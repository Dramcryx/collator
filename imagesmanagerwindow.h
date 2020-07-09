#ifndef IMAGESMANAGERWINDOW_H
#define IMAGESMANAGERWINDOW_H

#include <QWidget>
#include <QAbstractItemModel>

#include "imageslistmodel.h"

namespace Ui {
class ImagesManagerWindow;
}

class ImagesManagerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ImagesManagerWindow(ImagesListModel * model, QWidget *parent = nullptr);
    ~ImagesManagerWindow();

private slots:
    void on_addImage_clicked();

    void on_removeImage_clicked();

private:
    Ui::ImagesManagerWindow *ui;
};

#endif // IMAGESMANAGERWINDOW_H
