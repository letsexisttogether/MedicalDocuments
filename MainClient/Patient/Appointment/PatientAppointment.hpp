#ifndef PATIENTAPPOINTMENT_HPP
#define PATIENTAPPOINTMENT_HPP

#include <QWidget>

#include "SQL/Tables/Appointments/AppointmentsRecord.hpp"

namespace Ui
{
class PatientAppointment;
}

class PatientAppointment : public QWidget
{
    Q_OBJECT

public:
    explicit PatientAppointment(AppointmentsRecord&& appointment,
        QWidget* parent = nullptr);

    explicit PatientAppointment(const DefaultRecord::ID ID,
        const bool isByDoctor, QWidget* parent = nullptr);

    ~PatientAppointment();

private:
    void SetInformation() noexcept;

private:
    Ui::PatientAppointment *ui;

    AppointmentsRecord m_Appointment;
};

#endif // PATIENTAPPOINTMENT_HPP
