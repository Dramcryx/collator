#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ImagesListModel;
class ImagesManagerWindow;
class WorkingWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openWorkingWin_clicked();

    void on_openSetupWindow_clicked();

private:
    Ui::MainWindow *ui;

    ImagesListModel * m_shared_model;
    ImagesManagerWindow * m_manager;
    WorkingWindow * m_canvas;
};
#endif // MAINWINDOW_H
