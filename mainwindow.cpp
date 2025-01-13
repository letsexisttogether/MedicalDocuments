#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "appointmentwindow.h"

MainWindow::MainWindow(const SQLManager::ID ID, QWidget *parent)
    : m_AccountID{ ID }, QMainWindow(parent), ui{ new Ui::MainWindow }
{
    ui->setupUi(this);

    LoadBIO();

    qDebug() << "The account ID: " << m_AccountID;

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

void MainWindow::OpenAppointmentWindow()
{
    AppointmentWindow *appointmentWindow = new AppointmentWindow();

    // Відображаємо друге вікно
    appointmentWindow->show();

    // Закриваємо перше вікно
    this->close();
}

void MainWindow::LoadBIO() noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString bioColumnName{ "BIO"};

    const QString query
    {
        QString("SELECT (People.LastName + ' ' + People.FirstName + "
            "' ' + People.Patronymic) AS %1 "
            "FROM Patients JOIN People "
            "ON Patients.PersonID = People.ID "
            "WHERE Patients.ID = %2")
        .arg(bioColumnName)
        .arg(m_AccountID)
    };

    QList<TableRecord> data{ manager.ReadTableData(query) };

    if (data.isEmpty())
    {
        qDebug() << "There's no such data";

        return;
    }
    const TableRecord& person{ data.first() };

    const QString bio{ person.GetColumnValue(bioColumnName).toString() };

    ui->bio->setText(bio);
}