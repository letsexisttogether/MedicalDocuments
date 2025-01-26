#include "PasswordEchoChanger.hpp"
#include "ui_PasswordEchoChanger.h"

PasswordEchoChanger::PasswordEchoChanger(QWidget *parent)
    : QWidget{ parent }, ui{ new Ui::PasswordEchoChanger{} }
{
    ui->setupUi(this);
}

void PasswordEchoChanger::SetControllableEdit(QLineEdit* const edit)
{
    m_ControllableEdit = edit;
}

void PasswordEchoChanger::mousePressEvent(QMouseEvent *event)
{
    if (!m_ControllableEdit)
    {
        qDebug() << "[PasswordEchoChanger::mousePressEvent]"
            << "The controllable was not assigned";

        return;
    }

    if (event->button() == Qt::LeftButton)
    {
        const EchoMode echoMode = m_ControllableEdit->echoMode();

        m_ControllableEdit->setEchoMode((echoMode == EchoMode::Normal) ?
            (EchoMode::Password) : (EchoMode::Normal));
    }
}

PasswordEchoChanger::~PasswordEchoChanger()
{
    delete ui;
}
