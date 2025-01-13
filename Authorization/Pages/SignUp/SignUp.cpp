#include "SignUp.hpp"
#include "ui_SignUp.h"

#include <QCalendar>

#include "Authorization/FieldCheck/DefaultCheckers/DefaultPasswordChecker.hpp"
#include "Authorization/FieldCheck/DefaultCheckers/DefaultEmailChecker.hpp"

SignUp::SignUp(QWidget *parent)
    : QWidget(parent), ui(new Ui::SignUp)
{
    ui->setupUi(this);

    connect(ui->registerButton, &QPushButton::clicked, this,
        &SignUp::HandleRegistrationClick);
    connect(ui->returnButton, &QPushButton::clicked, this,
        &SignUp::HandleReturnClick);

    connect(ui->maleRadioButton, &QRadioButton::clicked, [=]()
    {
        if (ui->maleRadioButton->isChecked())
        {
            ui->femaleRadioButton->setChecked(false);
        }
    });
    connect(ui->femaleRadioButton, &QRadioButton::clicked, [=]()
    {
        if (ui->femaleRadioButton->isChecked())
        {
            ui->maleRadioButton->setChecked(false);
        }
    });

    ui->email->SetName("Пошта (логін)");
    ui->email->SetChecker(new DefaultEmailChecker{});

    ui->password->SetName("Пароль");
    ui->password->SetChecker(new DefaultPasswordChecker{});
    ui->password->SetEchoMode(QLineEdit::Password);

    ResetEditFields();
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::HandleRegistrationClick()
{
    if (!ui->email->CheckEdit())
    {
        return;
    }

    if (!ui->password->CheckEdit())
    {
        return;
    }

    SQLManager::ID personID = AddPerson();
    if (!personID)
    {
        return;
    }

    SQLManager::ID passwordID = AddPassword();
    if (!passwordID)
    {
        return;
    }

    SQLManager::ID patientID = AddPatient(personID, passwordID);
    if (!patientID)
    {
        return;
    }

    ResetEditFields();

    emit OperationCompleted();
}

void SignUp::HandleReturnClick()
{
    ResetEditFields();

    emit OperationCompleted();
}

SQLManager::ID SignUp::AddPerson() noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString firstName{ ui->firstName->text() };
    const QString lastName{ ui->lastName->text() };
    const QString patronymic{ ui->patronymic->text() };


    const qint16 isMale = (ui->maleRadioButton->isChecked());

    const QDate birthday{ ui->birthdayCalendar->selectedDate() };
    const QString birthdayString{ birthday.toString("yyyy-MM-dd") };

    const QString query
    {
        QString("INSERT INTO People (FirstName, LastName, "
            "Patronymic, Gender, Birthdate) "
            "VALUES (N'%1', N'%2', N'%3', %4, '%5');")
        .arg(firstName, lastName, patronymic)
        .arg(isMale)
        .arg(birthdayString)
    };

    return manager.InsertDataToTable(query);
}

SQLManager::ID SignUp::AddPassword() noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString enteredPassword{ ui->password->GetEditValue() };
    const QString salt{ m_Encryptor.GenerateSalt() };

    const QString password{ m_Encryptor.Encrypt(enteredPassword, salt) };

    const QString query
    {
        QString("INSERT INTO Passwords (Encrypted, Salt) "
            "VALUES ('%1', '%2');")
        .arg(password)
        .arg(salt)
    };

    return manager.InsertDataToTable(query);
}

SQLManager::ID SignUp::AddPatient(const SQLManager::ID personID,
    const SQLManager::ID passwordID) noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString email{ ui->email->GetEditValue() };

    const QString phoneNumber{ ui->phoneNumber->text() };

    const QString address{ ui->address->text() };

    const QString query
    {
        QString("INSERT INTO Patients (PersonID, Email, PasswordID, PhoneNumber, Address) "
                "VALUES (%1, '%2', %3, N'%4', N'%5');")
        .arg(personID)
        .arg(email)
        .arg(passwordID)
        .arg(phoneNumber)
        .arg(address)
    };

    return manager.InsertDataToTable(query);
}

void SignUp::ResetEditFields() noexcept
{
    ui->firstName->clear();
    ui->lastName->clear();
    ui->patronymic->clear();

    ui->phoneNumber->clear();
    ui->address->clear();

    ui->email->ClearEditValue();
    ui->password->ClearEditValue();

    ui->maleRadioButton->setChecked(true);
    ui->birthdayCalendar->showToday();
}