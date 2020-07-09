#ifndef WORKINGWINDOW_H
#define WORKINGWINDOW_H

#include <QWidget>

#include "imageslistmodel.h"

class QGraphicsPixmapItem;

namespace Ui {
class WorkingWindow;
}

class WorkingWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WorkingWindow(ImagesListModel * model, QWidget *parent = nullptr);
    ~WorkingWindow();

private slots:
    void imageAdded(QGraphicsPixmapItem *img);
    void imageRemoved(QGraphicsPixmapItem *img);

private:
    Ui::WorkingWindow *ui;
};

#endif // WORKINGWINDOW_H
