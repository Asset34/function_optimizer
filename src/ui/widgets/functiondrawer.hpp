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
    void clearFunction();

    void addMarkSet(const QVector<QVector3D> &marks);
    void addMarkSet(const Function &f, const std::vector<Vector> &marks);
    void clearMarks();

    void selectMarkSet(int index);

    void clear();

private:
    using MarkSet = QVector<QCustom3DItem*>;

    void showMarkSet(int index);
    void hideMarkSet(int index);

    static const int GRAPH_OFFEST = 10;
    static const int MARK_COUNT = 100;
    constexpr static const double MARK_SCALE = 0.015;
    static const QColor MARK_COLOR;
    QImage m_markTexture;

    QVBoxLayout *m_layout;

    QWidget *m_container;

    Q3DSurface *m_graph;
    QSurface3DSeries *m_dataSeries;

    QList<MarkSet> m_markSets;
    int m_selectedIndex;

};

#endif // FUNCTIONDRAWER_HPP
