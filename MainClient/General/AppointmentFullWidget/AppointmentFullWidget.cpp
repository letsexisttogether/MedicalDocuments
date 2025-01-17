#include "AppointmentFullWidget.hpp"
#include "ui_AppointmentFullWidget.h"

#include "SQL/Loaders/AppPharmConn/AppPharmConnMultyLoader.hpp"
#include "SQL/Tables/AppPharmConn/AppPharmConnRecord.hpp"
#include "SQL/Tables/Pharmacies/PharmaciesRecord.hpp"
#include "MainClient/General/PharmacyViewWidget/PharmacyViewWidget.hpp"

AppointmentFullWidget::AppointmentFullWidget(const AppointmentInfo& info,
    QWidget *parent)
    : ui{ new Ui::AppointmentFullWidget{} }, m_AppointmentInfo{ info }
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);

    SetCompleteInformation();
}

AppointmentFullWidget::~AppointmentFullWidget()
{
    delete ui;
}

void AppointmentFullWidget::SetCompleteInformation() noexcept
{
    SetDoctorSpecialization();
    SetKnownInfomation();
    SetPharmacies();
    SetDiagnosis() ;
    SetRecommendations();
}

void AppointmentFullWidget::SetDoctorSpecialization() noexcept
{
    QLabel* const specialityLabel = ui->speciality;
    const SpecializationsRecord& specialization
        = m_AppointmentInfo.GetSpecialization();

    specialityLabel->setText(specialityLabel->text()
        .append(specialization.GetTitle().toLower()));
    specialityLabel->setToolTip(specialization.GetDescription());
}

void AppointmentFullWidget::SetKnownInfomation() noexcept
{
    const AppointmentsRecord& appointment
        = m_AppointmentInfo.GetAppointment();

    const PatientsRecord& patient = m_AppointmentInfo.GetPatient();
    const PeopleRecord& patientPerson = m_AppointmentInfo.GetPatientPerson();

    ui->medNumber->setText(ui->medNumber->text()
        .append(QString::number(patient.GetID())));

    const PeopleRecord& doctorPerson = m_AppointmentInfo.GetDoctorPerson();

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
        .append(appointment.GetDate().toString(dateFormat)));
    ui->birthdate->setText(ui->birthdate->text()
       .append(patientPerson.GetBirthdate().toString(dateFormat)));
}

void AppointmentFullWidget::SetPharmacies() noexcept
{
    QVBoxLayout* const verticalLayout = ui->pharmaciesLayout;
    verticalLayout->setAlignment(Qt::AlignTop);

    QWidget* const widget = ui->pharmaciesScrollArea->widget();

    AppPharmConnMultyLoader loader
    {
        m_AppointmentInfo.GetAppointment().GetID(), true
    };

    for (qsizetype i = 0; i < loader.GetCount(); ++i)
    {
        verticalLayout->addWidget(new PharmacyViewWidget
        {
            PharmacyInfo{ loader.GetCurrent<AppPharmConnRecord>() },
            widget
        });
    }
}

void AppointmentFullWidget::SetDiagnosis() noexcept
{
    ui->diagnosis->setText(m_AppointmentInfo.GetAppointment()
        .GetDiagnosis());
}

void AppointmentFullWidget::SetRecommendations() noexcept
{
    ui->recommendations->setText(m_AppointmentInfo.GetAppointment()
        .GetRecommendations());
}