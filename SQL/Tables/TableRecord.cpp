#include "TableRecord.hpp"

TableRecord::TableRecord(QSqlRecord&& record)
    : m_Record{ record }
{}

QVariant TableRecord::GetColumnValue(const QString& columnName) const noexcept
{
    if (CheckColumn(columnName))
    {
        return m_Record.value(columnName);
    }

    return QVariant{};
}

void TableRecord::SetColumnValue(const QString& columnName,
    const QVariant& value) noexcept
{
    if (CheckColumn(columnName))
    {
        const qint32 columnIndex = m_Record.indexOf(columnName);
        m_Record.setValue(columnIndex, value);
    }
}

bool TableRecord::CheckColumn(const QString& columnName) const noexcept
{
    if (m_Record.contains(columnName))
    {
        return true;
    }

    qWarning() << "Column" << columnName << "does not exist.";

    return false;
}

bool TableRecord::IsEmpty() const noexcept
{
    return m_Record.isEmpty();
}
