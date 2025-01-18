#ifndef SIGNUP_HPP
#define SIGNUP_HPP

#include <QWidget>

#include "Authorization/PasswordEncryption/PasswordEncryptor.hpp"

namespace Ui
{
    class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);

    ~SignUp();

signals:
    void OperationCompleted();

private slots:
    void HandleRegistrationClick();
    void HandleReturnClick();

private:
    void ResetEditFields() noexcept;

private:
    Ui::SignUp *ui;

    PasswordEncryptor m_Encryptor{};
};

#endif // SIGNUP_HPP
