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

    # Daemon
    ./src/Daemon/Daemon.cpp
    ./src/Daemon/addToStartup.cpp
    ./src/Daemon/removeFromAutostart.cpp

    ./src/Daemon/CheckStatus.cpp
    ./src/Daemon/getJSON.cpp
    ./src/DataTime/DataTime.cpp
    ./src/Daemon/Configuration.cpp

    ./src/Daemon/readControllerPower.cpp
    ./src/Daemon/backgroundMode.cpp
    
    ./src/Daemon/toggleGyroController.cpp

    # CanBus
    ./src/Daemon/CanBus/CanPlayer.cpp

    # Logger
    ./src/Logger/Logger.cpp
    ./src/Logger/DataTime.cpp
    ./src/Logger/logError.cpp
)

# Header files
set(HEADER_FILES
    ./lib/Daemon.h
    ./lib/Logger.h
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