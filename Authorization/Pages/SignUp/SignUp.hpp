#ifndef SIGNUP_HPP
#define SIGNUP_HPP

#include <QWidget>
#include <optional>

#include "SQL/Manager/SQLManager.hpp"

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
    SQLManager::ID AddPerson() const noexcept;
    SQLManager::ID AddPassword() const noexcept;
    SQLManager::ID AddPatient(const SQLManager::ID personID,
        const SQLManager::ID passwordID) const noexcept;

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_HPP
