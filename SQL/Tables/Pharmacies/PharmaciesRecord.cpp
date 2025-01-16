#include "PharmaciesRecord.hpp"

PharmaciesRecord::PharmaciesRecord()
    : DefaultRecord{ "Pharmacies" }
{}

PharmaciesRecord::PharmaciesRecord(const ID ID)
    : DefaultRecord{ "Pharmacies" }
{
    LoadData("ID", QString::number(ID));
}

const QString& PharmaciesRecord::GetTitle() const noexcept
{
    return m_Title;
}

const QString& PharmaciesRecord::GetDescription() const noexcept
{
    return m_Description;
}

void PharmaciesRecord::SetData(const TableRecord& record) noexcept
{
    m_ID = record.GetColumnValue("ID").toInt();

    m_Title = record.GetColumnValue("Title").toString();
    m_Description = record.GetColumnValue("Description").toString();
}
