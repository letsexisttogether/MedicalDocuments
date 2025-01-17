#include "AppointmentCreator.hpp"
#include "ui_AppointmentCreator.h"

#include "SQL/Tables/Appointments/AppointmentsRecord.hpp"
#include "SQL/Tables/Specializations/SpecializationsRecord.hpp"
#include "SQL/Tables/People/PeopleRecord.hpp"

AppointmentCreator::AppointmentCreator(const PatientsRecord& patient,
        const DoctorsRecord& doctor, QWidget *parent)
    : QMainWindow{ parent }, ui{ new Ui::AppointmentCreator },
    m_Patient{ patient }, m_Doctor{ doctor }
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->saveButton, &QPushButton::clicked, this,
        &AppointmentCreator::OnSaveClicked);
    connect(ui->declineButton, &QPushButton::clicked, this,
        &AppointmentCreator::OnDeclineClicked);

    SetCompleteInformation();
}

AppointmentCreator::~AppointmentCreator()
{
    delete ui;
}

void AppointmentCreator::OnSaveClicked()
{
    AppointmentsRecord appointment
    {
        m_Doctor.GetID(), m_Patient.GetID(),QDate::currentDate(),
        ui->diagnosis->toPlainText(), ui->recommendations->toPlainText()
    };

    appointment.InsertData();

    close();
}

void AppointmentCreator::OnDeclineClicked()
{
    close();
}

void AppointmentCreator::SetCompleteInformation() noexcept
{
    SetDoctorSpecialization();
    SetKnownInformation();
}

void AppointmentCreator::SetDoctorSpecialization() noexcept
{
    QLabel* const specialityLabel = ui->speciality;
    const SpecializationsRecord& specialization
        = m_Doctor.GetSpecializationID();

    specialityLabel->setText(specialityLabel->text()
        .append(specialization.GetTitle().toLower()));
    specialityLabel->setToolTip(specialization.GetDescription());
}

void AppointmentCreator::SetKnownInformation() noexcept
{
    const PeopleRecord patientPerson{ m_Patient.GetPersonID() };

    ui->medNumber->setText(ui->medNumber->text()
        .append(QString::number(m_Patient.GetID())));

    const PeopleRecord doctorPerson{ m_Doctor.GetPersonID() };

    // FullNames
    const QString patientFullName
    {
        patientPerson.GetLastName() + ' ' + patientPerson.GetFirstName() +
            ' ' + patientPerson.GetPatrynomic()
    };
    ui->patient->setText(ui->patient->text().append(patientFullName));

    const QString doctorFullName
    {
        doctorPerson.GetLastName() + ' '
            + doctorPerson.GetFirstName().at(0) + ". "
            + doctorPerson.GetPatrynomic().at(0) + '.'
    };
    ui->doctor->setText(ui->doctor->text().append(doctorFullName));

    const QString gender
    {
        ((patientPerson.GetGender()) ? ("Чоловік") : ("Жінка"))
    };
    ui->gender->setText(ui->gender->text().append(gender));

    // Dates
    const QString dateFormat{ "dd.MM.yyyy" };

    ui->date->setText(ui->date->text()
        .append(QDate::currentDate().toString(dateFormat)));
    ui->birthdate->setText(ui->birthdate->text()
       .append(patientPerson.GetBirthdate().toString(dateFormat)));
}