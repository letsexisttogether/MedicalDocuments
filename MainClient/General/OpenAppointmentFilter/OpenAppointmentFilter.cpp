#include "OpenAppointmentFilter.hpp"

#include <QMouseEvent>

#include "MainClient/General/AppointmentFullWidget/AppointmentFullWidget.hpp"

OpenAppointmentFilter::OpenAppointmentFilter(QWidget* parent,
    const AppointmentInfo& info)
    : m_Parent{ parent }, m_AppointmentInfo{ info }
{}

bool OpenAppointmentFilter::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() != QEvent::MouseButtonPress)
    {
        return QObject::eventFilter(watched, event);
    }

    QMouseEvent* const mouseEvent = static_cast<QMouseEvent*>(event);
    if (mouseEvent->button() == Qt::LeftButton)
    {
        qDebug() << "Mouse clicked on widget using event filter";

        AppointmentFullWidget* widget = new AppointmentFullWidget
        {
            m_AppointmentInfo, m_Parent
        };

        widget->show();
    }

    return true;
}
