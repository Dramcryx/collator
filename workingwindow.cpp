#include "workingwindow.h"
#include "ui_workingwindow.h"

#include <QFileDialog>
#include <QCloseEvent>

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

void WorkingWindow::on_saveToFile_clicked()
{
    QString selectedFilter{};
    auto filename = QFileDialog::getSaveFileName(this, "Сохранить в файл", QString{}, "PNG;;JPG;;BMP", &selectedFilter)
            .append('.')
            .append(selectedFilter.toLower());
    auto rect = ui->graphicsView->scene()->itemsBoundingRect().toRect();
    // don't render empty pictures
    if (rect.width() * rect.height() > 0)
    {
        QPixmap image{rect.size()};
        QPainter painter{&image};
        ui->graphicsView->scene()->render(&painter, image.rect(), rect);
        image.save(filename, selectedFilter.toUtf8());
    }
}

void WorkingWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    this->hide();
}
