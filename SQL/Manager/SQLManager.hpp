#ifndef SQLMANAGER_HPP
#define SQLMANAGER_HPP

#include <QString>
#include <QSqlDatabase>

class SQLManager
{
public:
    static void Init(const QString& driver, const QString& serverName,
        const QString& dbName) noexcept;

    static SQLManager& GetInstance() noexcept;

private:
    SQLManager() = delete;
    SQLManager(const SQLManager&) = delete;
    SQLManager(SQLManager&&) = delete;

    SQLManager(const QString& driver, const QString& serverName,
        const QString& dbName);

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
