#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <QTextStream>
#include <QPainter>
#include <QPainterPath>
#include <QVector>
#include <QPoint>
#include <QPen>
#include <cmath>

class Graph : public QWidget
{
    Q_OBJECT
public:
    explicit Graph(QWidget *parent = nullptr);
    void setAdjacencyMatrix(QVector<QVector<qint16>>& adjMatrix);
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    QVector<QVector<qint16>> adjacencyMatrix;
    QVector<QPointF> nodePositions;
};

#endif // GRAPH_H
