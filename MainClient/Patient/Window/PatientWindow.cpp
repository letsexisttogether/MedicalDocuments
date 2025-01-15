#include "PatientWindow.hpp"
#include "ui_PatientWindow.h"

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
    QWidget *scrollWidget = ui->scrollArea->widget();
    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout *>(scrollWidget->layout());
    if (!scrollLayout)
    {
        // Якщо layout не налаштований у Designer, створюємо його
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    scrollLayout->addWidget(new PatientAppointment{ m_Patient.GetID(), false });

    /*
    // Додаємо записи динамічно
    for (int i = 1; i <= 10; ++i)
    {
        QWidget *recordWidget = new QWidget(this);
        QVBoxLayout *recordLayout = new QVBoxLayout(recordWidget);

        // Додаємо текстові записи
        recordLayout->addWidget(new QLabel(QString("Номер пацієнта %1: Ім'я %2").arg(i).arg(QString("Влад")), this));
        recordLayout->addWidget(new QLabel(QString("Запис %1: Текст 2").arg(i), this));
        recordLayout->addWidget(new QLabel(QString("Запис %1: Текст 3").arg(i), this));

        // Налаштовуємо стиль запису
        recordWidget->setStyleSheet("border: 1px solid gray; margin: 5px; padding: 10px;");

        // Додаємо до прокрутки
        scrollLayout->addWidget(recordWidget);
    }
    */
}