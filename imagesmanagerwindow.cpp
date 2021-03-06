#include "imagesmanagerwindow.h"
#include "ui_imagesmanagerwindow.h"

#include <QFileDialog>
#include <QCloseEvent>

ImagesManagerWindow::ImagesManagerWindow(ImagesListModel *model, QWidget *parent):
    QWidget(parent),
    ui(new Ui::ImagesManagerWindow)
{
    ui->setupUi(this);
    ui->imagesView->setModel(model);
    connect(model, &ImagesListModel::movedAbove, ui->imagesView->selectionModel(),
            &QItemSelectionModel::setCurrentIndex);
}

ImagesManagerWindow::~ImagesManagerWindow()
{
    delete ui;
}

void ImagesManagerWindow::on_addImage_clicked()
{
    auto model = qobject_cast<ImagesListModel*>(ui->imagesView->model());
    for (const auto & i: QFileDialog::getOpenFileNames(this,
                                                       "Выберите изображение",
                                                       QString{},
                                                       "(*.png *.bmp *.jpg)"))
    {
        model->addImage(i);
    }
}

void ImagesManagerWindow::on_removeImage_clicked()
{
    auto rows = ui->imagesView->selectionModel()->selectedRows();
    auto model = qobject_cast<ImagesListModel*>(ui->imagesView->model());
    for (auto &i: rows)
    {
        model->removeImage(i.row());
    }
}

void ImagesManagerWindow::closeEvent(QCloseEvent *event)
{
    event->ignore();
    this->hide();
}
