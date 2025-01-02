#ifndef APPOINTMENTWINDOW_H
#define APPOINTMENTWINDOW_H

#include <QMainWindow>

namespace Ui {
class AppointmentWindow;
}

class AppointmentWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppointmentWindow(QWidget *parent = nullptr);
    ~AppointmentWindow();

private:
    Ui::AppointmentWindow *ui;
};

#endif // APPOINTMENTWINDOW_H
