#include "PeopleRecord.hpp"

PeopleRecord::PeopleRecord()
    : DefaultRecord{ "People" }
{}

PeopleRecord::PeopleRecord(const ID ID)
    : DefaultRecord{ "People" }
{
    LoadData("ID", QString::number(ID));
}

PeopleRecord::PeopleRecord(const QString& firstName,
    const QString& lastName, const QString& patrynomic,
    const bool gender, const QDate& birthdate)
    : DefaultRecord{ "People" },
    m_FirstName{ firstName }, m_LastName{ lastName },
    m_Patrynomic{ patrynomic }, m_Gender{ gender }, m_Birthdate{ birthdate }
{}

void PeopleRecord::InsertData() noexcept
{
    const QString values
    {
        QString("'%1', '%2', '%3', %4, '%5'")
            .arg(m_FirstName)
            .arg(m_LastName)
            .arg(m_Patrynomic)
            .arg(m_Gender)
            .arg(m_Birthdate.toString("yyyy-MM-dd"))
    };

    RawInsertData(values);
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