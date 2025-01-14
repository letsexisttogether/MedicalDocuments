#ifndef PEOPLERECORD_HPP
#define PEOPLERECORD_HPP

#include <QDate>

#include "SQL/Manager/SQLManager.hpp"
#include "SQL/Tables/DefaultRecord.hpp"

class PeopleRecord : public DefaultRecord
{
public:
    PeopleRecord() = delete;
    PeopleRecord(const PeopleRecord&) = default;
    PeopleRecord(PeopleRecord&&) = default;

    explicit PeopleRecord(const SQLManager::ID ID);

    ~PeopleRecord() = default;

    void LoadData() noexcept;

    const QString& GetFirstName() const noexcept;
    const QString& GetLastName() const noexcept;
    const QString& GetPatrynomic() const noexcept;

    bool GetGender() const noexcept;
    const QDate& GetBirthdate() const noexcept;

    PeopleRecord& operator = (const PeopleRecord&) noexcept = default;
    PeopleRecord& operator = (PeopleRecord&&) noexcept = default;

private:
    QString m_FirstName{};
    QString m_LastName{};
    QString m_Patrynomic{};

    bool m_Gender{ true };
    QDate m_Birthdate{};
};

#endif // PEOPLERECORD_HPP
