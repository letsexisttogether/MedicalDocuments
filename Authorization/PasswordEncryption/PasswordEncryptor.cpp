#include "PasswordEncryptor.hpp"

#include <QRandomGenerator64>

PasswordEncryptor::PasswordEncryptor(const Algorithm algorithm)
    : m_Hash{ algorithm }
{}

QString PasswordEncryptor::Encrypt(const QString& password,
    const QString& salt) noexcept
{
    m_Hash.addData(password.toUtf8());
    m_Hash.addData(salt.toUtf8());

    QByteArray result{ m_Hash.result() };
    m_Hash.reset();

    return result.toBase64();
}

QString PasswordEncryptor::GenerateSalt() const noexcept
{
    QByteArray salt{};
    salt.resize(32);

    QRandomGenerator::global()->generate(salt.begin(), salt.end());

    return salt.toBase64();
}