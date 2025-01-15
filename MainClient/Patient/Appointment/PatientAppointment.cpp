#include "PatientAppointment.hpp"
#include "ui_PatientAppointment.h"

#include "SQL/Tables/Doctors/DoctorsRecord.hpp"
#include "SQL/Tables/People/PeopleRecord.hpp"
#include "SQL/Tables/Specializations/SpecializationsRecord.hpp"

PatientAppointment::PatientAppointment(const DefaultRecord::ID ID,
    const bool isByDoctor, QWidget *parent)
    : QWidget(parent), ui{ new Ui::PatientAppointment },
    m_Appointment{ ID , isByDoctor }
{
    ui->setupUi(this);

    SetInformation();
}

PatientAppointment::~PatientAppointment()
{
    delete ui;
}

void PatientAppointment::SetInformation() noexcept
{
    DoctorsRecord doctor{ m_Appointment.GetDoctorID() };

    PeopleRecord person{ doctor.GetPersonID() };
    SpecializationsRecord specialization{ doctor.GetSpecializationID() };

    const QString fullName
    {
        person.GetLastName() + ' '
            + person.GetFirstName().at(0) + ". "
            + person.GetPatrynomic().at(0) + '.'
    };
    ui->doctorBIO->setText(fullName);

    ui->specialization->setText(specialization.GetTitle());
    ui->specialization->setToolTip(specialization.GetDescription());

    ui->date->setText(m_Appointment.GetDate().toString("dd.MM.yyyy"));

    ui->diagnosis->setText(m_Appointment.GetDiagnosis());
}