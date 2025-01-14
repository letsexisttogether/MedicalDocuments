#ifndef DOCTORCLIENTWINDOW_H
#define DOCTORCLIENTWINDOW_H

#include <QMainWindow>

namespace Ui
{
    class DoctorWindow;
}

class DoctorWindow: public QMainWindow
{
    Q_OBJECT

public:
    explicit DoctorWindow(QWidget *parent = nullptr);
    ~DoctorWindow();

    QMap<QString, QVector<QString>> TestData;

public slots:
    void OnPatientChange(const QString &current_patient);

private:
    Ui::DoctorWindow* ui;
};

#endif // DOCTORCLIENTWINDOW_H