#include "PatientsRecord.hpp"

PatientsRecord::PatientsRecord()
    : DefaultRecord{ "Patients" }
{}

PatientsRecord::PatientsRecord(const ID ID)
    : DefaultRecord{ "Patients" }
{
    LoadData("ID", QString::number(ID));
}

PatientsRecord::PatientsRecord(const QString& email)
    : DefaultRecord{ "Patients "}
{
    LoadData("Email", email);
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

void PatientsRecord::SetData(const TableRecord& record) noexcept
{
    m_ID = record.GetColumnValue("ID").toInt();

    m_PersonID = record.GetColumnValue("PersonID").toInt();

    m_Email = record.GetColumnValue("Email").toString();
    m_PasswordID = record.GetColumnValue("PasswordID").toInt();

    m_PhoneNumber = record.GetColumnValue("PhoneNumber").toString();
    m_Address = record.GetColumnValue("Address").toString();
}