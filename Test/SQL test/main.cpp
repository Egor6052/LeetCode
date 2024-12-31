#include <pqxx/pqxx>
#include <iostream>

void createDatabase(const std::string &dbName, const std::string &user, const std::string &password) {
    try {
        // Підключення до бази даних 'postgres'
        pqxx::connection conn("dbname=postgres user=" + user + " password=" + password);
        if (conn.is_open()) {
            std::cout << "Підключено до системної бази даних 'postgres'.\n";
        } else {
            std::cerr << "Не вдалося підключитися до бази даних.\n";
            return;
        }

        // Створення бази даних
        pqxx::work txn(conn);
        txn.exec("CREATE DATABASE " + dbName);
        txn.commit();

        std::cout << "Базу даних '" << dbName << "' успішно створено!\n";
    } catch (const std::exception &e) {
        std::cerr << "Помилка: " << e.what() << '\n';
    }
}

int main() {
    const std::string dbName = "sensor_data";
    const std::string user = "your_user";
    const std::string password = "your_password";

    createDatabase(dbName, user, password);
    return 0;
}
