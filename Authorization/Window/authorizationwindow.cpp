#include "authorizationwindow.h"
#include "ui_authorizationwindow.h"

#include <QRegularExpression>

#include "mainwindow.h"
#include "doctorclientwindow.h"

AuthorizationWindow::AuthorizationWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::AuthorizationWindow)
{
    ui->setupUi(this);

    connect(ui->authorizationWidget, &Login::PatientLoginClicked, this,
        &AuthorizationWindow::SwitchToPatientWindow);
    connect(ui->authorizationWidget, &Login::DoctorLoginClicked, this,
        &AuthorizationWindow::SwitchToDoctorWindow);

    connect(ui->authorizationWidget, &Login::RegistrationClicked, this,
        &AuthorizationWindow::OpenRegistration);
    connect(ui->registrationWidget, &SignUp::OperationCompleted, this,
        &AuthorizationWindow::OpenAuthorization);

    ui->authorizationWidget->setGeometry(0, 0, 960, 550);
    ui->registrationWidget->setGeometry(0, 0, 960, 550);

    OpenAuthorization();
}

AuthorizationWindow::~AuthorizationWindow()
{
    delete ui;
}

void AuthorizationWindow::SwitchToPatientWindow()
{
    MainWindow *window = new MainWindow
    {
        ui->authorizationWidget->GetCurrentAccountID()
    };

    window->show();

    this->close();
}

void AuthorizationWindow::SwitchToDoctorWindow()
{
    DoctorClientWindow *window = new DoctorClientWindow();
    window->show();

    this->close();
}

void AuthorizationWindow::OpenAuthorization()
{
    ui->authorizationWidget->show();
    ui->registrationWidget->hide();
}

void AuthorizationWindow::OpenRegistration()
{
    ui->authorizationWidget->hide();
    ui->registrationWidget->show();
}

void AuthorizationWindow::TogglePasswordVisibility()
{
    /*
    const bool isActive = ui->passwordVisibility->isChecked();

    ui->password->SetEchoMode((isActive) ?
        (QLineEdit::Normal) : (QLineEdit::Password));
    */
}