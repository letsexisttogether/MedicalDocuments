#include "DefaultRecord.hpp"

DefaultRecord::DefaultRecord(QString&& tableName)
    : m_TableName{ std::move(tableName) }
{}

DefaultRecord::DefaultRecord(const ID ID, QString&& tableName)
    : m_ID{ ID }, m_TableName{ std::move(tableName) }
{}

DefaultRecord::ID DefaultRecord::GetID() const noexcept
{
    return m_ID;
}

bool DefaultRecord::IsEmpty() const noexcept
{
    return m_IsEmpty;
}

void DefaultRecord::LoadData(const QString& column, const QString& value)
    noexcept
{
    const TableRecord record{ LoadRawData(column, value) };

    if (record.IsEmpty())
    {
        m_IsEmpty = true;

        return;
    }

    m_IsEmpty = false;
    SetData(record);
}

TableRecord DefaultRecord::LoadRawData(const QString& column,
    const QString& value) noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString query
    {
        QString("SELECT * FROM %1 WHERE %2 = '%3'")
            .arg(m_TableName)
            .arg(column)
            .arg(value)
    };

    qDebug() << query;

    QList<TableRecord> data{ manager.ReadTableData(query) };

    if (data.isEmpty())
    {
        qWarning() << "Table" << m_TableName
            << "does not have contain data with ID" << m_ID;

        return TableRecord{};
    }

    return data.first();
}