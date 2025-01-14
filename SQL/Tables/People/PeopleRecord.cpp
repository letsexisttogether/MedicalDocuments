#include "PeopleRecord.hpp"

PeopleRecord::PeopleRecord()
    : DefaultRecord{ "People" }
{}

PeopleRecord::PeopleRecord(const ID ID)
    : DefaultRecord{ "People" }
{
    LoadData("ID", QString::number(ID));
}

const QString& PeopleRecord::GetFirstName() const noexcept
{
    return m_FirstName;
}

const QString& PeopleRecord::GetLastName() const noexcept
{
    return m_LastName;
}

const QString& PeopleRecord::GetPatrynomic() const noexcept
{
    return m_Patrynomic;
}

bool PeopleRecord::GetGender() const noexcept
{
    return m_Gender;
}

const QDate& PeopleRecord::GetBirthdate() const noexcept
{
    return m_Birthdate;
}

void PeopleRecord::SetData(const TableRecord& record) noexcept
{
    m_ID = record.GetColumnValue("ID").toInt();

    m_FirstName = record.GetColumnValue("FirstName").toString();
    m_LastName = record.GetColumnValue("LastName").toString();
    m_Patrynomic = record.GetColumnValue("Patronymic").toString();

    m_Gender = record.GetColumnValue("Gender").toBool();
    m_Birthdate = record.GetColumnValue("Birthdate").toDate();
}