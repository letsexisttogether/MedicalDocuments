#include "AppointmentFullWidget.hpp"
#include "ui_AppointmentFullWidget.h"

AppointmentFullWidget::AppointmentFullWidget(const AppointmentInfo& info,
    QWidget *parent)
    : ui{ new Ui::AppointmentFullWidget{} }, m_AppointmentInfo{ info }
{
    ui->setupUi(this);

    SetCompleteInformation();
}

AppointmentFullWidget::~AppointmentFullWidget()
{
    delete ui;
}

void AppointmentFullWidget::SetCompleteInformation() noexcept
{
    SetDoctorSpecialization();
    SetInfo();
    SetDiagnosis();
    SetRecommendations();
}

void AppointmentFullWidget::SetDoctorSpecialization() noexcept
{
    QLabel* const specialityLabel = ui->speciality;
    const SpecializationsRecord& specialization
        = m_AppointmentInfo.GetSpecialization();

    specialityLabel->setText(specialization.GetTitle());
    specialityLabel->setToolTip(specialization.GetDescription());
}

void AppointmentFullWidget::SetInfo() noexcept
{
    // Doctor
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