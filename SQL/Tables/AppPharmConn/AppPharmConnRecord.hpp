#ifndef APPPHARMCONNRECORD_HPP
#define APPPHARMCONNRECORD_HPP

#include "SQL/Manager/SQLManager.hpp"
#include "SQL/Tables/DefaultRecord.hpp"

class AppPharmConnRecord : public DefaultRecord
{
public:
    AppPharmConnRecord();
    AppPharmConnRecord(const AppPharmConnRecord&) = default;
    AppPharmConnRecord(AppPharmConnRecord&&) = default;

    explicit AppPharmConnRecord(const ID ID);
    AppPharmConnRecord(const ID appointmentID, const ID pharmacyID,
        const QString& amount, const quint16 dayStreak);

    ~AppPharmConnRecord() = default;

    virtual void InsertData() noexcept override;

    const ID GetAppointmentID() const noexcept;
    const ID GetPharmacyID() const noexcept;

    const QString& GetAmount() const noexcept;

    quint16 GetDayStreak() const noexcept;

    AppPharmConnRecord& operator = (const AppPharmConnRecord&) noexcept
        = default;
    AppPharmConnRecord& operator = (AppPharmConnRecord&&) noexcept
        = default;

private:
    void SetData(const TableRecord& record) noexcept override;

private:
    ID m_AppointmentID{};
    ID m_PharmacyID{};

    QString m_Amount{};

    quint16 m_DayStreak;
};

#endif // APPPHARMCONNRECORD_HPP
