#ifndef GRAPHDRAWING_H
#define GRAPHDRAWING_H

#include <QWidget>
#include <QTextStream>
#include <QPainter>
#include <QPainterPath>
#include <QVector>
#include <QPoint>
#include <QPen>
#include <cmath>

class GraphDrawing : public QWidget{
    Q_OBJECT
public:
    explicit GraphDrawing(QWidget *parent = nullptr);
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

#endif // GRAPHDRAWING_H
