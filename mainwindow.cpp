#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "imageslistmodel.h"
#include "imagesmanagerwindow.h"
#include "workingwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_shared_model(new ImagesListModel{}),
    m_manager(new ImagesManagerWindow(m_shared_model, this)),
    m_canvas(new WorkingWindow(m_shared_model, this))
{
    ui->setupUi(this);

    m_manager->setWindowFlag(Qt::Window);
    m_manager->setAttribute(Qt::WA_DeleteOnClose);

    m_canvas->setWindowFlag(Qt::Window);
    m_canvas->setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_shared_model;
}


void MainWindow::on_openWorkingWin_clicked()
{
    m_canvas->setVisible(!m_canvas->isVisible());
}

void MainWindow::on_openSetupWindow_clicked()
{
    m_manager->setVisible(!m_manager->isVisible());
}
