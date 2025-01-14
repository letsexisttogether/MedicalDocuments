#include "DefaultRecord.hpp"

DefaultRecord::DefaultRecord(const ID ID, QString&& tableName)
    : m_ID{ ID }, m_TableName{ std::move(tableName) }
{}

DefaultRecord::ID DefaultRecord::GetID() const noexcept
{
    return m_ID;
}

bool DefaultRecord::IsEmpty() const noexcept
{
    return m_ID == EmptyID;
}

TableRecord DefaultRecord::LoadRawData() noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString query
    {
        QString("SELECT * FROM %1 WHERE ID = %2")
            .arg(m_TableName)
            .arg(m_ID)
    };

    qDebug() << query;

    QList<TableRecord> data{ manager.ReadTableData(query) };

    if (data.isEmpty())
    {
        qWarning() << "There's no such data";
    }

    return data.first();
}