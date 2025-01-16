#ifndef APPPHARMCONNMULTYLOADER_HPP
#define APPPHARMCONNMULTYLOADER_HPP

#include "SQL/Loaders/MultyRecordLoader.hpp"

class AppPharmConnMultyLoader : public MultyRecordLoader
{
public:
    AppPharmConnMultyLoader() = delete;
    AppPharmConnMultyLoader(const AppPharmConnMultyLoader&) = default;
    AppPharmConnMultyLoader(AppPharmConnMultyLoader&&) = default;

    AppPharmConnMultyLoader(const ID ID, const bool isByAppointment = false);

    ~AppPharmConnMultyLoader() = default;

    AppPharmConnMultyLoader& operator = (const AppPharmConnMultyLoader&)
        noexcept = default;
    AppPharmConnMultyLoader& operator = (AppPharmConnMultyLoader&&)
        noexcept = default;
};

#endif // APPPHARMCONNMULTYLOADER_HPP
