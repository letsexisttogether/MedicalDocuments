#include "PasswordsTable.hpp"

PasswordsTable::PasswordsTable()
    : DefaultRecord{ "Passwords "}
{}

PasswordsTable::PasswordsTable(const ID ID)
    : DefaultRecord{ "Passwords" }
{
    LoadData("ID", QString::number(ID));
}

const QString& PasswordsTable::GetEncrypted() const noexcept
{
    return m_Encrypted;
}

const QString& PasswordsTable::GetSalt() const noexcept
{
    return m_Salt;
}

void PasswordsTable::SetData(const TableRecord& record) noexcept
{
    m_ID = record.GetColumnValue("ID").toInt();

    m_Encrypted = record.GetColumnValue("Encrypted").toString();
    m_Salt = record.GetColumnValue("Salt").toString();
}