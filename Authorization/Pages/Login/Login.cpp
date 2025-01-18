#include "Login.hpp"
#include "ui_Login.h"

#include "SQL/Manager/SQLManager.hpp"
#include "Authorization/FieldCheck/DefaultCheckers/DefaultPasswordChecker.hpp"
#include "Authorization/FieldCheck/DefaultCheckers/DefaultEmailChecker.hpp"

#include "SQL/Tables/Patients/PatientsRecord.hpp"
#include "SQL/Tables/Doctors/DoctorsRecord.hpp"
#include "SQL/Tables/Passwords/PasswordsRecord.hpp"

Login::Login(QWidget *parent)
    : QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->acceptButton, &QPushButton::clicked, this,
        &Login::HandleLoginClick);
    connect(ui->registerButton, &QPushButton::clicked, this,
        &Login::HandleRegistrationClick);
    connect(ui->passwordVisibility, &QCheckBox::clicked, [=]()
    {
        ui->password->SetEchoMode((ui->passwordVisibility->isChecked()) ?
            (QLineEdit::Normal) : (QLineEdit::Password));
    });

    ui->login->SetName("Логін");
    ui->login->SetChecker(new DefaultEmailChecker{});

    ui->password->SetName("Пароль");
    ui->password->SetChecker(new DefaultPasswordChecker{});
    ui->password->SetEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}

DefaultRecord::ID Login::GetCurrentAccountID() const noexcept
{
    return m_CurrentAccountID;
}

void Login::HandleLoginClick()
{
    if (!IsDoctor() && !ui->login->CheckEdit())
    {
        return;
    }

    if (!ui->password->CheckEdit())
    {
        ui->password->ClearEditValue();

        return;
    }

    if (IsDoctor())
    {
        TryLoginDoctor();
    }
    else
    {
        TryLoginPatient();
    }
}

void Login::HandleRegistrationClick()
{
    ResetEditFields();

    emit RegistrationClicked();
}

void Login::TryLoginPatient() noexcept
{
    const PatientsRecord patient{ ui->login->GetEditValue() };

    if (patient.IsEmpty())
    {
        ui->login->SetErrorMessage("Такого пацієнта не було зареєстовано");

        return;
    }

    if (CheckPasswordMatch(patient.GetPasswordID()))
    {
        m_CurrentAccountID = patient.GetID();

        emit PatientLoginClicked();
    }
}


void Login::TryLoginDoctor() noexcept
{
    const DoctorsRecord doctor{ ui->login->GetEditValue() };

    if (doctor.IsEmpty())
    {
        ui->login->SetErrorMessage("Такого лікаря немає в базі даних");

        return;
    }

    if (CheckPasswordMatch(doctor.GetPasswordID()))
    {
        m_CurrentAccountID = doctor.GetID();

        emit DoctorLoginClicked();
    }
}

bool Login::CheckPasswordMatch(const DefaultRecord::ID ID) noexcept
{
    const PasswordsRecord password{ ID };

    const QString encryptedPassword
    {
        m_Encryptor.Encrypt(ui->password->GetEditValue(),
            password.GetSalt())
    };

    if (password.GetEncrypted() != encryptedPassword)
    {
        ui->password->SetErrorMessage("Введений пароль не є правильним");
        ui->password->ClearEditValue();

        return false;
    }

    ResetEditFields();

    return true;
}

void Login::ResetEditFields() noexcept
{
    ui->login->ClearEditValue();
    ui->password->ClearEditValue();

    ui->doctorCheckBox->setChecked(false);
}

bool Login::IsDoctor() const noexcept
{
    return ui->doctorCheckBox->isChecked();
}