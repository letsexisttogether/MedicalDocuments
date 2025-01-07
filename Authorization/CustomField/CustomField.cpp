#include "CustomField.hpp"
#include "ui_CustomField.h"

CustomField::CustomField(QWidget *parent)
    : QWidget(parent), ui(new Ui::CustomField)
{
    ui->setupUi(this);
}

CustomField::~CustomField()
{
    delete ui;
}

void CustomField::SetName(const QString& name) noexcept
{
    ui->name->setText(name);
}

bool CustomField::CheckEdit() noexcept
{
    if (!m_EditChecker)
    {
        qDebug() << "There's no edit checker";

        return false;
    }

    const QString editData{ ui->edit->text() };

    return m_EditChecker->CheckField(editData);
}

QString CustomField::GetEditValue() const noexcept
{
    return ui->edit->text();
}

void CustomField::ClearEditValue() noexcept
{
    ui->edit->clear();
}

void CustomField::SetEchoMode(const QLineEdit::EchoMode echoMode) noexcept
{
    ui->edit->setEchoMode(echoMode);
}

void CustomField::SetChecker(FieldChecker* const editChecker) noexcept
{
    if (!editChecker)
    {
        return;
    }

    m_EditChecker.reset(editChecker);

    m_EditChecker->SetErrorLabel(ui->errorLabel);
}