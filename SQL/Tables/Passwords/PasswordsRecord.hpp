#ifndef PASSWORDSTABLES_HPP
#define PASSWORDSTABLES_HPP

#include "SQL/Tables/DefaultRecord.hpp"

class PasswordsRecord : public DefaultRecord
{
public:
    PasswordsRecord();
    PasswordsRecord(const PasswordsRecord&) = default;
    PasswordsRecord(PasswordsRecord&&) = default;

    explicit PasswordsRecord(const ID ID);
    PasswordsRecord(const QString& encrypted, const QString& salt);

    ~PasswordsRecord() = default;

    void InsertData() noexcept override;

    const QString& GetEncrypted() const noexcept;
    const QString& GetSalt() const noexcept;

private:
    void SetData(const TableRecord& record) noexcept override;

private:
    QString m_Encrypted{};
    QString m_Salt{};
};

#endif // PASSWORDSTABLES_HPP
