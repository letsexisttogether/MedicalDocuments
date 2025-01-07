#ifndef FIELDCHECKER_HPP
#define FIELDCHECKER_HPP

#include <QVector>
#include <QLabel>

#include "FieldCondition.hpp"

class FieldChecker
{
public:
    using Conditions = QVector<FieldCondition>;

public:
    FieldChecker() = default;
    FieldChecker(const FieldChecker&) = default;
    FieldChecker(FieldChecker&&) = default;

    FieldChecker(QLabel* const errorLabel);
    FieldChecker(const Conditions& conditions, QLabel* const errorLabel);

    virtual ~FieldChecker() = default;

    bool CheckField(const QString password) noexcept;

    void AddCondition(FieldCondition&& condition);

    void SetErrorLabel(QLabel* const errorLabel) noexcept;

private:
    Conditions m_Conditions{};
    QLabel* m_ErrorLabel{};
};

#endif // FIELDCHECKER_HPP
