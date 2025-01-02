#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QMainWindow>
#include "Authorization/FieldCheck/FieldChecker.hpp"

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

    FieldChecker m_PasswordChecker{};
    FieldChecker m_EmailChecker{};
};

#endif // AUTHORIZATIONWINDOW_H
