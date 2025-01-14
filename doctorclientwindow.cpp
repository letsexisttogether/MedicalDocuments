#include "doctorclientwindow.h"
#include "ui_doctorclientwindow.h"
#include "QVBoxLayout"
#include "QTextEdit"
#include "redactwindow.h"

DoctorClientWindow::DoctorClientWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::DoctorClientWindow)
{
    ui->setupUi(this);

    TestData.insert("Oleskandr", QVector<QString>{"aaa", "aa", "a"});
    TestData.insert("Anastasia", QVector<QString>{"bbbb", "bbb", "bb", "b"});


    ui->patientsBox->addItem("Anastasia");
    ui->patientsBox->addItem("Oleskandr");

    connect(ui->patientsBox, &QComboBox::currentTextChanged, this, &DoctorClientWindow::OnPatientChange);
}

DoctorClientWindow::~DoctorClientWindow()
{
    delete ui;
}

void DoctorClientWindow::OnPatientChange(const QString &current_patient)
{
    //QString current_patient = ui->patientsBox->currentText();

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
    for (int i = 0; i < TestData[current_patient].count(); ++i) {
        QWidget *recordWidget = new QWidget(this);
        QVBoxLayout *recordLayout = new QVBoxLayout(recordWidget);

        // Додаємо текстові записи
        recordLayout->addWidget(
            new QLabel(QString("Ім'я пацієнта: %1 ").arg(current_patient), this));
        recordLayout->addWidget(new QLabel(QString("Діагноз: %1").arg(QString(TestData[current_patient][i])), this));

        QHBoxLayout *buttonLayout = new QHBoxLayout();

        // Створюємо кнопки
        QPushButton *button1 = new QPushButton("Редагувати", this);
        connect(button1, &QPushButton::clicked, [this, current_patient, i](){
            this->hide();
            RedactWindow* redactWindow = new RedactWindow(this, current_patient, TestData[current_patient][i]); //потім БД
            redactWindow->show();
            OnPatientChange(current_patient);
            return;
        });
        QPushButton *button2 = new QPushButton("Видалити", this);
        connect(button2, &QPushButton::clicked, [this, current_patient, i](){
            TestData[current_patient].removeAt(i);
            OnPatientChange(current_patient);
            return;
        });
        //button1->setVisible(true);
        //button2->setVisible(true);

        // Додаємо кнопки до горизонтального layout
        buttonLayout->addWidget(button1);
        buttonLayout->addWidget(button2);

        // Додаємо горизонтальний layout з кнопками до вертикального layout
        recordLayout->addLayout(buttonLayout);

        // Налаштовуємо стиль запису
        recordWidget->setStyleSheet("border: 1px solid gray; margin: 5px; padding: 10px;");

        // Додаємо до прокрутки
        scrollLayout->addWidget(recordWidget);
    }
}
