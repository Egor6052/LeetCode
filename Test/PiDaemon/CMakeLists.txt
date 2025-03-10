cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Project name
project(PiDaemon)

# Option to use static libraries
option(USE_STATIC "Use static library" ON)

# Display system message
message(STATUS "OS: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compile with static library? ${USE_STATIC}")

# Path to source files
set(SOURCE_FILES
    ./src/Daemon/Daemon.cpp
    ./src/Daemon/addToStartup.cpp
    ./src/Daemon/removeFromAutostart.cpp

    ./src/Daemon/gyroControllerOn.cpp
    ./src/Daemon/gyroControllerOff.cpp

    ./src/Daemon/logger.cpp
    ./src/Daemon/getJSON.cpp
    ./src/DataTime/DataTime.cpp

    ./src/Daemon/readControllerPower.cpp
    ./src/Daemon/toggleGyroController.cpp
)

# Header files
set(HEADER_FILES
    ./lib/Daemon.h
)

# Adding an executable file
add_executable(start
    src/main.cpp
    ${SOURCE_FILES}
)

target_link_libraries(start PRIVATE pigpio)

# Compiler options
target_compile_options(start
    PRIVATE
        -Wall -fPIC
)

# Link libraries
target_link_libraries(start
    PRIVATE
        curl
)