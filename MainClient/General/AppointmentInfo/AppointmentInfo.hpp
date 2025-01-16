#ifndef APPOINTMENTINFO_HPP
#define APPOINTMENTINFO_HPP

#include "SQL/Tables/Appointments/AppointmentsRecord.hpp"
#include "SQL/Tables/Doctors/DoctorsRecord.hpp"
#include "SQL/Tables/People/PeopleRecord.hpp"
#include "SQL/Tables/Specializations/SpecializationsRecord.hpp"

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

    const PeopleRecord& GetPerson() const noexcept;

private:
    AppointmentsRecord m_Appointment;

    DoctorsRecord m_Doctor;
    SpecializationsRecord m_Specialization;

    PeopleRecord m_Person;
};

#endif // APPOINTMENTINFO_HPP
