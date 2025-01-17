#include "PharmacySelector.hpp"
#include "ui_PharmacySelector.h"

PharmacySelector::PharmacySelector(const QList<PharmaciesRecord>& pharmacies,
    QWidget *parent)
    : QWidget{ parent }, ui{ new Ui::PharmacySelector },
    m_Pharmacies{ pharmacies }
{
    ui->setupUi(this);

    FillPharmacies();
}

PharmacySelector::~PharmacySelector()
{
    delete ui;
}

void PharmacySelector::FillPharmacies() noexcept
{
    for (const auto& pharmacy : m_Pharmacies)
    {
        ui->pharmacyComboBox->addItem(pharmacy.GetTitle());
    }
}

QSize PharmacySelector::sizeHint() const
{
    return { width(), height() };
}