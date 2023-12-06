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

class Graph : public QWidget{
    Q_OBJECT
public:
    explicit Graph(QWidget *parent = nullptr);
    //Задает матрицу смежности
    void setAdjacencyMatrix(QVector<QVector<qint16>>& adjMatrix);
protected:
    //Рисует граф
    void paintEvent(QPaintEvent *event) override;
private:
    //Матрицы смежности и позиций узлов
    QVector<QVector<qint16>> adjacencyMatrix;
    QVector<QPointF> nodePositions;
};

#endif // GRAPH_H
