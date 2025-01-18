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

    PeopleRecord person
    {
        ui->firstName->text(),
        ui->lastName->text(),
        ui->patronymic->text(),
        ui->maleRadioButton->isChecked(),
        ui->birthdayCalendar->selectedDate()
    };
    person.InsertData();

    if (person.IsEmpty())
    {
        return;
    }

    PasswordEncryptor encryptor{};

    const QString enteredPassword{ ui->password->GetEditValue() };
    const QString salt{ encryptor.GenerateSalt() };

    const QString encryptedPassword
    {
        encryptor.Encrypt(enteredPassword, salt)
    };

    PasswordsRecord password
    {
        encryptedPassword,
        salt
    };
    password.InsertData();

    if (password.IsEmpty())
    {
        return;
    }

    PatientsRecord patient
    {
        person.GetID(),
        ui->email->GetEditValue(),
        password.GetID(),
        ui->phoneNumber->text(),
        ui->address->text()
    };
    patient.InsertData();

    if (patient.IsEmpty())
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