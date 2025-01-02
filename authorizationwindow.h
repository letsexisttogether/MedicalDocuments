#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QMainWindow>
#include "Password/Check/PasswordChecker.hpp"

namespace Ui {
class AuthorizationWindow;
}

class AuthorizationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AuthorizationWindow(QWidget *parent = nullptr);
    ~AuthorizationWindow();

private slots:
    void AcceptData();

    void OpenRegistration();

private:
    Ui::AuthorizationWindow *ui;
    bool isDoctor = true; //тестова фігня потім буде зчитуватися з бази даних

    PasswordChecker m_Checker{};
};

#endif // AUTHORIZATIONWINDOW_H
