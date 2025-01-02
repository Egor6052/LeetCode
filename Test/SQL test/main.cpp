#include <iostream>
#include <pqxx/pqxx>

void createDatabase(pqxx::connection &conn, const std::string &dbName) {
    try {
        conn.prepare("create_db", "CREATE DATABASE " + dbName);
        pqxx::nontransaction txn(conn);
        txn.exec_prepared("create_db");
        txn.commit();
        std::cout << "База даних \"" << dbName << "\" створена успішно." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Помилка створення бази даних: " << e.what() << std::endl;
    }
}


void createTable(pqxx::connection &conn, const std::string &tableName) {
    try {
        pqxx::work txn(conn);
        txn.exec("CREATE TABLE IF NOT EXISTS " + tableName + " ("
                 "id SERIAL PRIMARY KEY, "
                 "sensor_id INT NOT NULL, "
                 "current FLOAT NOT NULL, "
                 "voltage FLOAT NOT NULL, "
                 "timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP"
                 ")");
        txn.commit();
        std::cout << "Таблиця \"" << tableName << "\" створена успішно." << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Помилка створення таблиці: " << e.what() << std::endl;
    }
}

int main() {
    std::string superuserConnStr = "dbname=postgres user=Server1 password=psql";
    std::string newDbName = "sensor_data";
    std::string tableName = "measurements";

    try {
        // Підключення до PostgreSQL як суперкористувач
        pqxx::connection conn(superuserConnStr);

        // Створення бази даних
        createDatabase(conn, newDbName);

        // Підключення до нової бази даних
        std::string newDbConnStr = "dbname=" + newDbName + " user=Server1 password=psql";
        pqxx::connection newDbConn(newDbConnStr);

        // Створення таблиці в новій базі даних
        createTable(newDbConn, tableName);
    } catch (const std::exception &e) {
        std::cerr << "Загальна помилка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
