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

    void on_moveAbove_clicked();

    void on_moveBelow_clicked();

    void on_enlarge_clicked();

    void on_reduce_clicked();

    void on_saveToFile_clicked();

private:
    Ui::WorkingWindow *ui;

    void closeEvent(QCloseEvent * event) override;
};

#endif // WORKINGWINDOW_H
