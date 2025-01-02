/********************************************************************************
** Form generated from reading UI file 'appointmentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPOINTMENTWINDOW_H
#define UI_APPOINTMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppointmentWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AppointmentWindow)
    {
        if (AppointmentWindow->objectName().isEmpty())
            AppointmentWindow->setObjectName("AppointmentWindow");
        AppointmentWindow->resize(800, 600);
        centralwidget = new QWidget(AppointmentWindow);
        centralwidget->setObjectName("centralwidget");
        AppointmentWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AppointmentWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        AppointmentWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AppointmentWindow);
        statusbar->setObjectName("statusbar");
        AppointmentWindow->setStatusBar(statusbar);

        retranslateUi(AppointmentWindow);

        QMetaObject::connectSlotsByName(AppointmentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AppointmentWindow)
    {
        AppointmentWindow->setWindowTitle(QCoreApplication::translate("AppointmentWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppointmentWindow: public Ui_AppointmentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPOINTMENTWINDOW_H
