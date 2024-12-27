#include "table_schema.json"
#include <pqxx/pqxx>
#include <fstream>
#include <sstream>
#include <iostream>

std::string generateTableSQL(const nlohmann::json &schema) {
    std::ostringstream sql;
    sql << "CREATE TABLE IF NOT EXISTS " << schema["table_name"] << " (";
    for (const auto &column : schema["columns"]) {
        sql << column["name"] << " " << column["type"];
        if (column.contains("constraints")) {
            sql << " " << column["constraints"];
        }
        sql << ", ";
    }
    sql.seekp(-2, std::ios_base::end);
    sql << ")";
    return sql.str();
}

int main() {
    try {
        std::ifstream file("table_schema.json");
        if (!file.is_open()) {
            throw std::runtime_error("Не вдалося відкрити файл table_schema.json");
        }

        nlohmann::json schema;
        file >> schema;

        pqxx::connection conn("dbname=cpp_db user=cpp_user password=958432023");
        pqxx::work txn(conn);

        std::string createTableSQL = generateTableSQL(schema);
        txn.exec(createTableSQL);
        txn.commit();

        std::cout << "Таблицю створено успішно!" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
