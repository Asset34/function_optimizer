#ifndef FUNCTIONDRAWER_HPP
#define FUNCTIONDRAWER_HPP

#include <QWidget>
#include <Q3DSurface>

#include <QVector>

#include <vector>

#include <parser/function.hpp>
#include <parser/Utility/vector.hpp>

using namespace QtDataVisualization;

class QVBoxLayout;

class FunctionDrawer : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionDrawer(QWidget *parent = nullptr);

public slots:
    void setFunction(const Function &f, double min, double max);
    void setMarks(const QVector<QVector3D> &marks);
    void setMarks(const Function &f, const std::vector<Vector> &marks);
    void clearMarks();

private:
    static const int POINT_COUNT = 100;
    static const QColor MARK_COLOR;

    QVBoxLayout *m_layout;

    Q3DSurface *m_graph;
    QSurface3DSeries *m_dataSeries;

    QVector<QVector3D> m_marks;

};

#endif // FUNCTIONDRAWER_HPP
