#include "authorizationwindow.h"
#include "ui_authorizationwindow.h"

#include <QRegularExpression>

#include "mainwindow.h"
#include "registerwindow.h"
#include "doctorclientwindow.h"
#include "SQL/Manager/SQLManager.hpp"

#include "Authorization/FieldCheck/DefaultCheckers/DefaultPassowordChecker.hpp"
#include "Authorization/FieldCheck/DefaultCheckers/DefaultEmailChecker.hpp"

AuthorizationWindow::AuthorizationWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::AuthorizationWindow)
{
    ui->setupUi(this);

    connect(ui->acceptButton, &QPushButton::clicked, this,
        &AuthorizationWindow::AcceptData);
    connect(ui->registerButton, &QPushButton::clicked, this,
        &AuthorizationWindow::OpenRegistration);
    connect(ui->passwordVisibility, &QCheckBox::checkStateChanged, this,
        &AuthorizationWindow::TogglePasswordVisibility);

    ui->email->SetName("Пошта");
    ui->email->SetChecker(new DefaultEmailChecker{});


    ui->password->SetName("Пароль");
    ui->password->SetChecker(new DefaultPassowordChecker{});
    ui->password->SetEchoMode(QLineEdit::Password);
}

AuthorizationWindow::~AuthorizationWindow()
{
    delete ui;
}

void AuthorizationWindow::AcceptData()
{
    if (!ui->email->CheckEdit())
    {
        return;
    }

    if (!ui->password->CheckEdit())
    {
        ui->password->ClearEditValue();

        return;
    }

    /*
    // SQL test фігня
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString query
    {
        QString("SELECT Patients.Email, Passwords.Encrypted "
        "FROM Patients "
        "JOIN Passwords ON Patients.PasswordID = Passwords.ID "
        "WHERE Patients.Email = '%1'").arg(email)
    };

    QList<TableRecord> data{ manager.ReadTableData(query) };

    if (data.isEmpty())
    {
        qDebug() << "There's no such data";

        return;
    }
    const TableRecord& person{ data.first() };

    const QString recordEmail
    {
        person.GetColumnValue("Email").toString()
    };
    if (recordEmail != email)
    {
        qDebug() << "The email do not match";
    }

    const QString recordPassword
    {
        person.GetColumnValue("Encrypted").toString()
    };
    if (recordPassword != password)
    {
        qDebug() << "The password do not match";

        return;
    }

    */

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

void AuthorizationWindow::TogglePasswordVisibility()
{
    const bool isActive = ui->passwordVisibility->isChecked();

    ui->password->SetEchoMode((isActive) ?
        (QLineEdit::Normal) : (QLineEdit::Password));
}