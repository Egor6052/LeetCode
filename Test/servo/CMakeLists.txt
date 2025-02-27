cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Назва проекту
project(Servo)

# Опція для використання статичних бібліотек
option(USE_STATIC "Use static library" ON)

# Вивід повідомлення про систему
message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compile with static library? ${USE_STATIC}")

# Шлях до вихідних файлів
set(SOURCE_FILES
    ./src/Servo/Servo.cpp
    ./src/Servo/SetServoAngle.cpp
    ./src/Servo/Start.cpp

    ./src/Connection/Connection.cpp
)

# Заголовочні файли
set(HEADER_FILES
    ./lib/Servo.h
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

# # Пакет для gpio
# find_package(PkgConfig REQUIRED)
# pkg_check_modules(PIGPIO REQUIRED pigpio)

# add_executable(start src/Servo/Start.cpp)
# target_link_libraries(start PRIVATE pigpio)
