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

    explicit DefaultRecord(QString&& tableName);
    explicit DefaultRecord(const ID ID, QString&& tableName);

    virtual ~DefaultRecord() = default;

    virtual void InsertData() noexcept;

    ID GetID() const noexcept;

    // TODO: Remove if everything works
    bool IsEmpty() const noexcept;

    DefaultRecord& operator = (const DefaultRecord&) noexcept = default;
    DefaultRecord& operator = (DefaultRecord&&) noexcept = default;

protected:
    void LoadData(const QString& column, const QString& value) noexcept;

    TableRecord LoadRawData(const QString& column, const QString& value)
        noexcept;

    virtual void SetData(const TableRecord& record) noexcept = 0;

    const QString& GetTableName() const noexcept;

protected:
    ID m_ID{};

    bool m_IsEmpty{ true };

private:
    QString m_TableName{};
};

#endif // DEFAULTRECORD_HPP
