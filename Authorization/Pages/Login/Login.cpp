#include "Login.hpp"
#include "ui_Login.h"

#include "SQL/Manager/SQLManager.hpp"
#include "Authorization/FieldCheck/DefaultCheckers/DefaultPasswordChecker.hpp"
#include "Authorization/FieldCheck/DefaultCheckers/DefaultEmailChecker.hpp"

Login::Login(QWidget *parent)
    : QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->acceptButton, &QPushButton::clicked, this,
        &Login::HandleLoginClick);
    connect(ui->registerButton, &QPushButton::clicked, this,
        &Login::HandleRegistrationClick);

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


SQLManager::ID Login::GetCurrentAccountID() const noexcept
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
        if (CheckLogin("Doctors", "SpecialCode"))
        {
            ResetEditFields();

            emit DoctorLoginClicked();
        }
    }
    else if (CheckLogin("Patients", "Email"))
    {
        ResetEditFields();

        emit PatientLoginClicked();
    }
}

void Login::HandleRegistrationClick()
{
    ResetEditFields();

    emit RegistrationClicked();
}

bool Login::CheckLogin(const QString& table, const QString& column) noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString query
    {
        QString("SELECT %1.PersonID, %1.%2, Passwords.Encrypted, Passwords.Salt "
            "FROM %1 "
            "JOIN Passwords ON %1.PasswordID = Passwords.ID "
            "WHERE %1.%2 = '%3'")
        .arg(table, column, ui->login->GetEditValue())
    };

    qDebug() << query;

    QList<TableRecord> data{ manager.ReadTableData(query) };

    if (data.isEmpty())
    {
        qDebug() << "There's no such data";

        m_CurrentAccountID = SQLManager::ID{};

        return false;
    }
    const TableRecord& person{ data.first() };

    const QString recordPassword
    {
        person.GetColumnValue("Encrypted").toString()
    };
    const QString recordSalt
    {
        person.GetColumnValue("Salt").toString()
    };

    const QString enteredPassword
    {
        ui->password->GetEditValue()
    };
    const QString encryptedPassword
    {
        m_Encryptor.Encrypt(ui->password->GetEditValue(), recordSalt)
    };

    if (recordPassword != encryptedPassword)
    {
        ui->password->SetErrorMessage("Введений пароль не є правильним");
        ui->password->ClearEditValue();

        m_CurrentAccountID = SQLManager::ID{};

        return false;
    }

    m_CurrentAccountID = person.GetColumnValue("PersonID").toInt();

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