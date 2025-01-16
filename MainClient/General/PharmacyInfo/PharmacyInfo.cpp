#include "PharmacyInfo.hpp"

PharmacyInfo::PharmacyInfo(AppPharmConnRecord&& appPharmConn)
    : m_AppPharmConn{ std::move(appPharmConn) },
    m_Pharmacy{ m_AppPharmConn.GetPharmacyID() }
{}

const AppPharmConnRecord& PharmacyInfo::GetAppPharmConn() const noexcept
{
    return m_AppPharmConn;
}

const PharmaciesRecord& PharmacyInfo::GetPharmacy() const noexcept
{
    return m_Pharmacy;
}
