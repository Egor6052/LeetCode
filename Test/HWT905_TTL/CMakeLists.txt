cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Назва проекту
project(HWT905_reader)

# Опція для використання статичних бібліотек
option(USE_STATIC "Use static library" ON)

# Вивід повідомлення про систему
message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compile with static library? ${USE_STATIC}")

# Шлях до вихідних файлів
set(SOURCE_FILES
    ./src/HWT/HWT905.cpp
)

# Заголовочні файли
set(HEADER_FILES
    ./lib/HWT905.h
)

# Додавання виконуваного файлу
add_executable(start
    src/main.cpp
    ${SOURCE_FILES}
)

# Компіляторні опції
target_compile_options(start
    PRIVATE
        -Wall -fPIC
)

# # Додавання шляхів до заголовкових файлів
# target_include_directories(start
#     PRIVATE
#         ./lib
#         /usr/include/mysql
# )
