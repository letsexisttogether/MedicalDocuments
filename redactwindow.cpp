#include "redactwindow.h"
#include "ui_redactwindow.h"
#include "QVBoxLayout"
#include "QTextEdit"

#include "MainClient/Doctor/Window/DoctorWindow.hpp"

RedactWindow::RedactWindow(QWidget *parent, QString name, QString text)
    : QMainWindow(parent), m_name(name), m_text(text)
    , ui(new Ui::RedactWindow)
{
    ui->setupUi(this);

    connect(ui->confirmButton, &QPushButton::clicked, this, &RedactWindow::OnConfirm);


    QWidget *scrollWidget = ui->scrollArea->widget();
    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout *>(scrollWidget->layout());
    if (!scrollLayout)
    {
        // Якщо layout не налаштований у Designer, створюємо його
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }
    else
    {
        QLayoutItem *item;
        while ((item = scrollLayout->takeAt(0)) != nullptr) {
            delete item->widget(); // Видаляємо віджет
            delete item;
        }
    }

    // Додаємо записи динамічно
    QWidget *recordWidget = new QWidget(this);
    QVBoxLayout *recordLayout = new QVBoxLayout(recordWidget);

    // Додаємо текстові записи
    recordLayout->addWidget(
        new QLabel(QString("Ім'я пацієнта: %1 ").arg(name), this));

    QHBoxLayout *textLayout = new QHBoxLayout();
    Editor = new QTextEdit(QString(text), this);
    //recordLayout->addWidget(Editor);

    textLayout->addWidget(new QLabel(QString("Діагноз")));
    textLayout->addWidget(Editor);

    // Додаємо горизонтальний layout з кнопками до вертикального layout
    recordLayout->addLayout(textLayout);

    // Налаштовуємо стиль запису
    recordWidget->setStyleSheet("border: 1px solid gray; margin: 5px; padding: 10px;");

    // Додаємо до прокрутки
    scrollLayout->addWidget(recordWidget);
}

RedactWindow::~RedactWindow()
{
    delete ui;
}

void RedactWindow::OnConfirm()
{
    DoctorWindow* preivous = (DoctorWindow*)this->parentWidget();
    int index = preivous->TestData[m_name].indexOf(m_text);
    preivous->TestData[m_name].replace(index, Editor->toPlainText());
    preivous->show();
    preivous->OnPatientChange(m_name);
    this->close();
}
