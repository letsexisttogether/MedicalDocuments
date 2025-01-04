#ifndef SQLMANAGER_HPP
#define SQLMANAGER_HPP

#include <QString>
#include <QSqlDatabase>

class SQLManager
{
public:
    SQLManager();
    SQLManager(const QString& driver, const QString& serverName,
        const QString& dbName);

    ~SQLManager();

private:
    void TryConnect() noexcept;

    void CheckConnection(const bool printError = false) const noexcept;

private:
    QSqlDatabase m_DB{};
};

#endif // SQLMANAGER_HPP
