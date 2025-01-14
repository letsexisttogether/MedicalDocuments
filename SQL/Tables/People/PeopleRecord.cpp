#include "PeopleRecord.hpp"

PeopleRecord::PeopleRecord(const SQLManager::ID ID)
    : DefaultRecord{ ID, "People" }
{
    LoadData();
}

void PeopleRecord::LoadData() noexcept
{
    const TableRecord& person{ LoadRawData() };

    m_FirstName = person.GetColumnValue("FirstName").toString();
    m_LastName = person.GetColumnValue("LastName").toString();
    m_Patrynomic = person.GetColumnValue("Patronymic").toString();

    m_Gender = person.GetColumnValue("Gender").toBool();
    m_Birthdate = person.GetColumnValue("Birthdate").toDate();
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