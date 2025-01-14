#ifndef DOCTORSRECORD_HPP
#define DOCTORSRECORD_HPP

#include "SQL/Tables/DefaultRecord.hpp"

class DoctorsRecord : public DefaultRecord
{
public:
    DoctorsRecord();
    DoctorsRecord(const DoctorsRecord&) = default;
    DoctorsRecord(DoctorsRecord&&) = default;

    DoctorsRecord(const ID ID);
    DoctorsRecord(const QString& specialCode);

    ~DoctorsRecord() = default;

    ID GetPersonID() const noexcept;
    ID GetSpecializationID() const noexcept;

    const QString& SpecialCode() const noexcept;
    ID GetPasswordID() const noexcept;

    quint16 GetWorkExperience() const noexcept;

    DoctorsRecord& operator = (const DoctorsRecord&) noexcept = default;
    DoctorsRecord& operator = (DoctorsRecord&&) noexcept = default;

private:
    void SetData(const TableRecord& record) noexcept override;

private:
    ID m_PersonID{};
    ID m_SpecializationID{};

    QString m_SpecialCode{};
    ID m_PasswordID{};

    quint16 m_WorkExperience{};
};

#endif // DOCTORSRECORD_HPP
