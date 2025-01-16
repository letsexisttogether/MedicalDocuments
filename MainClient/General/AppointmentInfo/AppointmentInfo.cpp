#include "AppointmentInfo.hpp"

AppointmentInfo::AppointmentInfo(AppointmentsRecord&& appointment,
    bool isPartialLoad)
    : m_Appointment{ std::move(appointment) },
    m_Doctor{ appointment.GetDoctorID() },
    m_Specialization{ m_Doctor.GetSpecializationID() },
    m_Person{ m_Doctor.GetPersonID() }
{}

const AppointmentsRecord& AppointmentInfo::GetAppointment() const noexcept
{
    return m_Appointment;
}

const DoctorsRecord& AppointmentInfo::GetDoctor() const noexcept
{
    return m_Doctor;
}
const SpecializationsRecord& AppointmentInfo::GetSpecialization()
    const noexcept
{
    return m_Specialization;
}

const PeopleRecord& AppointmentInfo::GetPerson() const noexcept
{
    return m_Person;
}