#include "PatientsRecord.hpp"

PatientsRecord::PatientsRecord()
    : DefaultRecord{ "Patients" }
{}

PatientsRecord::PatientsRecord(const ID ID)
    : DefaultRecord{ "Patients" }
{
    LoadData("ID", QString::number(ID));
}

PatientsRecord::PatientsRecord(const ID personID, const QString& email,
    const ID passwordID, const QString& phoneNumber,
    const QString& address)
    : DefaultRecord{ "Patients" },
    m_PersonID{ personID }, m_Email{ email }, m_PasswordID{ passwordID },
    m_PhoneNumber{ phoneNumber }, m_Address{ address }
{}

PatientsRecord::PatientsRecord(const QString& email)
    : DefaultRecord{ "Patients "}
{
    LoadData("Email", email);
}

void PatientsRecord::InsertData() noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString query
    {
        QString("INSERT INTO %1 VALUES (%2, '%3', %4, '%5', '%6')")
            .arg(GetTableName())
            .arg(m_PersonID)
            .arg(m_Email)
            .arg(m_PasswordID)
            .arg(m_PhoneNumber)
            .arg(m_Address)
    };

    m_ID = manager.InsertDataToTable(query);
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