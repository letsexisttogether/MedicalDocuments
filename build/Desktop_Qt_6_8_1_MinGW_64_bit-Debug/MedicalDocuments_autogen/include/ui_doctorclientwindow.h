/********************************************************************************
** Form generated from reading UI file 'doctorclientwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORCLIENTWINDOW_H
#define UI_DOCTORCLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DoctorClientWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *openAppointmentWindowButton;
    QLabel *label_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_2;
    QLabel *label;
    QComboBox *patientsBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DoctorClientWindow)
    {
        if (DoctorClientWindow->objectName().isEmpty())
            DoctorClientWindow->setObjectName("DoctorClientWindow");
        DoctorClientWindow->resize(800, 600);
        centralwidget = new QWidget(DoctorClientWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 40, 191, 31));
        openAppointmentWindowButton = new QPushButton(centralwidget);
        openAppointmentWindowButton->setObjectName("openAppointmentWindowButton");
        openAppointmentWindowButton->setGeometry(QRect(340, 510, 121, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(250, 70, 121, 20));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 140, 801, 361));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 799, 359));
        scrollArea->setWidget(scrollAreaWidgetContents_2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 10, 101, 20));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 63, 20));
        patientsBox = new QComboBox(centralwidget);
        patientsBox->setObjectName("patientsBox");
        patientsBox->setGeometry(QRect(380, 70, 301, 26));
        DoctorClientWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DoctorClientWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        DoctorClientWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DoctorClientWindow);
        statusbar->setObjectName("statusbar");
        DoctorClientWindow->setStatusBar(statusbar);

        retranslateUi(DoctorClientWindow);

        QMetaObject::connectSlotsByName(DoctorClientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DoctorClientWindow)
    {
        DoctorClientWindow->setWindowTitle(QCoreApplication::translate("DoctorClientWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("DoctorClientWindow", "\320\235\320\260\320\273\320\260\321\210\321\202\321\203\320\262\320\260\320\275\320\275\321\217 \320\277\321\200\320\276\321\204\321\226\320\273\321\216", nullptr));
        openAppointmentWindowButton->setText(QCoreApplication::translate("DoctorClientWindow", "\320\224\320\276\320\264\320\260\321\202\320\270 \320\267\320\260\320\277\320\270\321\201", nullptr));
        label_3->setText(QCoreApplication::translate("DoctorClientWindow", "\320\236\320\261\320\265\321\200\321\226\321\202\321\214 \320\277\320\260\321\206\321\226\321\224\320\275\321\202\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("DoctorClientWindow", "\320\242\320\243\320\242 \320\242\320\206\320\237\320\220 \320\237\320\206\320\221", nullptr));
        label->setText(QCoreApplication::translate("DoctorClientWindow", "\320\237\320\206\320\221:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DoctorClientWindow: public Ui_DoctorClientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORCLIENTWINDOW_H
