#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "appointmentwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->openAppointmentWindowButton, &QPushButton::clicked, this, &MainWindow::openAppointmentWindow);

    QWidget *scrollWidget = ui->scrollArea->widget();
    QVBoxLayout *scrollLayout = qobject_cast<QVBoxLayout *>(scrollWidget->layout());
    if (!scrollLayout) {
        // Якщо layout не налаштований у Designer, створюємо його
        scrollLayout = new QVBoxLayout(scrollWidget);
        scrollWidget->setLayout(scrollLayout);
    }

    // Додаємо записи динамічно
    for (int i = 1; i <= 10; ++i) {
        QWidget *recordWidget = new QWidget(this);
        QVBoxLayout *recordLayout = new QVBoxLayout(recordWidget);

        // Додаємо текстові записи
        recordLayout->addWidget(new QLabel(QString("Номер пацієнта %1: Ім'я %2").arg(i).arg(QString("Влад")), this));
        recordLayout->addWidget(new QLabel(QString("Запис %1: Текст 2").arg(i), this));
        recordLayout->addWidget(new QLabel(QString("Запис %1: Текст 3").arg(i), this));

        // Налаштовуємо стиль запису
        recordWidget->setStyleSheet("border: 1px solid gray; margin: 5px; padding: 10px;");

        // Додаємо до прокрутки
        scrollLayout->addWidget(recordWidget);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openAppointmentWindow()
{
    AppointmentWindow *appointmentWindow = new AppointmentWindow();

    // Відображаємо друге вікно
    appointmentWindow->show();

    // Закриваємо перше вікно
    this->close();
}
