#ifndef PHARMACYINFO_HPP
#define PHARMACYINFO_HPP

#include "SQL/Tables/AppPharmConn/AppPharmConnRecord.hpp"
#include "SQL/Tables/Pharmacies/PharmaciesRecord.hpp"

class PharmacyInfo
{
public:
    PharmacyInfo() = delete;
    PharmacyInfo(const PharmacyInfo&) = default;
    PharmacyInfo(PharmacyInfo&&) = default;

    PharmacyInfo(AppPharmConnRecord&& appPharmConn);

    ~PharmacyInfo() = default;

    const AppPharmConnRecord& GetAppPharmConn() const noexcept;
    const PharmaciesRecord& GetPharmacy() const noexcept;

private:
    AppPharmConnRecord m_AppPharmConn;
    PharmaciesRecord m_Pharmacy;
};

#endif // PHARMACYINFO_HPP
