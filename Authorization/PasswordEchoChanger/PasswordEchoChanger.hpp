#ifndef PASSWORDECHOCHANGER_HPP
#define PASSWORDECHOCHANGER_HPP

#include <QWidget>
#include <QMouseEvent>
#include <QLineEdit>

namespace Ui
{
    class PasswordEchoChanger;
}

class PasswordEchoChanger : public QWidget
{
    Q_OBJECT

public:
    explicit PasswordEchoChanger(QWidget *parent = nullptr);

    ~PasswordEchoChanger();

    void SetControllableEdit(QLineEdit* const edit);

    void mousePressEvent(QMouseEvent* event) override;

private:
    using EchoMode = QLineEdit::EchoMode;

private:
    Ui::PasswordEchoChanger *ui;

    QLineEdit* m_ControllableEdit{};
};

#endif // PASSWORDECHOCHANGER_HPP
