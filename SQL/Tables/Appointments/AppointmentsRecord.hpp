#ifndef APPOINTMENTSRECORD_HPP
#define APPOINTMENTSRECORD_HPP

#include <QDate>

#include "SQL/Tables/DefaultRecord.hpp"

class AppointmentsRecord : public DefaultRecord
{
public:
    AppointmentsRecord();

    AppointmentsRecord(const AppointmentsRecord&) = default;
    AppointmentsRecord(AppointmentsRecord&&) = default;

    explicit AppointmentsRecord(const ID ID, const bool isByDoctor);

    ~AppointmentsRecord() = default;

    AppointmentsRecord& operator = (const AppointmentsRecord&) noexcept = default;
    AppointmentsRecord& operator = (AppointmentsRecord&&) noexcept = default;

private:
    void SetData(const TableRecord& record) noexcept override;

private:
    ID m_DoctorID{};
    ID m_PatientID{};

    QDate m_Date{};

    QString m_Diagnosis{};
    QString m_Recommendations{};
};

#endif // APPOINTMENTSRECORD_HPP
