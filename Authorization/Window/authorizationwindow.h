#ifndef AUTHORIZATIONWINDOW_H
#define AUTHORIZATIONWINDOW_H

#include <QMainWindow>

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
    void SwitchToPatientWindow();
    void SwitchToDoctorWindow();

    void OpenAuthorization();
    void OpenRegistration();

    void TogglePasswordVisibility();

private:
    Ui::AuthorizationWindow *ui;

    bool isDoctor = false; //тестова фігня потім буде зчитуватися з бази даних
};

#endif // AUTHORIZATIONWINDOW_H
