#include "SpecializationsRecord.hpp"

SpecializationsRecord::SpecializationsRecord()
    : DefaultRecord{ "Specializations" }
{}

SpecializationsRecord::SpecializationsRecord(const ID ID)
    : DefaultRecord{ "Specializations" }
{
    LoadData("ID", QString::number(ID));
}

const QString& SpecializationsRecord::GetTitle() const noexcept
{
    return m_Title;
}

const QString& SpecializationsRecord::GetDescription() const noexcept
{
    return m_Description;
}

void SpecializationsRecord::SetData(const TableRecord& record) noexcept
{
    m_ID = record.GetColumnValue("ID").toInt();

    m_Title = record.GetColumnValue("Title").toString();
    m_Description = record.GetColumnValue("Description").toString();
}