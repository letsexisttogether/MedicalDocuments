#include "MultyRecordLoader.hpp"

#include "SQL/Tables/Appointments/AppointmentsRecord.hpp"
#include "SQL/Tables/AppPharmConn/AppPharmConnRecord.hpp"

MultyRecordLoader::MultyRecordLoader(QString&& tableName)
    : m_TableName{ std::move(tableName) }
{}

template <class _Record>
_Record MultyRecordLoader::GetCurrent() noexcept
{
    const ID ID = m_Records.at(m_Current)
        .GetColumnValue("ID").toInt();

    const _Record record{ ID };

    m_Current += ((m_Current + 1) < m_Records.count());

    return record;
}

const qsizetype MultyRecordLoader::GetCount() const noexcept
{
    return m_Records.count();
}


void MultyRecordLoader::LoadData() noexcept
{
    const QString query
    {
        QString("SELECT ID FROM %1")
            .arg(m_TableName)
    };

    LoadRawData(query);
}

void MultyRecordLoader::LoadData(const QString& column,
    const QString& value) noexcept
{
    const QString query
    {
        QString("SELECT ID FROM %1 WHERE %2 = '%3'")
            .arg(m_TableName)
            .arg(column)
            .arg(value)
    };

    LoadRawData(query);
}

void MultyRecordLoader::LoadData(MultipleConditionsMap&& conditions) noexcept
{
    QString selectConditions{ "WHERE " };

    qsizetype i = 0;
    qsizetype size = conditions.size();
    for (MultipleConditionsMap::Iterator it = conditions.begin(); it != conditions.end(); ++it)
    {
        selectConditions.append(QString("%1 = '%2'")
            .arg(it.key())
            .arg(it.value()));

        if (++i < size)
        {
            selectConditions.append(" AND ");
        }
    }

    const QString query
    {
        QString("SELECT ID FROM %1 ")
            .arg(m_TableName)
            .append(selectConditions)
    };

    qDebug() << query;
}


void MultyRecordLoader::LoadRawData(const QString& query) noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    qDebug() << query;

    m_Records = manager.ReadTableData(query);

    if (m_Records.isEmpty())
    {
        qWarning() << "Table \"Appointments\""
            << "does not contain any data";
    }
}

template AppointmentsRecord MultyRecordLoader::GetCurrent<AppointmentsRecord>()
    noexcept;

template AppPharmConnRecord MultyRecordLoader::GetCurrent<AppPharmConnRecord>()
    noexcept;