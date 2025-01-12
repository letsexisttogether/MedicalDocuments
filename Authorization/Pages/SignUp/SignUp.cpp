#include "SignUp.hpp"
#include "ui_SignUp.h"

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

    ui->firstName->SetName("Ім'я");
    ui->secondName->SetName("Прізвище");
    ui->thirdName->SetName("По батькові");

    ui->email->SetName("Пошта (логін)");
    ui->email->SetChecker(new DefaultEmailChecker{});

    ui->password->SetName("Пароль");
    ui->password->SetChecker(new DefaultPasswordChecker{});
    ui->password->SetEchoMode(QLineEdit::Password);
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

    emit OperationCompleted();
}

void SignUp::HandleReturnClick()
{
    emit OperationCompleted();
}

SQLManager::ID SignUp::AddPerson() const noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString firstName{ ui->firstName->GetEditValue() };
    const QString secondName{ ui->secondName->GetEditValue() };
    const QString thirdName{ ui->thirdName->GetEditValue() };

    const qint16 isMale = (ui->maleRadioButton->isChecked());

    const QDate birthday{ ui->birthdayCalendar->selectedDate() };
    const QString birthdayString{ birthday.toString("yyyy-MM-dd") };

    const QString query
    {
        QString("INSERT INTO People (FirstName, SecondName, "
            "LastName, Gender, BirthdayDate) "
            "VALUES ('%1', '%2', '%3', %4, '%5');")
        .arg(firstName, secondName, thirdName)
        .arg(isMale)
        .arg(birthdayString)
    };

    return manager.InsertDataToTable(query);
}

SQLManager::ID SignUp::AddPassword() const noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString password{ ui->password->GetEditValue() };
    const QString salt{ "Hello " };

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
    const SQLManager::ID passwordID) const noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString email{ ui->email->GetEditValue() };

    const QString phoneNumber{ "+380667615115" };
    const QString address{ "м. Київ, п-р. Оболонський, д. 28б, кв. 15 "};

    const QString query
    {
        QString("INSERT INTO Patients (PersonID, Email, PasswordID, PhoneNumber, Address) "
                "VALUES (%1, '%2', %3, '%4', '%5');")
        .arg(personID)
        .arg(email)
        .arg(passwordID)
        .arg(phoneNumber)
        .arg(address)
    };

    return manager.InsertDataToTable(query);
}
