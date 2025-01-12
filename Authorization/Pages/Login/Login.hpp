#ifndef DOCTORLOGIN_HPP
#define DOCTORLOGIN_HPP

#include <QWidget>

namespace Ui
{
    class Login;
}

class Login: public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

    ~Login();

signals:
    void PatientLoginClicked();
    void DoctorLoginClicked();
    void RegistrationClicked();

private slots:
    void HandleLoginClick();
    void HandleRegistrationClick();

private:
    bool CheckLogin(const QString& table, const QString& column) noexcept;

    bool IsDoctor() const noexcept;

private:
    Ui::Login* ui;
};

#endif // DOCTORLOGIN_HPP
