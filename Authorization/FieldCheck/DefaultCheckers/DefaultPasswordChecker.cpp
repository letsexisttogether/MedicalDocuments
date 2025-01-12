#include "DefaultPasswordChecker.hpp"

#include <QRegularExpression>

DefaultPasswordChecker::DefaultPasswordChecker()
{
    FieldCondition length
    {
        "Пароль повинен мати не менше 8 та не більше 64 знаків",
        [] (const QString& password)
        {
            const qsizetype length = password.length();
            return length >= 8 && length <= 64;
        }
    };
    AddCondition(std::move(length));

    FieldCondition uppercase
    {
        "Пароль повинен містити хоча б одну велику літеру",
        [] (const QString& password)
        {
            return password.contains(QRegularExpression{ "[A-Z]" });
        }
    };
    AddCondition(std::move(uppercase));

    FieldCondition digit
    {
        "Пароль повинен містити хоча б одну цифру",
        [] (const QString& password)
        {
            return password.contains(QRegularExpression{ "[0-9]" });
        }
    };
    AddCondition(std::move(digit));

    FieldCondition specialChar
    {
        "Пароль повинен містити хоча б один спеціальний символ",
        [] (const QString& password)
        {
            return password.contains(QRegularExpression
            {
                "[!@#$%^&*(),.?\":{}|<>-]"
            });
        }
    };
    AddCondition(std::move(specialChar));
}
