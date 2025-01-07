#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QMainWindow>

#include "Authorization/FieldCheck/FieldChecker.hpp"

namespace Ui
{
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

    void TogglePasswordVisibility();

private:


private:
    Ui::AuthorizationWindow *ui;
    bool isDoctor = false; //тестова фігня потім буде зчитуватися з бази даних
};

#endif // AUTHORIZATIONWINDOW_H
