#include "AppointmentsLoader.hpp"

AppointmentsLoader::AppointmentsLoader(const DefaultRecord::ID ID,
    const bool isByDoctor)
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

AppointmentsRecord AppointmentsLoader::GetCurrent() noexcept
{
    const ID ID = m_Appointments.at(m_Current)
        .GetColumnValue("ID").toInt();

    const AppointmentsRecord appointment
    {
       AppointmentsRecord{ ID }
    };

    m_Current += ((m_Current + 1) < m_Appointments.count());

    return appointment;
}

const qsizetype AppointmentsLoader::GetCount() const noexcept
{
    return m_Appointments.count();
}

void AppointmentsLoader::LoadData(const QString& column,
    const QString& value) noexcept
{
    SQLManager& manager{ SQLManager::GetInstance() };

    const QString query
    {
        QString("SELECT ID FROM Appointments "
                "WHERE %1 = '%2'")
            .arg(column)
            .arg(value)
    };

    qDebug() << query;

    m_Appointments = manager.ReadTableData(query);

    if (m_Appointments.isEmpty())
    {
        qWarning() << "Table \"Appointments\""
            << "does not contain any data";
    }
}