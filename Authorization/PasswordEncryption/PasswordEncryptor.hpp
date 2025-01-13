#ifndef PASSWORDENCRYPTOR_HPP
#define PASSWORDENCRYPTOR_HPP

#include <QCryptographicHash>
#include <QString>

class PasswordEncryptor
{
public:
    using Algorithm = QCryptographicHash::Algorithm;

public:
    PasswordEncryptor() = default;
    PasswordEncryptor(const PasswordEncryptor&) = delete;
    PasswordEncryptor(PasswordEncryptor&&) = default;

    PasswordEncryptor(const Algorithm algorithm);

    ~PasswordEncryptor() = default;

    QString Encrypt(const QString& password, const QString& salt) noexcept;

    // TODO: maybe move this login to a dedicated class, but deff not now
    QString GenerateSalt() const noexcept;

    PasswordEncryptor& operator = (const PasswordEncryptor&) noexcept = delete;
    PasswordEncryptor& operator = (PasswordEncryptor&&) noexcept = delete;

private:

private:
    QCryptographicHash m_Hash
    {
        QCryptographicHash::Sha256
    };
};

#endif // PASSWORDENCRYPTOR_HPP
