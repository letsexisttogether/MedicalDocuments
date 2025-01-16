#include "AppointmentInfo.hpp"

AppointmentInfo::AppointmentInfo(AppointmentsRecord&& appointment,
    bool isPartialLoad)
    : m_Appointment{ std::move(appointment) },
    m_Doctor{ m_Appointment.GetDoctorID() },
    m_Specialization{ m_Doctor.GetSpecializationID() },
    m_Patient{ m_Appointment.GetPatientID() },
    m_DoctorPerson{ m_Doctor.GetPersonID() },
    m_PatientPerson{ m_Patient.GetPersonID() }
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

const PatientsRecord& AppointmentInfo::GetPatient() const noexcept
{
    return m_Patient;
}

const PeopleRecord& AppointmentInfo::GetDoctorPerson() const noexcept
{
    return m_DoctorPerson;
}

const PeopleRecord& AppointmentInfo::GetPatientPerson() const noexcept
{
    return m_PatientPerson;
}