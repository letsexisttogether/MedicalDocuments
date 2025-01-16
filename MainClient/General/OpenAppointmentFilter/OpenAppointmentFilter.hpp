#ifndef OPENAPPOINTMENTFILTER_HPP
#define OPENAPPOINTMENTFILTER_HPP

#include <QObject>
#include <QEvent>

#include "MainClient/General/AppointmentInfo/AppointmentInfo.hpp"

class OpenAppointmentFilter : public QObject
{
    Q_OBJECT

public:
    OpenAppointmentFilter() = delete;

    OpenAppointmentFilter(QWidget* const parent, const AppointmentInfo& info);
    // OpenAppointmentFilter()

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QWidget* const m_Parent;
    const AppointmentInfo& m_AppointmentInfo;
};

#endif // OPENAPPOINTMENTFILTER_HPP
