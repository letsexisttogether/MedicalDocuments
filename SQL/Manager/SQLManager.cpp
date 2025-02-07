#include "SQLManager.hpp"

#include <QStringLiteral>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

void SQLManager::Init(const QString& driver, const QString& serverName,
    const QString& dbName, const QString& username, const QString& password)
    noexcept
{
    m_Instance = new SQLManager
    {
        driver, serverName, dbName,
        username, password
    };
}

SQLManager& SQLManager::GetInstance() noexcept
{
    if (!m_Instance)
    {
        qDebug() << "Attempt to get an uninitialized instance of SQLManager";
    }

    return *m_Instance;
}

SQLManager::SQLManager(const QString& driver, const QString& serverName,
    const QString& dbName, const QString& username, const QString& password)
{
    // Initialize the database with the given driver
    m_DB = QSqlDatabase::addDatabase(driver);

    // Build the connection string
    const QString connection
    {
        QStringLiteral("Driver={SQL Server};Server=%1;Database=%2;"
            "UID=%3;PWD=%4;TrustServerCertificate=True;")
        .arg(serverName, dbName, username, password)
    };

    // Set the connection string
    m_DB.setDatabaseName(connection);

    // Attempt to connect
    TryConnect();
}
SQLManager::~SQLManager()
{
    qDebug() << "Closing the connection with" << m_DB.databaseName();

    m_DB.close();
}

void SQLManager::TryConnect() noexcept
{
    m_DB.open();

    CheckConnection(true);
}

bool SQLManager::CheckConnection(const bool printError) const noexcept
{
    const QString connectionInformation
    {
        QStringLiteral("The connection to [%1]")
            .arg(m_DB.databaseName())
    };

    if (m_DB.isOpen())
    {
        qDebug() << connectionInformation << "is OPEN";

        return true;
    }

    qDebug() << connectionInformation << "is CLOSED"
        << "The last error is" << m_DB.lastError().text();

    if (printError)
    {
        qDebug() << "The last error:" << m_DB.lastError().text();
    }

    return false;
}

QList<TableRecord> SQLManager::ReadTableData(const QString& query) noexcept
{
    QList<TableRecord> data{};

    QSqlQuery sqlQuery{ m_DB };

    if (!sqlQuery.exec(query))
    {
        qDebug() << "Query was not executed. The last error:"
            << sqlQuery.lastError().text();
    }

    while (sqlQuery.next())
    {
        data.append(TableRecord{ sqlQuery.record() });
    }

    return data;
}

SQLManager::ID SQLManager::InsertDataToTable(const QString& query) noexcept
{
    QSqlQuery sqlQuery{ m_DB };

    if (!sqlQuery.exec(query))
    {
        qDebug() << "Query was not executed. The last error:"
            << sqlQuery.lastError().text();

        return 0;
    }

    const QVariant lastInsertId{ sqlQuery.lastInsertId() };
    if (lastInsertId.isValid() && lastInsertId.canConvert<ID>())
    {
        return lastInsertId.toInt();
    }

    return 0;
}