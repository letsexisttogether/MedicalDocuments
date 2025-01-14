#ifndef PASSWORDSTABLES_HPP
#define PASSWORDSTABLES_HPP

#include "SQL/Tables/DefaultRecord.hpp"

class PasswordsTable : public DefaultRecord
{
public:
    PasswordsTable();
    PasswordsTable(const PasswordsTable&) = default;
    PasswordsTable(PasswordsTable&&) = default;

    PasswordsTable(const ID ID);

    ~PasswordsTable() = default;

    const QString& GetEncrypted() const noexcept;
    const QString& GetSalt() const noexcept;

private:
    void SetData(const TableRecord& record) noexcept override;

private:
    QString m_Encrypted{};
    QString m_Salt{};
};

#endif // PASSWORDSTABLES_HPP
