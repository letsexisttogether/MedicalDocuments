#ifndef MULTYRECORDLOADER_H
#define MULTYRECORDLOADER_H

#include "SQL/Tables/Appointments/AppointmentsRecord.hpp"

class MultyRecordLoader
{
public:
    using ID = DefaultRecord::ID;

public:
    MultyRecordLoader() = delete;
    MultyRecordLoader(const MultyRecordLoader&) = default;
    MultyRecordLoader(MultyRecordLoader&&) = default;

    MultyRecordLoader(const ID ID, const bool isByDoctor);

    ~MultyRecordLoader() = default;

    template <class _Record>
    _Record GetCurrent() noexcept;

    const qsizetype GetCount() const noexcept;

    MultyRecordLoader& operator = (const MultyRecordLoader&) = default;
    MultyRecordLoader& operator = (MultyRecordLoader&&) = default;

private:
    void LoadData(const QString& column, const QString& value) noexcept;

private:
    qsizetype m_Current{};

    QList<TableRecord> m_Records{};
};

#endif // MULTYRECORDLOADER_H
