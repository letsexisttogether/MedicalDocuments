#ifndef PATIENTAPPOINTMENT_HPP
#define PATIENTAPPOINTMENT_HPP

#include <QWidget>

namespace Ui {
class PatientAppointment;
}

class PatientAppointment : public QWidget
{
    Q_OBJECT

public:
    explicit PatientAppointment(QWidget *parent = nullptr);

    ~PatientAppointment();

private:
    Ui::PatientAppointment *ui;
};

#endif // PATIENTAPPOINTMENT_HPP
