#ifndef PHARMACYCREATOR_HPP
#define PHARMACYCREATOR_HPP

#include <QWidget>

#include "SQL/Tables/Pharmacies/PharmaciesRecord.hpp"

namespace Ui
{
    class PharmacyCreator;
}

class PharmacyCreator : public QWidget
{
    Q_OBJECT

public:
    explicit PharmacyCreator(QWidget *parent = nullptr);

    ~PharmacyCreator();

    void InsertAppPharmConns(const DefaultRecord::ID appointmentID) noexcept;

private slots:
    void OnAddPharmacyClicked();

private:
    void FillPharmacies() noexcept;

private:
    Ui::PharmacyCreator *ui;

    QList<PharmaciesRecord> m_Pharmacies{};
};

#endif // PHARMACYCREATOR_HPP
