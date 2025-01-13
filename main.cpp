#include <QApplication>
#include <QPair>

#include "Authorization/Window/authorizationwindow.h"
#include "SQL/Manager/SQLManager.hpp"
#include "Authorization/PasswordEncryption/PasswordEncryptor.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SQLManager::Init("QODBC", "ALEXMACHINE", "MedicalDocuments");

    AuthorizationWindow w;
    w.show();

    /*
    PasswordEncryptor encrytor{};

    const QStringList passwords
    {
        "Alexxx25!",
        "Letuslive17!3!27",
        "Alexxx25!",
        "QWERTY1215!",
        "LinchukLinchuk1234!"
    };

    for (const QString& password: passwords)
    {
        const QString salt{ encrytor.GenerateSalt() };

        const QString encryptedPassword{ encrytor.Encrypt(password, salt ) };

        qDebug() << "Original password: " << password
            << "Encrypted password: " << encryptedPassword
            << "Salt: " << salt;
    }
    */

    return a.exec();
}
