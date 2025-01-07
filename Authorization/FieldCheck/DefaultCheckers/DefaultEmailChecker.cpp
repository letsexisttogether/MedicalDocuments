#include "DefaultEmailChecker.hpp"

#include <QRegularExpression>

DefaultEmailChecker::DefaultEmailChecker()
{
    FieldCondition length
    {
        "Email повинен мати не менше 5 та не більше 320 знаків",
        [] (const QString& email)
        {
            const qsizetype length = email.length();
            return length >= 5 && length <= 320;
        }
    };
    AddCondition(std::move(length));

    FieldCondition format
    {
        "Email повинен бути наступного вигляду: example25@gmail.com",
        [] (const QString& email)
        {
            QRegularExpression emailRegex
            {
                R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})"
            };

            return emailRegex.match(email).hasMatch();
        }
    };
    AddCondition(std::move(format));
}

