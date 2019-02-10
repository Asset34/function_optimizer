#include "functiondrawer.hpp"

#include <QVBoxLayout>
#include <QtDataVisualization>

#include <QDebug>

const QColor FunctionDrawer::MARK_COLOR = Qt::black;

FunctionDrawer::FunctionDrawer(QWidget *parent)
    : QWidget(parent),
      m_markTexture(2, 2, QImage::Format_RGB32),
      m_selectedIndex(-1)
{
    m_markTexture.fill(MARK_COLOR);

    // Create data series
    m_dataSeries = new QSurface3DSeries;
    m_dataSeries->setDrawMode(QSurface3DSeries::DrawSurface);

    // Create graph
    m_graph = new Q3DSurface();
    m_graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront);
    m_graph->activeTheme()->setType(Q3DTheme::Theme::ThemeStoneMoss);
    m_graph->addSeries(m_dataSeries);

    // Create container
    m_container = QWidget::createWindowContainer(m_graph);

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_container);

    // Create widget
    setLayout(m_layout);
}

void FunctionDrawer::setFunction(const Function &f, double min, double max)
{
    double step = (max - min) / (MARK_COUNT - 1);

    QSurfaceDataArray *data = new QSurfaceDataArray;
    QSurfaceDataRow *dataRow;
    for (double y = min; y <= max; y += step) {
        dataRow = new QSurfaceDataRow;
        for (double x = min; x <= max; x += step) {
            *dataRow << QVector3D(x, f(std::vector<double>{x, y}), y);
        }

        *data << dataRow;
    }

    m_dataSeries->dataProxy()->resetArray(data);

    // Adjust axis
    m_graph->axisX()->setRange(min, max);
    m_graph->axisZ()->setRange(min, max);
    m_graph->axisY()->setAutoAdjustRange(true);
    m_graph->axisY()->setRange(
                m_graph->axisY()->min() - GRAPH_OFFEST,
                m_graph->axisY()->max() + GRAPH_OFFEST
                );
}

void FunctionDrawer::clearFunction()
{
    m_dataSeries->dataProxy()->removeRows(
                0,
                m_dataSeries->dataProxy()->rowCount()
                );
}

void FunctionDrawer::addMarkSet(const QVector<QVector3D> &marks)
{
    MarkSet markSet(marks.size());
    for (int i = 0; i < marks.size(); i++) {
        markSet[i] = new QCustom3DItem(
                   ":/items/cube.obj",
                   marks[i],
                   QVector3D(MARK_SCALE, MARK_SCALE, MARK_SCALE),
                   QQuaternion(),
                   m_markTexture
                   );
        markSet[i]->setVisible(false);

        m_graph->addCustomItem(markSet[i]);
    }

    m_markSets.push_back(markSet);
}

void FunctionDrawer::addMarkSet(const Function &f, const std::vector<Vector> &marks)
{
    QVector<QVector3D> transformedMarks(marks.size());
    double x, y;
    for (int i = 0; i < marks.size(); i++) {
        x = marks[i][0];
        y = marks[i][1];

        transformedMarks[i].setX(x);
        transformedMarks[i].setY(f(std::vector<double>{x, y}));
        transformedMarks[i].setZ(y);
    }

    addMarkSet(transformedMarks);
}

void FunctionDrawer::clearMarks()
{
    m_graph->removeCustomItems();
    m_markSets.clear();
    m_selectedIndex = -1;
}

void FunctionDrawer::selectMarkSet(int index)
{
    if (m_selectedIndex >= 0) {
        hideMarkSet(m_selectedIndex);
    }

    m_selectedIndex = index;
    showMarkSet(index);
}

void FunctionDrawer::clear()
{
    clearMarks();
    clearFunction();
}

void FunctionDrawer::showMarkSet(int index)
{
    for (QCustom3DItem *item : m_markSets[index]) {
        item->setVisible(true);
    }
}

void FunctionDrawer::hideMarkSet(int index)
{
    for (QCustom3DItem *item : m_markSets[index]) {
        item->setVisible(false);
    }
}
