#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include "SQL/Tables/People/PeopleRecord.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class PatientWindow;
}
QT_END_NAMESPACE

class PatientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PatientWindow(const SQLManager::ID ID, QWidget *parent = nullptr);

    ~PatientWindow();

private slots:
    void OpenAppointmentWindow();

private:
    void SetBIO() noexcept;

private:
    Ui::PatientWindow *ui;

    PeopleRecord m_Person;
};
#endif // MAINWINDOW_H
