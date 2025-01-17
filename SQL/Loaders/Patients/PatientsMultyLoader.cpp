#include "PatientsMultyLoader.hpp"

#include <QStringList>

PatientsMultyLoader::PatientsMultyLoader(const QString& fullName, const QString& birthdate)
    : MultyRecordLoader{ "People" }
{
    const QStringList names
    {
        fullName.simplified().split(' ')
    };

    if (names.isEmpty())
    {
        qDebug() << "[PatientsMultyLoader] Wrong string format";

        return;
    }

    MultipleConditionsMap map
    {
        { "FirstName", names[0] },
        { "LastName", names[1] },
        { "Patronymics", names[2] },
        { "Birthdate", birthdate }
    };

    LoadData(std::move(map));
}
