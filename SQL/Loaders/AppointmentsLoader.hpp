#ifndef APPOINTMENTSLOADER_HPP
#define APPOINTMENTSLOADER_HPP

#include "SQL/Tables/Appointments/AppointmentsRecord.hpp"

class AppointmentsLoader
{
public:
    using ID = DefaultRecord::ID;

public:
    AppointmentsLoader() = delete;
    AppointmentsLoader(const AppointmentsLoader&) = default;
    AppointmentsLoader(AppointmentsLoader&&) = default;

    AppointmentsLoader(const ID ID, const bool isByDoctor);

    ~AppointmentsLoader() = default;

    AppointmentsRecord GetCurrent() noexcept;

    const qsizetype GetCount() const noexcept;

    AppointmentsLoader& operator = (const AppointmentsLoader&) = default;
    AppointmentsLoader& operator = (AppointmentsLoader&&) = default;

private:
    void LoadData(const QString& column, const QString& value) noexcept;

private:
    qsizetype m_Current{};

    QList<TableRecord> m_Appointments{};
};

#endif // APPOINTMENTSLOADER_HPP
