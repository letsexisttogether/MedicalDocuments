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

private:
    AppPharmConnRecord m_AppPharmConn;
    PharmaciesRecord m_Pharmacy;
};

#endif // PHARMACYINFO_HPP
