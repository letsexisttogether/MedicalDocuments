#ifndef DOCTORLOGIN_HPP
#define DOCTORLOGIN_HPP

#include <QWidget>

#include "SQL/Manager/SQLManager.hpp"
#include "Authorization/PasswordEncryption/PasswordEncryptor.hpp"

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

    SQLManager::ID GetCurrentAccountID() const noexcept;

signals:
    void PatientLoginClicked();
    void DoctorLoginClicked();
    void RegistrationClicked();

private slots:
    void HandleLoginClick();
    void HandleRegistrationClick();

private:
    bool CheckLogin(const QString& table, const QString& column) noexcept;

    void ResetEditFields() noexcept;

    bool IsDoctor() const noexcept;

private:
    Ui::Login* ui;

    SQLManager::ID m_CurrentAccountID{};
    PasswordEncryptor m_Encryptor{};
};

#endif // DOCTORLOGIN_HPP
