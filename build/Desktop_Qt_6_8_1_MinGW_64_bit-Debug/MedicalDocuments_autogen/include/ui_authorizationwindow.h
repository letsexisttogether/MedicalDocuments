/********************************************************************************
** Form generated from reading UI file 'authorizationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATIONWINDOW_H
#define UI_AUTHORIZATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthorizationWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *idEdit;
    QLineEdit *passwordEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *acceptButton;
    QPushButton *registerButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AuthorizationWindow)
    {
        if (AuthorizationWindow->objectName().isEmpty())
            AuthorizationWindow->setObjectName("AuthorizationWindow");
        AuthorizationWindow->resize(800, 600);
        centralwidget = new QWidget(AuthorizationWindow);
        centralwidget->setObjectName("centralwidget");
        idEdit = new QLineEdit(centralwidget);
        idEdit->setObjectName("idEdit");
        idEdit->setGeometry(QRect(290, 220, 191, 26));
        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(290, 280, 191, 26));
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(330, 140, 101, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 220, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 280, 63, 20));
        acceptButton = new QPushButton(centralwidget);
        acceptButton->setObjectName("acceptButton");
        acceptButton->setGeometry(QRect(210, 360, 141, 41));
        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(390, 360, 141, 41));
        AuthorizationWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AuthorizationWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        AuthorizationWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AuthorizationWindow);
        statusbar->setObjectName("statusbar");
        AuthorizationWindow->setStatusBar(statusbar);

        retranslateUi(AuthorizationWindow);

        QMetaObject::connectSlotsByName(AuthorizationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AuthorizationWindow)
    {
        AuthorizationWindow->setWindowTitle(QCoreApplication::translate("AuthorizationWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("AuthorizationWindow", "\320\220\320\222\320\242\320\236\320\240\320\230\320\227\320\220\320\246\320\206\320\257", nullptr));
        label_2->setText(QCoreApplication::translate("AuthorizationWindow", "\320\237\320\276\321\210\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("AuthorizationWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        acceptButton->setText(QCoreApplication::translate("AuthorizationWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\321\203\320\262\320\260\321\202\320\270\321\201\321\217", nullptr));
        registerButton->setText(QCoreApplication::translate("AuthorizationWindow", "\320\227\320\260\321\200\320\265\321\224\321\201\321\202\321\200\321\203\320\262\320\260\321\202\320\270\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthorizationWindow: public Ui_AuthorizationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATIONWINDOW_H
