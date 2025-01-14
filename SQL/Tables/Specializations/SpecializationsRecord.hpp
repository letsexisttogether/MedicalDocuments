#ifndef SPECIALIZATIONSRECORD_HPP
#define SPECIALIZATIONSRECORD_HPP

#include "SQL/Tables/DefaultRecord.hpp"

class SpecializationsRecord : public DefaultRecord
{
public:
    SpecializationsRecord();
    SpecializationsRecord(const SpecializationsRecord&) = default;
    SpecializationsRecord(SpecializationsRecord&&) = default;

    SpecializationsRecord(const ID ID);

    ~SpecializationsRecord() = default;

    const QString& GetTitle() const noexcept;
    const QString& GetDescription() const noexcept;

    SpecializationsRecord& operator = (const SpecializationsRecord&)
        noexcept = default;
    SpecializationsRecord& operator = (SpecializationsRecord&&)
        noexcept = default;

private:
    void SetData(const TableRecord& table) noexcept override;

private:
    QString m_Title{};
    QString m_Description{};
};

#endif // SPECIALIZATIONSRECORD_HPP
