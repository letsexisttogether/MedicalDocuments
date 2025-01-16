#ifndef PATIENTAPPOINTMENT_HPP
#define PATIENTAPPOINTMENT_HPP

#include <QWidget>
#include <QMouseEvent>

#include "MainClient/General/AppointmentInfo/AppointmentInfo.hpp"

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

    QSize sizeHint() const override
    {
        return { width(), height() };
    }

private:
    void SetInformation() noexcept;

private:
    Ui::PatientAppointment *ui;

    AppointmentInfo m_AppointmentInfo;
};

#endif // PATIENTAPPOINTMENT_HPP
