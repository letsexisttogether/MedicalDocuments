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

    FieldCondition length
    {
        //"Пароль повинен мати не менше 8 та не більше 64 знаків",
        "Password < 8",
        [] (const QString& password)
        {
            const qsizetype length = password.length();
            return length >= 8 && length <= 64;
        }
    };
    m_PasswordChecker.AddCondition(std::move(length));

    FieldCondition uppercase
    {
        //"Пароль повинен містити хоча б одну велику літеру",
        "No uppercase letter",
        [] (const QString& password)
        {
            return password.contains(QRegularExpression{ "[A-Z]" });
        }
    };
    m_PasswordChecker.AddCondition(std::move(uppercase));

    FieldCondition digit
    {
        //"Пароль повинен містити хоча б одну цифру",
        "No digit",
        [] (const QString& password)
        {
            return password.contains(QRegularExpression{ "[0-9]" });
        }
    };
    m_PasswordChecker.AddCondition(std::move(digit));

    FieldCondition specialChar
    {
        //"Пароль повинен містити хоча б один спеціальний символ",
        "No special character",
        [] (const QString& password)
        {
            return password.contains(QRegularExpression
            {
                "[!@#$%^&*(),.?\":{}|<>-]"
            });
        }
    };
    m_PasswordChecker.AddCondition(std::move(specialChar));
}

AuthorizationWindow::~AuthorizationWindow()
{
    delete ui;
}

void AuthorizationWindow::AcceptData()
{
    const QString password{ ui->passwordEdit->text() };
    if (!m_PasswordChecker.CheckPassword(password))
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
