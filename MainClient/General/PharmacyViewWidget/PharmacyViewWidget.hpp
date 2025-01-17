#ifndef PHARMACIEVIEWWIDGET_HPP
#define PHARMACIEVIEWWIDGET_HPP

#include <QWidget>

#include "MainClient/General/PharmacyInfo/PharmacyInfo.hpp"

namespace Ui
{
    class PharmacyViewWidget;
}

class PharmacyViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PharmacyViewWidget(PharmacyInfo&& pharmacyInfo,
        QWidget *parent = nullptr);

    ~PharmacyViewWidget();

    QSize sizeHint() const override;

private:
    void UpdateInformation() noexcept;

private:
    Ui::PharmacyViewWidget *ui;

    PharmacyInfo m_PharmacyInfo;
};

#endif // PHARMACIEVIEWWIDGET_HPP
