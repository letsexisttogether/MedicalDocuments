#include "FieldChecker.hpp"

#include <QDebug>

FieldChecker::FieldChecker(const Conditions& conditions)
    : m_Conditions{ conditions }
{}

bool FieldChecker::CheckPassword(const QString password)
    noexcept
{
    for (const FieldCondition& condition : m_Conditions)
    {
        if (!condition.Check(password))
        {
            qDebug() << condition.GetMessage();

            return false;
        }
    }

    return true;
}

void FieldChecker::AddCondition(FieldCondition&& condition)
{
    m_Conditions.append(std::move(condition));
}