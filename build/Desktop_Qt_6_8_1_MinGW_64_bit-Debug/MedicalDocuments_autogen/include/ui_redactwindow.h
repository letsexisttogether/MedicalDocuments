/********************************************************************************
** Form generated from reading UI file 'redactwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REDACTWINDOW_H
#define UI_REDACTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RedactWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *confirmButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RedactWindow)
    {
        if (RedactWindow->objectName().isEmpty())
            RedactWindow->setObjectName("RedactWindow");
        RedactWindow->resize(800, 600);
        centralwidget = new QWidget(RedactWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(320, 40, 141, 41));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(60, 100, 671, 311));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 669, 309));
        scrollArea->setWidget(scrollAreaWidgetContents);
        confirmButton = new QPushButton(centralwidget);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(320, 450, 151, 41));
        RedactWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RedactWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        RedactWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RedactWindow);
        statusbar->setObjectName("statusbar");
        RedactWindow->setStatusBar(statusbar);

        retranslateUi(RedactWindow);

        QMetaObject::connectSlotsByName(RedactWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RedactWindow)
    {
        RedactWindow->setWindowTitle(QCoreApplication::translate("RedactWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("RedactWindow", "\320\240\320\265\320\264\320\260\320\263\321\203\320\262\320\260\320\275\320\275\321\217 \320\267\320\260\320\277\320\270\321\201\321\203", nullptr));
        confirmButton->setText(QCoreApplication::translate("RedactWindow", "\320\237\321\226\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\320\270 \320\267\320\274\321\226\320\275\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RedactWindow: public Ui_RedactWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REDACTWINDOW_H
