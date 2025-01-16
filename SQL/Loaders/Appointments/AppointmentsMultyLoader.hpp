#ifndef APPOINTMENTSMULTYLOADER_HPP
#define APPOINTMENTSMULTYLOADER_HPP

#include "SQL/Loaders/MultyRecordLoader.hpp"

class AppointmentsMultyLoader : public MultyRecordLoader
{
public:
    AppointmentsMultyLoader() = delete;
    AppointmentsMultyLoader(const AppointmentsMultyLoader&) = default;
    AppointmentsMultyLoader(AppointmentsMultyLoader&&) = default;

    AppointmentsMultyLoader(const ID ID, const bool isByDoctor = false);

    ~AppointmentsMultyLoader() = default;

    AppointmentsMultyLoader& operator = (const AppointmentsMultyLoader&)
        noexcept = default;
    AppointmentsMultyLoader& operator = (AppointmentsMultyLoader&&)
        noexcept = default;
};

#endif // APPOINTMENTSMULTYLOADER_HPP
