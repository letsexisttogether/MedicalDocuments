#include "FieldChecker.hpp"

#include <QDebug>
#include <QTimer>

FieldChecker::FieldChecker(QLabel* const errorLabel)
    : m_ErrorLabel{ errorLabel }
{}

FieldChecker::FieldChecker(const Conditions& conditions,
    QLabel* const errorLabel)
    : m_Conditions{ conditions }, m_ErrorLabel{ errorLabel }
{}

bool FieldChecker::CheckField(const QString password)
    noexcept
{
    for (const FieldCondition& condition : m_Conditions)
    {
        if (!condition.Check(password))
        {
            if (m_ErrorLabel)
            {
                m_ErrorLabel->setText(condition.GetMessage());

                m_ErrorLabel->show();
                QTimer::singleShot(3000, m_ErrorLabel, &QLabel::hide);
            }

            return false;
        }
    }

    return true;
}

void FieldChecker::AddCondition(FieldCondition&& condition)
{
    m_Conditions.append(std::move(condition));
}

void FieldChecker::SetErrorLabel(QLabel* const errorLabel) noexcept
{
    m_ErrorLabel = errorLabel;
}