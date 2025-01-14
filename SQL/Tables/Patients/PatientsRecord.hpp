#ifndef PATIENTSRECORD_HPP
#define PATIENTSRECORD_HPP

#include "SQL/Manager/SQLManager.hpp"

class PatientsRecord
{
public:
    PatientsRecord();
    /*
    PatientsRecord(const PatientsRecord&) = default;
    PatientsRecord(PatientsRecord&&) = default;

    explicit PatientsRecord(const SQLManager::ID ID);

    ~PatientsRecord() = default;

    void LoadData() noexcept;

    SQLManager::ID GetID() const noexcept;


    PatientsRecord& operator = (const PatientsRecord&) noexcept = default;
    PatientsRecord& operator = (PatientsRecord&&) noexcept = default;
    */
};

#endif // PATIENTSRECORD_HPP
