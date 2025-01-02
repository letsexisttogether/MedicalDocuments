#include "PasswordCondition.hpp"

PasswordCondition::PasswordCondition(Condition condition)
    : m_Condition{ condition }
{}

PasswordCondition::PasswordCondition(QString&& message, Condition condition)
    : m_Message{ std::move(message) }, m_Condition{ condition }
{}

bool PasswordCondition::Check(const QString& password) const noexcept
{
    return m_Condition(password);
}

QString PasswordCondition::GetMessage() const noexcept
{
    return m_Message;
}

void PasswordCondition::SetMessage(QString&& message) noexcept
{
    m_Message = std::move(message);
}