#ifndef PHARMACYMULTYLOADER_HPP
#define PHARMACYMULTYLOADER_HPP

#include "SQL/Loaders/MultyRecordLoader.hpp"

class PharmacyMultyLoader : public MultyRecordLoader
{
public:
    PharmacyMultyLoader();

    PharmacyMultyLoader(const PharmacyMultyLoader &) = default;
    PharmacyMultyLoader(PharmacyMultyLoader &&) = default;

    ~PharmacyMultyLoader() = default;

    PharmacyMultyLoader& operator = (const PharmacyMultyLoader &) noexcept
        = default;
    PharmacyMultyLoader& operator = (PharmacyMultyLoader &&) noexcept
        = default;

};
#endif // PHARMACYMULTYLOADER_HPP
