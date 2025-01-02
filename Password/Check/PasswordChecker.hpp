#ifndef PASSWORDCHECKER_HPP
#define PASSWORDCHECKER_HPP

#include <QVector>

#include "PasswordCondition.hpp"

class PasswordChecker
{
public:
    using Conditions = QVector<PasswordCondition>;

public:
    PasswordChecker() = default;
    PasswordChecker(const PasswordChecker&) = default;
    PasswordChecker(PasswordChecker&&) = default;

    PasswordChecker(const Conditions& conditions);

    ~PasswordChecker() = default;

    bool CheckPassword(const QString password) noexcept;

    void AddCondition(PasswordCondition&& condition);

private:
    Conditions m_Conditions{};
};

#endif // PASSWORDCHECKER_HPP
