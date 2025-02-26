cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Назва проекту
project(API_tester)

# Опція для використання статичних бібліотек
option(USE_STATIC "Use static library" ON)

# Вивід повідомлення про систему
message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compile with static library? ${USE_STATIC}")

# Шлях до вихідних файлів
set(SOURCE_FILES
    ./src/APIs/API.cpp
    ./src/APIs/sendToRaspberry.cpp
    ./src/APIs/getJSON.cpp
    ./src/APIs/DataTime.cpp
    ./src/APIs/logData.cpp
    ./src/APIs/setJsonPath.cpp
)

# Заголовочні файли
set(HEADER_FILES
    ./lib/API.h
)

# Додавання виконуваного файлу
add_executable(start
    src/main.cpp
    ${SOURCE_FILES}
)

find_package(CURL REQUIRED)
target_link_libraries(start PRIVATE CURL::libcurl)


# Компіляторні опції
target_compile_options(start
    PRIVATE
        -Wall -fPIC
)
