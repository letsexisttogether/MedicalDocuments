#include "AppointmentsMultyLoader.hpp"

AppointmentsMultyLoader::AppointmentsMultyLoader(const ID ID,
    const bool isByDoctor)
    : MultyRecordLoader{ "Appointments" }
{
    if (isByDoctor)
    {
        LoadData("DoctorID", QString::number(ID));
    }
    else
    {
        LoadData("PatientID", QString::number(ID));
    }
}