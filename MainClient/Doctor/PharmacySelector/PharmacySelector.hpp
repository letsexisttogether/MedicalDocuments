#ifndef PHARMACYSELECTOR_HPP
#define PHARMACYSELECTOR_HPP

#include <QWidget>

#include "SQL/Tables/Pharmacies/PharmaciesRecord.hpp"

namespace Ui
{
    class PharmacySelector;
}

class PharmacySelector : public QWidget
{
    Q_OBJECT

public:
    explicit PharmacySelector(const QList<PharmaciesRecord>& pharmacies,
        QWidget *parent = nullptr);

    ~PharmacySelector();

    QSize sizeHint() const override;

private:
    void FillPharmacies() noexcept;

private:
    Ui::PharmacySelector *ui;

    const QList<PharmaciesRecord> m_Pharmacies;
};

#endif // PHARMACYSELECTOR_HPP
