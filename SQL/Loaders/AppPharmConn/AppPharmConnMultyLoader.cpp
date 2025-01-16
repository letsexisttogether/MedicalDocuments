#include "AppPharmConnMultyLoader.hpp"

AppPharmConnMultyLoader::AppPharmConnMultyLoader(const ID ID,
    const bool isByAppointment)
    : MultyRecordLoader{ "AppPharmConn" }
{
    if (isByAppointment)
    {
        LoadData("AppointmentID", QString::number(ID));
    }
    else
    {
        LoadData("PharmacyID", QString::number(ID));
    }
}

