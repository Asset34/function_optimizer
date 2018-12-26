#include "functiondrawer.hpp"

#include <QVBoxLayout>
#include <QtDataVisualization>

#include <QDebug>

const QColor FunctionDrawer::MARK_COLOR = Qt::red;

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

void FunctionDrawer::setFunction(
        const Function &func,
        double xmin,
        double xmax,
        double ymin,
        double ymax
        )
{
    m_graph->axisX()->setRange(ymin, ymax);
    m_graph->axisZ()->setRange(xmin, xmax);

    QSurfaceDataArray *data = new QSurfaceDataArray;
    double x = xmin;
    double y;
    while (x < xmax) {
        QSurfaceDataRow *dataRow = new QSurfaceDataRow;

        y = ymin;
        while (y < ymax) {
            *dataRow << QVector3D(y, func({x, y}), x);
            y += STEP;
        }

        *data << dataRow;

        x += STEP;
    }

    m_dataSeries->dataProxy()->resetArray(data);
}

void FunctionDrawer::setMarks(const QVector<QVector3D> &marks)
{
    m_graph->removeCustomItems();

    QImage color = QImage(2, 2, QImage::Format_RGB32);
    color.fill(MARK_COLOR);

//    QCustom3DItem *item;
    for (QVector3D mark : marks) {
        QCustom3DItem *item = new QCustom3DItem(
                    ":/items/sphere.obj",
                    mark,
                    QVector3D(0.01f, 0.01f, 0.01f),
                    QQuaternion(),
                    color
                    );

        int check = m_graph->addCustomItem(item);
        if (check < 0) {
             qDebug() << "FAIL";
        }
    }
}

void FunctionDrawer::clearMarks()
{
    m_graph->removeCustomItems();
}
