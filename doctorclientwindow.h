#ifndef DOCTORCLIENTWINDOW_H
#define DOCTORCLIENTWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class DoctorClientWindow;
}

class DoctorClientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorClientWindow(QWidget *parent = nullptr);
    ~DoctorClientWindow();

    QMap<QString, QVector<QString>> TestData;

public slots:
    void OnPatientChange(const QString &current_patient);

private:
    Ui::DoctorClientWindow *ui;


};

#endif // DOCTORCLIENTWINDOW_H
