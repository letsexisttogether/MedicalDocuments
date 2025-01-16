#ifndef APPOINTMENTFULLWIDGET_HPP
#define APPOINTMENTFULLWIDGET_HPP

#include <QWidget>

#include "MainClient/General/AppointmentInfo/AppointmentInfo.hpp"

namespace Ui
{
    class AppointmentFullWidget;
}

class AppointmentFullWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AppointmentFullWidget(const AppointmentInfo& info,
        QWidget *parent = nullptr);

    ~AppointmentFullWidget();

private:
    void SetCompleteInformation() noexcept;

    void SetDoctorSpecialization() noexcept;
    void SetInfo() noexcept;
    void SetDiagnosis() noexcept;
    void SetRecommendations() noexcept;

private:
    Ui::AppointmentFullWidget *ui;

    const AppointmentInfo& m_AppointmentInfo;
};

#endif // APPOINTMENTFULLWIDGET_HPP
