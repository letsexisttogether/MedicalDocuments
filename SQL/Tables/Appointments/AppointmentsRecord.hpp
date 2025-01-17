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

    explicit AppointmentsRecord(const ID ID);
    AppointmentsRecord(const ID ID, const bool isByDoctor);
    AppointmentsRecord(const ID doctorID, const ID patientID,
        const QDate& date, const QString& diagnosis,
        const QString& recommendations);

    ~AppointmentsRecord() = default;

    void InsertData() noexcept override;

    ID GetDoctorID() const noexcept;
    ID GetPatientID() const noexcept;

    const QDate& GetDate() const noexcept;

    const QString& GetDiagnosis() const noexcept;
    const QString& GetRecommendations() const noexcept;

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
