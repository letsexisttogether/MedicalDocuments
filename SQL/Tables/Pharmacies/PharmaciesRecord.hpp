#ifndef PHARMACIESRECORD_HPP
#define PHARMACIESRECORD_HPP

#include "SQL/Manager/SQLManager.hpp"
#include "SQL/Tables/DefaultRecord.hpp"

class PharmaciesRecord : public DefaultRecord
{
public:
    PharmaciesRecord();
    PharmaciesRecord(const PharmaciesRecord&) = default;
    PharmaciesRecord(PharmaciesRecord&&) = default;

    explicit PharmaciesRecord(const ID ID);

    ~PharmaciesRecord() = default;

    const QString& GetTitle() const noexcept;
    const QString& GetDescription() const noexcept;

    PharmaciesRecord& operator = (const PharmaciesRecord&) noexcept = default;
    PharmaciesRecord& operator = (PharmaciesRecord &&) noexcept = default;

private:
    void SetData(const TableRecord& record) noexcept override;

private:
    QString m_Title{};
    QString m_Description{};
};

#endif // PHARMACIESRECORD_HPP
