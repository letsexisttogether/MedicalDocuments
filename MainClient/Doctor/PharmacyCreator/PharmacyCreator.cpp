#include "PharmacyCreator.hpp"
#include "ui_PharmacyCreator.h"

#include "MainClient/Doctor/PharmacySelector/PharmacySelector.hpp"
#include "SQL/Loaders/Pharmacies/PharmacyMultyLoader.hpp"

PharmacyCreator::PharmacyCreator(QWidget *parent)
    : QWidget{ parent }, ui{ new Ui::PharmacyCreator }
{
    ui->setupUi(this);

    connect(ui->addPharmacy, &QPushButton::clicked, this,
        &PharmacyCreator::OnAddPharmacyClicked);

    FillPharmacies();
}

PharmacyCreator::~PharmacyCreator()
{
    delete ui;
}

void PharmacyCreator::OnAddPharmacyClicked()
{
    QVBoxLayout* const verticalLayout = ui->pharmacies;
    verticalLayout->setAlignment(Qt::AlignTop);

    QWidget* const widget = ui->scrollArea->widget();

    verticalLayout->addWidget(new PharmacySelector
    {
        m_Pharmacies,
        widget
    });
}

void PharmacyCreator::FillPharmacies() noexcept
{
    PharmacyMultyLoader loader{};

    for (qsizetype i = 0; i < loader.GetCount(); ++i)
    {
        m_Pharmacies.append(loader.GetCurrent<PharmaciesRecord>());
    }
}