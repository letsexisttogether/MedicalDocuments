#include "authorizationwindow.h"
#include "ui_authorizationwindow.h"

#include <QRegularExpression>

#include "mainwindow.h"
#include "registerwindow.h"
#include "doctorclientwindow.h"

AuthorizationWindow::AuthorizationWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::AuthorizationWindow)
{
    ui->setupUi(this);

    connect(ui->acceptButton, &QPushButton::clicked, this, &AuthorizationWindow::AcceptData);
    connect(ui->registerButton, &QPushButton::clicked, this, &AuthorizationWindow::OpenRegistration);

    // Password фігня

    m_PasswordChecker.SetErrorLabel(ui->errorLabel);

    FieldCondition length
    {
        "Пароль повинен мати не менше 8 та не більше 64 знаків",
        [] (const QString& password)
        {
            const qsizetype length = password.length();
            return length >= 8 && length <= 64;
        }
    };
    m_PasswordChecker.AddCondition(std::move(length));

    FieldCondition uppercase
    {
        "Пароль повинен містити хоча б одну велику літеру",
        [] (const QString& password)
        {
            return password.contains(QRegularExpression{ "[A-Z]" });
        }
    };
    m_PasswordChecker.AddCondition(std::move(uppercase));

    FieldCondition digit
    {
        "Пароль повинен містити хоча б одну цифру",
        [] (const QString& password)
        {
            return password.contains(QRegularExpression{ "[0-9]" });
        }
    };
    m_PasswordChecker.AddCondition(std::move(digit));

    FieldCondition specialChar
    {
        "Пароль повинен містити хоча б один спеціальний символ",
        [] (const QString& password)
        {
            return password.contains(QRegularExpression
            {
                "[!@#$%^&*(),.?\":{}|<>-]"
            });
        }
    };
    m_PasswordChecker.AddCondition(std::move(specialChar));

    // Email фігня

    m_EmailChecker.SetErrorLabel(ui->errorLabel);

    FieldCondition emailFormat
    {
        "Email повинен бути наступного вигляду: example25@gmail.com",
        [] (const QString& email)
        {
            QRegularExpression emailRegex
            {
                R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})"
            };

            return emailRegex.match(email).hasMatch();
        }
    };
    m_EmailChecker.AddCondition(std::move(emailFormat));
}

AuthorizationWindow::~AuthorizationWindow()
{
    delete ui;
}

void AuthorizationWindow::AcceptData()
{
    const QString email{ ui->idEdit->text() };
    if (!m_EmailChecker.CheckField(email))
    {
        return;
    }

    const QString password{ ui->passwordEdit->text() };
    if (!m_PasswordChecker.CheckField(password))
    {
        return;
    }

    if(!isDoctor) //тестова фігня
    {
        MainWindow *mainWindow = new MainWindow();

        mainWindow->show();

        this->close();
    }
    else
    {
        DoctorClientWindow *doctorClientWindow = new DoctorClientWindow();

        doctorClientWindow->show();

        this->close();
    }
}

void AuthorizationWindow::OpenRegistration()
{
    RegisterWindow *registerWindow = new RegisterWindow();

    registerWindow->show();

    this->close();
}
