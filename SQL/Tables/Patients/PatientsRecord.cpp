#include "PatientsRecord.hpp"

PatientsRecord::PatientsRecord(const ID ID)
    : DefaultRecord{ ID, "Patients" }
{
    LoadData();
}

DefaultRecord::ID PatientsRecord::GetPersonID() const
{
    return m_PersonID;
}

const QString& PatientsRecord::GetEmail() const
{
    return m_Email;
}

DefaultRecord::ID PatientsRecord::GetPasswordID() const
{
    return m_PasswordID;
}

const QString& PatientsRecord::GetPhoneNumber() const
{
    return m_PhoneNumber;
}

const QString& PatientsRecord::GetAddress() const
{
    return m_Address;
}

void PatientsRecord::LoadData() noexcept
{
    const TableRecord patient{ LoadRawData() };

    m_PersonID = patient.GetColumnValue("PersonID").toInt();

    m_Email = patient.GetColumnValue("Email").toString();
    m_PasswordID = patient.GetColumnValue("PasswordID").toInt();

    m_PhoneNumber = patient.GetColumnValue("PhoneNumber").toString();
    m_Address = patient.GetColumnValue("Address").toString();
}
