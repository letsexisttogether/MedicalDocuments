#ifndef SQLMANAGER_HPP
#define SQLMANAGER_HPP

#include <QString>
#include <QSqlDatabase>
#include <QList>

#include "SQL/Tables/TableRecord.hpp"

class SQLManager
{
public:
    using ID = qint64;

public:
    static void Init(const QString& driver, const QString& serverName, const QString& dbName,
        const QString& username, const QString& password) noexcept;

    static SQLManager& GetInstance() noexcept;

public:
    QList<TableRecord> ReadTableData(const QString& query) noexcept;

    ID InsertDataToTable(const QString& query) noexcept;

    // TODO: Implement when the time comes (probably never)
    // void InsertDataToTable(const QString& tableName, TableRecord&& record) noexcept;

private:
    SQLManager() = delete;
    SQLManager(const SQLManager&) = delete;
    SQLManager(SQLManager&&) = delete;

    SQLManager(const QString& driver, const QString& serverName, const QString& dbName,
        const QString& username, const QString& password);

    ~SQLManager();

    SQLManager& operator = (const SQLManager&) noexcept = delete;
    SQLManager& operator = (SQLManager&&) noexcept = delete;

    void TryConnect() noexcept;
    bool CheckConnection(const bool printError = false) const noexcept;    

private:
    inline static SQLManager* m_Instance{};

private:
    QSqlDatabase m_DB{};
};

#endif // SQLMANAGER_HPP
