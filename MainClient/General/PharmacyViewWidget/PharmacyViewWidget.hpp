#ifndef PHARMACIEVIEWWIDGET_HPP
#define PHARMACIEVIEWWIDGET_HPP

#include <QWidget>

#include "SQL/Tables/Pharmacies/PharmaciesRecord.hpp"

namespace Ui
{
    class PharmacyViewWidget;
}

class PharmacyViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PharmacyViewWidget(const PharmaciesRecord& pharmacy,
        QWidget *parent = nullptr);

    ~PharmacyViewWidget();

    QSize sizeHint() const override;

private:
    void UpdateInformation() noexcept;

private:
    Ui::PharmacyViewWidget *ui;

    const PharmaciesRecord m_Pharmacy;
};

#endif // PHARMACIEVIEWWIDGET_HPP
