#include "PharmacyViewWidget.hpp"
#include "ui_PharmacyViewWidget.h"

PharmacyViewWidget::PharmacyViewWidget(PharmacyInfo&& pharmacy,
    QWidget *parent)
    : QWidget{ parent }, ui{ new Ui::PharmacyViewWidget },
    m_PharmacyInfo{ std::move(pharmacy) }
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
    const AppPharmConnRecord& appPharmConn
        = m_PharmacyInfo.GetAppPharmConn();
    const PharmaciesRecord& pharmacy
        = m_PharmacyInfo.GetPharmacy();

    ui->title->setText(pharmacy.GetTitle());
    ui->title->setToolTip(pharmacy.GetDescription());

    ui->amount->setText(appPharmConn.GetAmount());

    ui->streak->setText(QString::number(appPharmConn.GetDayStreak()));
}