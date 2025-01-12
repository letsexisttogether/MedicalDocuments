#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

#include "SQL/Manager/SQLManager.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const SQLManager::ID ID, QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void OpenAppointmentWindow();

private:
    void LoadBIO() noexcept;

private:
    Ui::MainWindow *ui;

    SQLManager::ID m_AccountID{};
};
#endif // MAINWINDOW_H
