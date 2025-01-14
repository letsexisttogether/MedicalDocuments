#include <QApplication>
#include <QPair>

#include "Authorization/Window/authorizationwindow.h"
#include "SQL/Manager/SQLManager.hpp"
#include "Authorization/PasswordEncryption/PasswordEncryptor.hpp"

void AddPasswords() noexcept;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLocale::setDefault(QLocale{ QLocale::Ukrainian, QLocale::Ukraine });

    SQLManager::Init("QODBC", "192.168.0.11,1433", "MedicalDocuments",
        "MedicalDocumentsConnection", "QWERTY25!");

    AuthorizationWindow w;
    w.show();

    // AddPasswords();

    return a.exec();
}

void AddPasswords() noexcept
{
    const QStringList passwords
    {
        "Abc12345!",
        "Qwerty123!",
        "Password1@",
        "Welcome2023!",
        "HelloWorld1@",
        "MyPassword9#",
        "TestUser2022!",
        "Secret1234$",
        "StrongPass!1",
        "HappyDay2023#",
        "Summer@1234",
        "Winter2022!",
        "GoodMorning1@",
        "LoveYou123!",
        "OpenSesame1@",
        "Sunshine2023!",
        "Coffee@1234",
        "Winter@2023!",
        "1PasswordTest!",
        "Admin1234!"
    };

    SQLManager& manager{ SQLManager::GetInstance() };

    PasswordEncryptor encrytor{};

    for (const QString& password: passwords)
    {
        const QString salt{ encrytor.GenerateSalt() };

        const QString encryptedPassword{ encrytor.Encrypt(password, salt ) };

        const QString query
        {
            QString("INSERT INTO Passwords (Encrypted, Salt) "
                "VALUES ('%1', '%2');")
            .arg(encryptedPassword)
            .arg(salt)
        };

        manager.InsertDataToTable(query);
    }
}