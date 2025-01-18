#include "SignUp.hpp"
#include "ui_SignUp.h"

#include <QCalendar>

#include "Authorization/FieldCheck/DefaultCheckers/DefaultPasswordChecker.hpp"
#include "Authorization/FieldCheck/DefaultCheckers/DefaultEmailChecker.hpp"
#include "SQL/Tables/People/PeopleRecord.hpp"
#include "SQL/Tables/Patients/PatientsRecord.hpp"
#include "SQL/Tables/Passwords/PasswordsRecord.hpp"

SignUp::SignUp(QWidget *parent)
    : QWidget(parent), ui(new Ui::SignUp)
{
    ui->setupUi(this);

    connect(ui->registerButton, &QPushButton::clicked, this,
        &SignUp::HandleRegistrationClick);
    connect(ui->returnButton, &QPushButton::clicked, this,
        &SignUp::HandleReturnClick);

    connect(ui->passwordVisibility, &QCheckBox::clicked, [=]()
    {
        ui->password->SetEchoMode((ui->passwordVisibility->isChecked()) ?
            (QLineEdit::Normal) : (QLineEdit::Password));
    });

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
    PeopleRecord person
    {
        ui->firstName->text(),
        ui->lastName->text(),
        ui->patronymic->text(),
        ui->maleRadioButton->isChecked(),
        ui->birthdayCalendar->selectedDate()
    };

    person.InsertData();

    return person.GetID();
}

SQLManager::ID SignUp::AddPassword() noexcept
{
    const QString enteredPassword{ ui->password->GetEditValue() };
    const QString salt{ m_Encryptor.GenerateSalt() };

    const QString encryptedPassword
    {
        m_Encryptor.Encrypt(enteredPassword, salt)
    };

    PasswordsRecord password
    {
        encryptedPassword,
        salt
    };

    password.InsertData();

    return password.GetID();
}

SQLManager::ID SignUp::AddPatient(const SQLManager::ID personID,
    const SQLManager::ID passwordID) noexcept
{
    PatientsRecord patient
    {
        personID,
        ui->email->GetEditValue(),
        passwordID,
        ui->phoneNumber->text(),
        ui->address->text()
    };

    patient.InsertData();

    return patient.GetID();
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