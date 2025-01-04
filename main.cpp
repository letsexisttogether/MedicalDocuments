#include <QApplication>

#include "Authorization/Window/authorizationwindow.h"
#include "SQL/Manager/SQLManager.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SQLManager::Init("QODBC", "ALEXMACHINE", "MedicalDocuments");

    AuthorizationWindow w;
    w.show();

    return a.exec();
}
