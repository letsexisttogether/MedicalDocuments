#include "PasswordChecker.hpp"

#include <QDebug>

PasswordChecker::PasswordChecker(const Conditions& conditions)
    : m_Conditions{ conditions }
{}

bool PasswordChecker::CheckPassword(const QString password)
    noexcept
{
    for (const PasswordCondition& condition : m_Conditions)
    {
        if (!condition.Check(password))
        {
            qDebug() << condition.GetMessage();

            return false;
        }
    }

    return true;
}

void PasswordChecker::AddCondition(PasswordCondition&& condition)
{
    m_Conditions.append(std::move(condition));
}