#include "AppointmentsRecord.hpp"

AppointmentsRecord::AppointmentsRecord()
    : DefaultRecord{ "Appointments" }
{}

AppointmentsRecord::AppointmentsRecord(const ID ID, const bool isByDoctor)
    : DefaultRecord{ "Appointments" }
{}

void AppointmentsRecord::SetData(const TableRecord& record) noexcept
{
    m_ID = record.GetColumnValue("ID").toInt();

    m_DoctorID = record.GetColumnValue("DoctorID").toInt();
    m_PatientID = record.GetColumnValue("PatientID").toInt();

    m_Date = record.GetColumnValue("Date").toDate();

    m_Diagnosis = record.GetColumnValue("Diagnosis").toString();
    m_Recommendations = record.GetColumnValue("Recommendations").toString();
}