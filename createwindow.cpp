#include "createwindow.h"
#include "ui_createwindow.h"
#include "QVBoxLayout"
#include "QTextEdit"
#include "doctorclientwindow.h"

CreateWindow::CreateWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateWindow)
{
    ui->setupUi(this);

    connect(ui->confirmButton, &QPushButton::clicked, this, &CreateWindow::OnConfirm);

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
        new QLabel(QString("Ім'я пацієнта: "), this)); // тіпа достав з бд

    QHBoxLayout *textLayout = new QHBoxLayout();
    QTextEdit* Editor = new QTextEdit(QString("text"), this); //теж тіпа достав з бд
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

CreateWindow::~CreateWindow()
{
    delete ui;
}

void CreateWindow::OnConfirm()
{
    //додання в бд буде

    DoctorClientWindow* preivous = (DoctorClientWindow*)this->parentWidget();
    preivous->show();
    this->close();
}
