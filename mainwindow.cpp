#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "imagesmanagerwindow.h"
#include "workingwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_shared_model = new ImagesListModel{};
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_shared_model;
}


void MainWindow::on_openWorkingWin_clicked()
{
    auto window = new WorkingWindow(m_shared_model, this);
    window->setWindowFlag(Qt::Window);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
}

void MainWindow::on_openSetupWindow_clicked()
{
    auto window = new ImagesManagerWindow(m_shared_model, this);
    window->setWindowFlag(Qt::Window);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->show();
}
