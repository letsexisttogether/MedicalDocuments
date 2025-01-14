#ifndef PATIENTSRECORD_HPP
#define PATIENTSRECORD_HPP

#include "SQL/Manager/SQLManager.hpp"
#include "SQL/Tables/DefaultRecord.hpp"

class PatientsRecord : public DefaultRecord
{
public:
    PatientsRecord();

    PatientsRecord(const PatientsRecord&) = default;
    PatientsRecord(PatientsRecord&&) = default;

    explicit PatientsRecord(const ID ID);
    explicit PatientsRecord(const QString& email);

    ~PatientsRecord() = default;

    ID GetPersonID() const;

    const QString& GetEmail() const;
    ID GetPasswordID() const;

    const QString& GetPhoneNumber() const;
    const QString& GetAddress() const;

    PatientsRecord& operator = (const PatientsRecord&) noexcept = default;
    PatientsRecord& operator = (PatientsRecord&&) noexcept = default;

private:
    void SetData(const TableRecord& table) noexcept override;

private:
    ID m_PersonID{};

    QString m_Email{};
    ID m_PasswordID{};

    QString m_PhoneNumber{};
    QString m_Address{};
};

#endif // PATIENTSRECORD_HPP