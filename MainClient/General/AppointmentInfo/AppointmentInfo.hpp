#ifndef APPOINTMENTINFO_HPP
#define APPOINTMENTINFO_HPP

#include "SQL/Tables/Appointments/AppointmentsRecord.hpp"
#include "SQL/Tables/Doctors/DoctorsRecord.hpp"
#include "SQL/Tables/Specializations/SpecializationsRecord.hpp"
#include "SQL/Tables/Patients/PatientsRecord.hpp"
#include "SQL/Tables/People/PeopleRecord.hpp"

class AppointmentInfo
{
public:
    AppointmentInfo() = delete;
    AppointmentInfo(const AppointmentInfo&) = default;
    AppointmentInfo(AppointmentInfo&&) = default;

    AppointmentInfo(AppointmentsRecord&& appointment,
        bool isPartialLoad = true);

    ~AppointmentInfo() = default;

    const AppointmentsRecord& GetAppointment() const noexcept;

    const DoctorsRecord& GetDoctor() const noexcept;
    const SpecializationsRecord& GetSpecialization() const noexcept;

    const PatientsRecord& GetPatient() const noexcept;

    const PeopleRecord& GetDoctorPerson() const noexcept;
    const PeopleRecord& GetPatientPerson() const noexcept;

private:
    AppointmentsRecord m_Appointment;

    DoctorsRecord m_Doctor;
    SpecializationsRecord m_Specialization;

    PatientsRecord m_Patient;

    PeopleRecord m_DoctorPerson;
    PeopleRecord m_PatientPerson;
};

#endif // APPOINTMENTINFO_HPP
