#ifndef PASSWORDCONDITION_HPP
#define PASSWORDCONDITION_HPP

#include <QString>
#include <functional>

class PasswordCondition
{
public:
    using Condition = std::function<bool(const QString&)>;

public:
    PasswordCondition() = default;
    PasswordCondition(const PasswordCondition&) = default;
    PasswordCondition(PasswordCondition&&) = default;

    PasswordCondition(Condition condition);
    PasswordCondition(QString&& message, Condition condition);

    ~PasswordCondition() = default;

    bool Check(const QString& password) const noexcept;

    QString GetMessage() const noexcept;
    void SetMessage(QString&& message) noexcept;

    PasswordCondition& operator = (const PasswordCondition&) noexcept = default;
    PasswordCondition& operator = (PasswordCondition&&) noexcept = default;

protected:
    QString m_Message{};
    Condition m_Condition;
};

#endif // PASSWORDCONDITION_HPP
