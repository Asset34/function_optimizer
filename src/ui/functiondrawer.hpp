#ifndef FUNCTIONDRAWER_HPP
#define FUNCTIONDRAWER_HPP

#include <QWidget>
#include <Q3DSurface>

#include <QVector>

#include <Parser/Functions/function.hpp>

using namespace QtDataVisualization;

class QVBoxLayout;

class FunctionDrawer : public QWidget
{
    Q_OBJECT
public:
    explicit FunctionDrawer(QWidget *parent = nullptr);

public slots:
    void setFunction(
            const Function &func,
            double xmin,
            double xmax,
            double ymin,
            double ymax
            );
    void setMarks(const QVector<QVector3D> &marks);
    void clearMarks();

private:
    constexpr static const double STEP = 1.0;
    static const QColor MARK_COLOR;

    QVBoxLayout *m_layout;

    Q3DSurface *m_graph;
    QSurface3DSeries *m_dataSeries;

    QVector<QVector3D> m_marks;

};

#endif // FUNCTIONDRAWER_HPP
