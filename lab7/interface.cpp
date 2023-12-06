#include "interface.h"
#include "ui_interface.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TInterface){
    ui->setupUi(this);
    setWindowTitle("Graph Implementation");
    resize(1024, 768);
    ui->fileContent->resize(200, 200);
    connect(ui->openButton, &QPushButton::clicked, this, &TInterface::selectFile);
}

TInterface::~TInterface(){
    delete ui;
}

void TInterface::selectFile(){
    ui->fileContent->clear();
    if(ui->graphLayout->count() > 0){
        QLayoutItem* item;
        while((item = ui->graphLayout->takeAt(0)) != 0){
            delete item->widget();
            delete item;
        }
    }
    QString fileName = QFileDialog::getOpenFileName(this, "Choose File", "", "Text files (*.txt)");
    if(fileName.isEmpty()){
        QMessageBox::critical(this, "Error", "File is not selected");
        return;
    }
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "Error", "Cannot open file. Try again");
        return;
    }
    QTextStream inLine(&file);
    while (!inLine.atEnd()) {
        QString line = inLine.readLine();
        if(!isValid(line)){
            QMessageBox::critical(this, "Error", "File contains incorrect data!");
            return;
        }
        QStringList vals = line.split(" ");
        QVector<qint16> row;
        for (const QString &val : vals) {
            row.append(val.toInt());
        }
        matrix.append(row);
    }
    QMessageBox::information(this, "Success", "File has been opened!");
    permission = true;
    file.close();
    drawGraph();
}

bool TInterface::isValid(const QString &fileContent){
    bool validFormat = true;
    if(fileContent.isEmpty()) validFormat = false;
    QStringList numbers = fileContent.split(" ");
    foreach (const QString& number, numbers) {
        if(number.toInt() > 1 || number.toInt() < 0){
            validFormat = false;
            break;
        }
    }
    return validFormat;
}

void TInterface::drawGraph(){
    if(permission){
        Graph* graph = new Graph(this);
        graph->setAdjacencyMatrix(matrix);
        ui->graphLayout->addWidget(graph);
        graph->show();
        permission = false;
        if(!matrix.empty()) matrix.clear();
    }
}

