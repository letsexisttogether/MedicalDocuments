#include "PatientAppointment.hpp"
#include "ui_PatientAppointment.h"

#include "MainClient/General/OpenAppointmentFilter/OpenAppointmentFilter.hpp"

PatientAppointment::PatientAppointment(AppointmentsRecord&& appointment,
    QWidget *parent)
    : QWidget{ parent }, ui{ new Ui::PatientAppointment },
    m_AppointmentInfo{ std::move(appointment) }
{
    ui->setupUi(this);
    installEventFilter(new OpenAppointmentFilter{ parent , m_AppointmentInfo });

    SetInformation();
}

PatientAppointment::PatientAppointment(const DefaultRecord::ID ID,
    const bool isByDoctor, QWidget *parent)
    : QWidget{ parent }, ui{ new Ui::PatientAppointment },
    m_AppointmentInfo{ AppointmentsRecord{ ID, isByDoctor } }
{
    ui->setupUi(this);
    installEventFilter(new OpenAppointmentFilter{ this, m_AppointmentInfo });

    SetInformation();
}

PatientAppointment::~PatientAppointment()
{
    delete ui;
}

void PatientAppointment::SetInformation() noexcept
{
    const PeopleRecord& person = m_AppointmentInfo.GetPerson();

    const AppointmentsRecord& appointment
        = m_AppointmentInfo.GetAppointment();
    const SpecializationsRecord& specialization
        = m_AppointmentInfo.GetSpecialization();

    const QString fullName
    {
        person.GetLastName() + ' '
            + person.GetFirstName().at(0) + ". "
            + person.GetPatrynomic().at(0) + '.'
    };
    ui->doctorBIO->setText(fullName);

    ui->specialization->setText(specialization.GetTitle());
    ui->specialization->setToolTip(specialization.GetDescription());

    ui->date->setText(appointment.GetDate().toString("dd.MM.yyyy"));

    ui->diagnosis->setText(appointment.GetDiagnosis());
}