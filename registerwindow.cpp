#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Authorization/Window/authorizationwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

    connect(ui->acceptButton, &QPushButton::clicked, this, &RegisterWindow::AcceptData);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::AcceptData()
{
    if(ui->passwordEdit->text().isEmpty() || ui->idEdit->text().isEmpty())
        return;

    AuthorizationWindow *authorizationWindow = new AuthorizationWindow();

    authorizationWindow->show();

    this->close();
}
