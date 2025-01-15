#include "AppointmentsRecord.hpp"

AppointmentsRecord::AppointmentsRecord()
    : DefaultRecord{ "Appointments" }
{}

AppointmentsRecord::AppointmentsRecord(const ID ID, const bool isByDoctor)
    : DefaultRecord{ "Appointments" }
{
    if (isByDoctor)
    {
        LoadData("DoctorID", QString::number(ID));
    }
    else
    {
        LoadData("PatientID", QString::number(ID));
    }
}

AppointmentsRecord::ID AppointmentsRecord::GetDoctorID() const noexcept
{
    return m_DoctorID;
}

AppointmentsRecord::ID AppointmentsRecord::GetPatientID() const noexcept
{
    return m_PatientID;
}

const QDate& AppointmentsRecord::GetDate() const noexcept
{
    return m_Date;
}

const QString& AppointmentsRecord::GetDiagnosis() const noexcept
{
    return m_Diagnosis;
}

const QString& AppointmentsRecord::GetRecommendations() const noexcept
{
    return m_Recommendations;
}

void AppointmentsRecord::SetData(const TableRecord& record) noexcept
{
    m_ID = record.GetColumnValue("ID").toInt();

    m_DoctorID = record.GetColumnValue("DoctorID").toInt();
    m_PatientID = record.GetColumnValue("PatientID").toInt();

    m_Date = record.GetColumnValue("Date").toDate();

    m_Diagnosis = record.GetColumnValue("Diagnosis").toString();
    m_Recommendations = record.GetColumnValue("Recommendations").toString();
}