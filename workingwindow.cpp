#include "workingwindow.h"
#include "ui_workingwindow.h"

#include <QGraphicsPathItem>

WorkingWindow::WorkingWindow(ImagesListModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkingWindow)
{
    ui->setupUi(this);
    ui->imagesView->setModel(model);
    ui->graphicsView->setScene(new QGraphicsScene(ui->graphicsView));

    connect(model, &ImagesListModel::imageAdded, this, &WorkingWindow::imagesAdded);
}

WorkingWindow::~WorkingWindow()
{
    delete ui;
}

void WorkingWindow::imagesAdded(QGraphicsPixmapItem * img)
{
    ui->graphicsView->scene()->addItem(img);
}
