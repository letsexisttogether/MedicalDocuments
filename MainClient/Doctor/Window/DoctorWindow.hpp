#ifndef DOCTORCLIENTWINDOW_H
#define DOCTORCLIENTWINDOW_H

#include <QMainWindow>

#include "SQL/Tables/Doctors/DoctorsRecord.hpp"

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

    QMap<QString, QVector<QString>> TestData;

public slots:
    void OnPatientChange(const QString &current_patient);

private:
    void SetBIO() noexcept;

private:
    Ui::DoctorWindow* ui;

    DoctorsRecord m_Doctor;
};

#endif // DOCTORCLIENTWINDOW_H