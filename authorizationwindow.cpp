#include "authorizationwindow.h"
#include "ui_authorizationwindow.h"
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

    PasswordCondition length
    {
        //"Пароль повинен мати не менше 8 знаків",
        "Password < 8",
        [] (const QString& password)
        {
            return password.length() >= 8;
        }
    };
    m_Checker.AddCondition(std::move(length));
}

AuthorizationWindow::~AuthorizationWindow()
{
    delete ui;
}

void AuthorizationWindow::AcceptData()
{
    const QString password{ ui->passwordEdit->text() };
    if (!m_Checker.CheckPassword(password))
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
