#include "PasswordsRecord.hpp"

PasswordsRecord::PasswordsRecord()
    : DefaultRecord{ "Passwords "}
{}

PasswordsRecord::PasswordsRecord(const ID ID)
    : DefaultRecord{ "Passwords" }
{
    LoadData("ID", QString::number(ID));
}

PasswordsRecord::PasswordsRecord(const QString& encrypted,
    const QString& salt)
    : DefaultRecord{ "Passwords" },
    m_Encrypted{ encrypted }, m_Salt{ salt }
{}

void PasswordsRecord::InsertData() noexcept
{
    const QString values
    {
        QString("'%1', '%2'")
            .arg(m_Encrypted)
            .arg(m_Salt)
    };

    RawInsertData(values);
}

const QString& PasswordsRecord::GetEncrypted() const noexcept
{
    return m_Encrypted;
}

const QString& PasswordsRecord::GetSalt() const noexcept
{
    return m_Salt;
}

void PasswordsRecord::SetData(const TableRecord& record) noexcept
{
    m_ID = record.GetColumnValue("ID").toInt();

    m_Encrypted = record.GetColumnValue("Encrypted").toString();
    m_Salt = record.GetColumnValue("Salt").toString();
}