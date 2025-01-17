#include "AppPharmConnRecord.hpp"

AppPharmConnRecord::AppPharmConnRecord()
    : DefaultRecord{ "AppPharmConn" }
{}

AppPharmConnRecord::AppPharmConnRecord(const ID ID)
    : DefaultRecord{ "AppPharmConn" }
{
    LoadData("ID", QString::number(ID));
}

AppPharmConnRecord::AppPharmConnRecord(const ID appointmentID,
    const ID pharmacyID, const QString& amount, const quint16 dayStreak)
    : DefaultRecord{ "AppPharmConn" }, m_AppointmentID{ appointmentID },
    m_PharmacyID{ pharmacyID }, m_Amount{ amount },
    m_DayStreak{ dayStreak }
{}

void AppPharmConnRecord::InsertData() noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString query
    {
        QString("INSERT INTO %1 VALUES (%2, %3, '%4', %5)")
            .arg(GetTableName())
            .arg(m_AppointmentID)
            .arg(m_PharmacyID)
            .arg(m_Amount)
            .arg(m_DayStreak)
    };

    m_ID = manager.InsertDataToTable(query);
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