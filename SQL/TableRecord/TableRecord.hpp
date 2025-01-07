#ifndef TABLERECORD_HPP
#define TABLERECORD_HPP

#include <QString>
#include <QVariant>
#include <QSet>
#include <QSqlRecord>

class TableRecord
{
public:
    TableRecord() = delete;
    TableRecord(const TableRecord&) = default;
    TableRecord(TableRecord&&) = default;

    TableRecord(QSqlRecord&& record);

    ~TableRecord() = default;

    QVariant GetColumnValue(const QString& columnName) const noexcept;
    void SetColumnValue(const QString& columnName, const QVariant& value)
        noexcept;

    TableRecord& operator = (const TableRecord&) noexcept = default;
    TableRecord& operator = (TableRecord&&) noexcept = default;

    bool CheckColumn(const QString& columnName) const noexcept;

private:
    QSqlRecord m_Record;
};

#endif // TABLERECORD_HPP
