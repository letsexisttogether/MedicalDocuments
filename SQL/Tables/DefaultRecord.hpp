#ifndef DEFAULTRECORD_HPP
#define DEFAULTRECORD_HPP

#include "SQL/Manager/SQLManager.hpp"

class DefaultRecord
{
public:
    using ID = SQLManager::ID;

public:
    DefaultRecord() = default;
    DefaultRecord(const DefaultRecord&) = default;
    DefaultRecord(DefaultRecord&&) = default;

    explicit DefaultRecord(const ID ID, QString&& tableName);

    // It's not virtual for the compiler not to create a v-table
    ~DefaultRecord() = default;

    ID GetID() const noexcept;

    bool IsEmpty() const noexcept;

    DefaultRecord& operator = (const DefaultRecord&) noexcept = default;
    DefaultRecord& operator = (DefaultRecord&&) noexcept = default;

protected:
    TableRecord LoadRawData() noexcept;

protected:
    ID m_ID{};

    bool m_IsEmpty{ true };

private:
    QString m_TableName{};
};

#endif // DEFAULTRECORD_HPP
