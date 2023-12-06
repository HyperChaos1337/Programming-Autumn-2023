#include "graph.h"

Graph::Graph(QWidget *parent)
    : QWidget{parent}{
}

void Graph::setAdjacencyMatrix(QVector<QVector<qint16>> &adjMatrix){
    this->adjacencyMatrix = adjMatrix;
}

void Graph::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);

    int nodeRadius = 20;
    int centerX = width() / 2;
    int centerY = height() / 2;
    int radiusX = qMin(centerX, centerY) - 50;
    int radiusY = radiusX;
    QPen pen;
    pen.setWidth(2);
    painter.setPen(pen);

    for(int i = 0; i < adjacencyMatrix.size(); i++){
        double angle = 2 * M_PI * i / adjacencyMatrix.size();
        int x = centerX + radiusX * cos(angle);
        int y = centerY + radiusY * sin(angle);
        nodePositions.append(QPointF(x, y));
    }
    for (int i = 0; i < adjacencyMatrix.size(); ++i){
        if (adjacencyMatrix[i][i] == 1){
            QPolygonF arrow;
            arrow << QPointF(nodePositions[i].x()+30, nodePositions[i].y()+10);
            arrow << QPointF(nodePositions[i].x()+20, nodePositions[i].y());
            arrow << QPointF(nodePositions[i].x()+30, nodePositions[i].y()-10);
            painter.drawEllipse(nodePositions[i].x(), nodePositions[i].y()-20 - nodeRadius, nodeRadius * 2, nodeRadius * 2);
            painter.drawPolyline(arrow);
        }
    }

    for(int i = 0; i < adjacencyMatrix.size(); ++i){
        painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        QPoint point(nodePositions[i].x()+10, nodePositions[i].y()+30);
        painter.drawEllipse(nodePositions[i], nodeRadius, nodeRadius);
        painter.drawText(point, QString::number(i + 1));
    }

    // Отрисовка дуг
    for (int row = 0; row < adjacencyMatrix.size(); ++row){
        for (int col = 0; col < adjacencyMatrix[row].size(); ++col){
            if (adjacencyMatrix[row][col] == 1){
                QPolygonF arrow, line;
                QPainterPath path;
                //QPainterPath path;
                //arrow << QPointF(nodePositions[col].x()-20, nodePositions[col].y()+5);
                //arrow << QPointF(nodePositions[col].x(), nodePositions[col].y());
                //arrow << QPointF(nodePositions[col].x()-20, nodePositions[col].y()-5);
                line << nodePositions[row] << nodePositions[col];
                QPointF start(nodePositions[row].x(), nodePositions[row].y());
                QPointF end(nodePositions[col].x(), nodePositions[col].y());
                QLineF edge(start, end);
                double angle = std::acos(edge.dx() / edge.length());
                if (edge.dy() >= 0)
                    angle = (M_PI * 2) - angle;
                QPointF arrowP1 = edge.p2() - QPointF(sin(angle + M_PI / 3) * 20,
                                                      cos(angle + M_PI / 3) * 20);
                QPointF arrowP2 = edge.p2() - QPointF(sin(angle + M_PI - M_PI / 3) * 20,
                                                      cos(angle + M_PI - M_PI / 3) * 20);
                arrow << edge.p2() << arrowP1 << arrowP2;
                path.moveTo(start);
                path.lineTo(end);
                path.addPolygon(arrow);
                // Отрисовка дуги
                painter.drawPath(path);
                painter.drawPolygon(line);

            }
        }
    }

}

/*
    QApplication a(argc, argv);

    QGraphicsScene scene;
    QGraphicsView view(&scene);
    view.show();

    QPainterPath path;
    QPointF startPoint(100, 100); // Начальная точка
    QPointF endPoint(300, 200);   // Конечная точка

    QPolygonF arrowHead;
    arrowHead << QPointF(-10, 5) << QPointF(0, 0) << QPointF(-10, -5); // Определяем форму направленной стрелки

    QLineF line(startPoint, endPoint);  // Создаем отрезок

    double angle = std::acos(line.dx() / line.length());
    if (line.dy() >= 0)
        angle = (M_PI * 2) - angle;

    QPointF arrowP1 = line.p2() - QPointF(sin(angle + M_PI / 3) * 10,
                                          cos(angle + M_PI / 3) * 10);
    QPointF arrowP2 = line.p2() - QPointF(sin(angle + M_PI - M_PI / 3) * 10,
                                          cos(angle + M_PI - M_PI / 3) * 10);

    arrowHead << line.p2() << arrowP1 << arrowP2;

    path.moveTo(startPoint);
    path.lineTo(endPoint);
    path.addPolygon(arrowHead);

    scene.addPath(path);

    return a.exec();
*/
