#ifndef MULTYRECORDLOADER_H
#define MULTYRECORDLOADER_H

#include <QMap>

#include "SQL/Tables/DefaultRecord.hpp"

class MultyRecordLoader
{
public:
    using ID = DefaultRecord::ID;
    using MultipleConditionsMap = QMap<QString, QString>;

public:
    MultyRecordLoader() = delete;
    MultyRecordLoader(const MultyRecordLoader&) = default;
    MultyRecordLoader(MultyRecordLoader&&) = default;

    explicit MultyRecordLoader(QString&& tableName);

    ~MultyRecordLoader() = default;

    template <class _Record>
    _Record GetCurrent() noexcept;

    const qsizetype GetCount() const noexcept;

    MultyRecordLoader& operator = (const MultyRecordLoader&) = default;
    MultyRecordLoader& operator = (MultyRecordLoader&&) = default;

protected:
    void LoadData() noexcept;
    void LoadData(const QString& column, const QString& value) noexcept;
    void LoadData(MultipleConditionsMap&& conditions) noexcept;

private:
    void LoadRawData(const QString& query) noexcept;

private:
    QString m_TableName;

    qsizetype m_Current{};
    QList<TableRecord> m_Records{};
};

#endif // MULTYRECORDLOADER_H
