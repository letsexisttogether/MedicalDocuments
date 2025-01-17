#include "DoctorWindow.hpp"
#include "ui_DoctorWindow.h"

#include <QVBoxLayout>
#include <QTextEdit>

#include "SQL/Tables/People/PeopleRecord.hpp"
#include "SQL/Tables/Specializations/SpecializationsRecord.hpp"
#include "SQL/Loaders/Patients/PatientsMultyLoader.hpp"
#include "SQL/Loaders/Appointments/AppointmentsMultyLoader.hpp"
#include "MainClient/Doctor/AppointmentCreator/AppointmentCreator.hpp"
#include "MainClient/Patient/Appointment/PatientAppointment.hpp"

DoctorWindow::DoctorWindow(const DefaultRecord::ID ID, QWidget *parent)
    : QMainWindow(parent), ui{ new Ui::DoctorWindow }, m_Doctor{ ID }
{
    ui->setupUi(this);

    UpdateDoctorInformation();

    connect(ui->acceptPatientSelection, &QPushButton::clicked, this,
        &DoctorWindow::OnPatientChange);
    connect(ui->addAppointment, &QPushButton::clicked, this,
        &DoctorWindow::OnAddAppointment);
}

DoctorWindow::~DoctorWindow()
{
    delete ui;
}

void DoctorWindow::OnPatientChange()
{
    UpdatePatientInformation();
    UpdateAppointments();
}

void DoctorWindow::OnAddAppointment()
{
    QMainWindow* const appointmentCreator
        = new AppointmentCreator{ m_Patient, m_Doctor, this };

    appointmentCreator->show();
}

void DoctorWindow::UpdateDoctorInformation() noexcept
{
    PeopleRecord person{ m_Doctor.GetPersonID() };

    const QString fullName
    {
        person.GetLastName() + ' ' + person.GetFirstName() +
            ' ' + person.GetPatrynomic()
    };
    ui->bio->setText(fullName);

    const QString gender
    {
        ((person.GetGender()) ? ("Чоловік") : ("Жінка"))
    };
    ui->gender->setText(gender);

    const SpecializationsRecord specialization
    {
        m_Doctor.GetSpecializationID()
    };
    ui->specialization->setText(specialization.GetTitle());
    ui->specialization->setToolTip(specialization.GetDescription());

    const quint16 workExperience = m_Doctor.GetWorkExperience();
    const QString workExperienceStr
    {
        QString("%1 років %2 місяців")
            .arg(workExperience / 12)
            .arg(workExperience % 12)
    };
    ui->workExperience->setText(workExperienceStr);
}

void DoctorWindow::UpdatePatientInformation() noexcept
{
    QLabel* const recordOfPatient = ui->recordOfPatient;

    m_Patient = PatientsRecord{ ui->email->text() };

    const PeopleRecord person{ m_Patient.GetPersonID() };

    const QString fullName
    {
        person.GetLastName() + ' ' + person.GetFirstName() +
           ' ' + person.GetPatrynomic()
    };

    recordOfPatient->setText(fullName);
}

void DoctorWindow::UpdateAppointments() noexcept
{
    QVBoxLayout* const verticalLayout = ui->verticalLayout;
    verticalLayout->setAlignment(Qt::AlignTop);

    QWidget* const scrollAreaWidget = ui->scrollArea->widget();

    ClearAppointments();

    AppointmentsMultyLoader loader{ m_Patient.GetID(), false };

    for (qsizetype i = 0; i < loader.GetCount(); ++i)
    {
        verticalLayout->addWidget(new PatientAppointment
        {
            loader.GetCurrent<AppointmentsRecord>(), scrollAreaWidget
        });
    }
}

void DoctorWindow::ClearAppointments() noexcept
{
    QVBoxLayout* const verticalLayout = ui->verticalLayout;

    QLayoutItem* item{};
    while ((item = verticalLayout->takeAt(0)) != nullptr)
    {
        if (item->widget())
        {
            delete item->widget();
        }
        delete item;
    }
}