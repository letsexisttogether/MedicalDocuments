#include "PatientWindow.hpp"
#include "ui_PatientWindow.h"

#include "SQL/Loaders/AppointmentsLoader.hpp"
#include "SQL/Tables/People/PeopleRecord.hpp"
#include "MainClient/Patient/Appointment/PatientAppointment.hpp"
#include "appointmentwindow.h"

PatientWindow::PatientWindow(const DefaultRecord::ID ID, QWidget *parent)
    : QMainWindow(parent), ui{ new Ui::PatientWindow }, m_Patient{ ID }
{
    ui->setupUi(this);

    SetBIO();
    SetAppointments();
}

PatientWindow::~PatientWindow()
{
    delete ui;
}

void PatientWindow::OpenAppointmentWindow()
{
    AppointmentWindow *appointmentWindow = new AppointmentWindow();

    // Відображаємо друге вікно
    appointmentWindow->show();

    // Закриваємо перше вікно
    this->close();
}

void PatientWindow::SetBIO() noexcept
{
    PeopleRecord person{ m_Patient.GetPersonID() };

    const QString medRecord
    {
        QString::number(person.GetID())
    };
    ui->medRecord->setText(medRecord);

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

    const QString birthdate
    {
        person.GetBirthdate().toString("dd.MM.yyyy")
    };
    ui->birthdate->setText(birthdate);
}

void PatientWindow::SetAppointments() noexcept
{
    QVBoxLayout* const verticalLayout = ui->verticalLayout;
    verticalLayout->setAlignment(Qt::AlignTop);

    QWidget* const scrollAreaWidget = ui->scrollArea->widget();

    AppointmentsLoader loader{ m_Patient.GetID(), false };

    for (qsizetype i = 0; i < loader.GetCount() + 20; ++i)
    {
        verticalLayout->addWidget(new PatientAppointment
        {
            loader.GetCurrent(), scrollAreaWidget
        });
    }

    /*
    verticalLayout->addItem(new QSpacerItem
    {
        50, 40
    });
    */
}
