#include "workingwindow.h"
#include "ui_workingwindow.h"

WorkingWindow::WorkingWindow(ImagesListModel *model, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkingWindow)
{
    ui->setupUi(this);
    ui->imagesView->setModel(model);
    ui->graphicsView->setScene(new QGraphicsScene(ui->graphicsView));

    connect(model, &ImagesListModel::imageAdded, this, &WorkingWindow::imageAdded);
    connect(model, &ImagesListModel::imageRemoved, this, &WorkingWindow::imageRemoved);
    connect(model, &ImagesListModel::movedAbove, ui->imagesView->selectionModel(),
            &QItemSelectionModel::setCurrentIndex);
}

WorkingWindow::~WorkingWindow()
{
    delete ui;
}

void WorkingWindow::imageAdded(QGraphicsPixmapItem * img)
{
    ui->graphicsView->scene()->addItem(img);
}

void WorkingWindow::imageRemoved(QGraphicsPixmapItem *img)
{
    ui->graphicsView->scene()->removeItem(img);
}

void WorkingWindow::on_moveAbove_clicked()
{
    auto model = qobject_cast<ImagesListModel*>(ui->imagesView->model());
    for (auto &i: ui->imagesView->selectionModel()->selectedRows())
    {
        model->pull(i.row());
    }
}

void WorkingWindow::on_moveBelow_clicked()
{
    auto model = qobject_cast<ImagesListModel*>(ui->imagesView->model());
    for (auto &i: ui->imagesView->selectionModel()->selectedRows())
    {
        model->push(i.row());
    }
}

void WorkingWindow::on_enlarge_clicked()
{
    for (auto &i: ui->imagesView->selectionModel()->selectedRows())
    {
        auto image = qvariant_cast<MovablePicture*>(i.data(Qt::UserRole));
        image->setScale(image->scale() + 0.1);
    }
}

void WorkingWindow::on_reduce_clicked()
{
    for (auto &i: ui->imagesView->selectionModel()->selectedRows())
    {
        auto image = qvariant_cast<MovablePicture*>(i.data(Qt::UserRole));
        image->setScale(image->scale() - 0.1);
    }
}
