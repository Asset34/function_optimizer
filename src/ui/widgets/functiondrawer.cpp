#include "functiondrawer.hpp"

#include <QVBoxLayout>
#include <QtDataVisualization>

const QColor FunctionDrawer::MARK_COLOR = Qt::black;

FunctionDrawer::FunctionDrawer(QWidget *parent)
    : QWidget(parent)
{
    // Create data series
    m_dataSeries = new QSurface3DSeries;
    m_dataSeries->setDrawMode(QSurface3DSeries::DrawSurface);

    // Create graph
    m_graph = new Q3DSurface();
    m_graph->scene()->activeCamera()->setCameraPreset(Q3DCamera::CameraPresetFront);
    m_graph->activeTheme()->setType(Q3DTheme::Theme::ThemeStoneMoss);
    m_graph->addSeries(m_dataSeries);

    // Create container
    QWidget *container = QWidget::createWindowContainer(m_graph);

    // Create layout
    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(container);

    // Create widget
    setLayout(m_layout);
}

void FunctionDrawer::setFunction(const Function &f, double min, double max)
{
    double step = (max - min) / (POINT_COUNT - 1);

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
}

void FunctionDrawer::setMarks(const QVector<QVector3D> &marks)
{
    m_graph->removeCustomItems();

    QImage color = QImage(2, 2, QImage::Format_RGB32);
    color.fill(MARK_COLOR);

    QCustom3DItem *item;
    for (QVector3D mark : marks) {
        item = new QCustom3DItem(
                   ":/items/sphere.obj",
                   mark,
                   QVector3D(0.01f, 0.01f, 0.01f),
                   QQuaternion(),
                   color
                   );

        m_graph->addCustomItem(item);
        }
}

void FunctionDrawer::setMarks(const std::vector<Vector> &marks, const Function &f)
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

    setMarks(transformedMarks);
}

void FunctionDrawer::clearMarks()
{
    m_graph->removeCustomItems();
}
