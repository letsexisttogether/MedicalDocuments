#include "PatientAppointment.hpp"
#include "ui_PatientAppointment.h"

PatientAppointment::PatientAppointment(QWidget *parent)
    : QWidget(parent), ui{ new Ui::PatientAppointment }
{
    ui->setupUi(this);
}

PatientAppointment::~PatientAppointment()
{
    delete ui;
}
