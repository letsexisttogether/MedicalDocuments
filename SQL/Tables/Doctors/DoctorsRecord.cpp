#include "DoctorsRecord.hpp"

DoctorsRecord::DoctorsRecord()
    : DefaultRecord{ "Doctors"}
{}

DoctorsRecord::DoctorsRecord(const ID ID)
    : DefaultRecord{ "Doctors"}
{
    LoadData("ID", QString::number(ID));
}

DoctorsRecord::DoctorsRecord(const QString& specialCode)
    : DefaultRecord{ "Doctors"}
{
    LoadData("SpecialCode", specialCode);
}

DoctorsRecord::ID DoctorsRecord::GetPersonID() const noexcept
{
    return m_PersonID;
}

DoctorsRecord::ID DoctorsRecord::GetSpecializationID() const noexcept
{
    return m_SpecializationID;
}

const QString& DoctorsRecord::SpecialCode() const noexcept
{
    return m_SpecialCode;
}

DoctorsRecord::ID DoctorsRecord::GetPasswordID() const noexcept
{
    return m_PasswordID;
}

quint16 DoctorsRecord::GetWorkExperience() const noexcept
{
    return	m_WorkExperience;
}

void DoctorsRecord::SetData(const TableRecord& record) noexcept
{
    m_ID = record.GetColumnValue("ID").toInt();

    m_PersonID = record.GetColumnValue("PersonID").toInt();
    m_SpecializationID = record.GetColumnValue("SpecializationID").toInt();

    m_SpecialCode = record.GetColumnValue("SpecialCode").toString();
    m_PasswordID = record.GetColumnValue("PasswordID").toInt();

    m_WorkExperience =record.GetColumnValue("WorkExperience").toInt();
}