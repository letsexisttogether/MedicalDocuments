#include "FieldCondition.hpp"

FieldCondition::FieldCondition(Condition condition)
    : m_Condition{ condition }
{}

FieldCondition::FieldCondition(QString&& message, Condition condition)
    : m_Message{ std::move(message) }, m_Condition{ condition }
{}

bool FieldCondition::Check(const QString& password) const noexcept
{
    return m_Condition(password);
}

const QString& FieldCondition::GetMessage() const noexcept
{
    return m_Message;
}

void FieldCondition::SetMessage(QString&& message) noexcept
{
    m_Message = std::move(message);
}