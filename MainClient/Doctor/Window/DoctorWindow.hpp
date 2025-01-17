#ifndef DOCTORCLIENTWINDOW_H
#define DOCTORCLIENTWINDOW_H

#include <QMainWindow>

#include "SQL/Tables/Doctors/DoctorsRecord.hpp"
#include "SQL/Tables/Patients/PatientsRecord.hpp"

namespace Ui
{
    class DoctorWindow;
}

class DoctorWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorWindow(const DefaultRecord::ID ID,
        QWidget *parent = nullptr);

    ~DoctorWindow();

public slots:
    void OnPatientChange();
    void OnAddAppointment();

private:
    void UpdateDoctorInformation() noexcept;

    void UpdatePatientInformation() noexcept;
    void UpdateAppointments() noexcept;
    void ClearAppointments() noexcept;

private:
    Ui::DoctorWindow* ui;

    DoctorsRecord m_Doctor;
    PatientsRecord m_Patient{};
};

#endif // DOCTORCLIENTWINDOW_H