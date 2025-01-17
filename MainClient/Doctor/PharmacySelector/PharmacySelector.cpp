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

void PharmacySelector::InsertAppPharmConn
    (const DefaultRecord::ID appointmentID) const noexcept
{
    qsizetype currentIndex = ui->pharmacyComboBox->currentIndex();

    AppPharmConnRecord appPharmConn
    {
        appointmentID,
        m_Pharmacies[currentIndex].GetID(),
        ui->amount->toPlainText(),
        ui->streak->text().toUShort()
    };

    appPharmConn.InsertData();
}

QSize PharmacySelector::sizeHint() const
{
    return { width(), height() };
}

void PharmacySelector::FillPharmacies() noexcept
{
    for (const auto& pharmacy : m_Pharmacies)
    {
        ui->pharmacyComboBox->addItem(pharmacy.GetTitle());
    }
}
