/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

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

class Ui_RegisterWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *passwordEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *acceptButton;
    QLineEdit *idEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName("RegisterWindow");
        RegisterWindow->resize(800, 600);
        centralwidget = new QWidget(RegisterWindow);
        centralwidget->setObjectName("centralwidget");
        passwordEdit = new QLineEdit(centralwidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(310, 270, 191, 26));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 130, 101, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(220, 210, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(220, 270, 63, 20));
        acceptButton = new QPushButton(centralwidget);
        acceptButton->setObjectName("acceptButton");
        acceptButton->setGeometry(QRect(330, 350, 141, 41));
        idEdit = new QLineEdit(centralwidget);
        idEdit->setObjectName("idEdit");
        idEdit->setGeometry(QRect(310, 210, 191, 26));
        RegisterWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegisterWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        RegisterWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterWindow);
        statusbar->setObjectName("statusbar");
        RegisterWindow->setStatusBar(statusbar);

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QCoreApplication::translate("RegisterWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("RegisterWindow", "\320\240\320\225\320\204\320\241\320\242\320\240\320\220\320\246\320\206\320\257", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWindow", "\320\237\320\276\321\210\321\202\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        acceptButton->setText(QCoreApplication::translate("RegisterWindow", "\320\227\320\260\321\200\320\265\321\224\321\201\321\202\321\200\321\203\320\262\320\260\321\202\320\270\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
