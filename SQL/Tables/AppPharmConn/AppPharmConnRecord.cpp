#include "AppPharmConnRecord.hpp"

AppPharmConnRecord::AppPharmConnRecord()
    : DefaultRecord{ "AppPharmConn" }
{}

AppPharmConnRecord::AppPharmConnRecord(const ID ID)
    : DefaultRecord{ "AppPharmConn" }
{
    LoadData("ID", QString::number(ID));
}

const DefaultRecord::ID AppPharmConnRecord::GetAppointmentID() const noexcept
{
    return m_AppointmentID;
}

const DefaultRecord::ID AppPharmConnRecord::GetPharmacyID() const noexcept
{
    return m_PharmacyID;
}

const QString& AppPharmConnRecord::GetAmount() const noexcept
{
    return m_Amount;
}

quint16 AppPharmConnRecord::GetDayStreak() const noexcept
{
    return m_DayStreak;
}

void AppPharmConnRecord::SetData(const TableRecord& record) noexcept
{
    m_ID = record.GetColumnValue("ID").toInt();

    m_AppointmentID = record.GetColumnValue("AppointmentID").toInt();
    m_PharmacyID = record.GetColumnValue("PharmacyID").toInt();

    m_Amount = record.GetColumnValue("Amount").toString();

    m_DayStreak = record.GetColumnValue("DayStreak").toInt();
}