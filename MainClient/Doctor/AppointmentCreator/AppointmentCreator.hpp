#ifndef APPOINTMENTCREATOR_HPP
#define APPOINTMENTCREATOR_HPP

#include <QMainWindow>

#include "SQL/Tables/Patients/PatientsRecord.hpp"
#include "SQL/Tables/Doctors/DoctorsRecord.hpp"

namespace Ui
{
    class AppointmentCreator;
}

class AppointmentCreator : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppointmentCreator(const PatientsRecord& patient,
        const DoctorsRecord& doctor, QWidget *parent = nullptr);

    ~AppointmentCreator();

private slots:
    void OnSaveClicked();
    void OnDeclineClicked();

private:
    void SetCompleteInformation() noexcept;

    void SetDoctorSpecialization() noexcept;
    void SetKnownInformation() noexcept;

private:
    Ui::AppointmentCreator *ui;

    const DoctorsRecord& m_Doctor;
    const PatientsRecord& m_Patient;
};

#endif // APPOINTMENTCREATOR_HPP
