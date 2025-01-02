#ifndef PASSWORDCHECKER_HPP
#define PASSWORDCHECKER_HPP

#include <QVector>

#include "FieldCondition.hpp"

class FieldChecker
{
public:
    using Conditions = QVector<FieldCondition>;

public:
    FieldChecker() = default;
    FieldChecker(const FieldChecker&) = default;
    FieldChecker(FieldChecker&&) = default;

    FieldChecker(const Conditions& conditions);

    ~FieldChecker() = default;

    bool CheckPassword(const QString password) noexcept;

    void AddCondition(FieldCondition&& condition);

private:
    Conditions m_Conditions{};
};

#endif // PASSWORDCHECKER_HPP
