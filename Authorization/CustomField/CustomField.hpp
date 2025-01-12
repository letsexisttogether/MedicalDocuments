#ifndef CUSTOMFIELD_HPP
#define CUSTOMFIELD_HPP

#include <QWidget>
#include <QLineEdit>
#include <memory>

#include "Authorization/FieldCheck/FieldChecker.hpp"

namespace Ui
{
    class CustomField;
}

class CustomField : public QWidget
{
    Q_OBJECT

public:
    explicit CustomField(QWidget *parent = nullptr);

    ~CustomField();

    bool CheckEdit() noexcept;

    void SetName(const QString& name) noexcept;

    QString GetEditValue() const noexcept;
    void ClearEditValue() noexcept;

    void SetEchoMode(const QLineEdit::EchoMode echoMode) noexcept;

    void SetErrorMessage(const QString& message) noexcept;

    void SetChecker(FieldChecker* const editChecker) noexcept;

protected:
    Ui::CustomField *ui;

    std::unique_ptr<FieldChecker> m_EditChecker{};
};

#endif // CUSTOMFIELD_HPP
