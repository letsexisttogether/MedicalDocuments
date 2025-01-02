#ifndef REDACTWINDOW_H
#define REDACTWINDOW_H

#include <QMainWindow>
#include "QTextEdit"

namespace Ui {
class RedactWindow;
}

class RedactWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RedactWindow(QWidget *parent = nullptr, QString name = " ", QString text = " ");
    ~RedactWindow();

private slots:
    void OnConfirm();

private:
    Ui::RedactWindow *ui;

    QString m_name; // не потрібно, для тесту без БД
    QString m_text; // не потрібно, для тесту без БД

    QTextEdit* Editor; // хз можна зробити по іншому можна просто буде більше таких додати
};

#endif // REDACTWINDOW_H
