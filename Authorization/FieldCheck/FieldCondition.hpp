#ifndef PASSWORDCONDITION_HPP
#define PASSWORDCONDITION_HPP

#include <QString>
#include <functional>

class FieldCondition
{
public:
    using Condition = std::function<bool(const QString&)>;

public:
    FieldCondition() = default;
    FieldCondition(const FieldCondition&) = default;
    FieldCondition(FieldCondition&&) = default;

    FieldCondition(Condition condition);
    FieldCondition(QString&& message, Condition condition);

    ~FieldCondition() = default;

    bool Check(const QString& password) const noexcept;

    const QString& GetMessage() const noexcept;
    void SetMessage(QString&& message) noexcept;

    FieldCondition& operator = (const FieldCondition&) noexcept = default;
    FieldCondition& operator = (FieldCondition&&) noexcept = default;

protected:
    QString m_Message{};
    Condition m_Condition;
};

#endif // PASSWORDCONDITION_HPP
