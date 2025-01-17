#ifndef PATIENTSMULTYLOADER_HPP
#define PATIENTSMULTYLOADER_HPP

#include "SQL/Loaders/MultyRecordLoader.hpp"

class PatientsMultyLoader : public MultyRecordLoader
{
public:
    PatientsMultyLoader() = delete;

    PatientsMultyLoader(const QString& fullName, const QString& birthdate);

    ~PatientsMultyLoader() = default;
};

#endif // PATIENTSMULTYLOADER_HPP
