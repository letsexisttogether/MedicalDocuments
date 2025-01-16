#include "PharmacyViewWidget.hpp"
#include "ui_PharmacyViewWidget.h"

PharmacyViewWidget::PharmacyViewWidget(const PharmaciesRecord& pharmacy,
    QWidget *parent)
    : QWidget{ parent }, ui{ new Ui::PharmacyViewWidget },
    m_Pharmacy{ pharmacy }
{
    ui->setupUi(this);

    UpdateInformation();
}

PharmacyViewWidget::~PharmacyViewWidget()
{
    delete ui;
}

QSize PharmacyViewWidget::sizeHint() const
{
    return { width(), height() };
}

void PharmacyViewWidget::UpdateInformation() noexcept
{

}