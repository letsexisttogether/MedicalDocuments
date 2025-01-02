#include "appointmentwindow.h"
#include "ui_appointmentwindow.h"

AppointmentWindow::AppointmentWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppointmentWindow)
{
    ui->setupUi(this);
}

AppointmentWindow::~AppointmentWindow()
{
    delete ui;
}
