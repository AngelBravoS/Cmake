cmake_minimum_required(VERSION 3.6)

project(cmake)

# Especificación de C++ estándar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Para evitar extensiones específicas del compilador
set(CMAKE_CXX_COMPILER "cl") # clang++/g++/icx/cl
#set(CMAKE_CXX_COMPILER_ID "")
#set(CMAKE_AR "llvm-ar")
#set(CMAKE_RANLIB "llvm-ranlib")

# Configuración de compilación (Debug/Release)
#set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build: Debug or Release")
set(CMAKE_BUILD_TYPE Debug)

# Configuración específica del compilador
if (CMAKE_CXX_COMPILER STREQUAL "clang++")
    add_compile_options(
        "$<$<CONFIG:Debug>:-Wpedantic;-Wall;-Wextra;-Wconversion;-Wshadow;-Wcast-qual;-Wwrite-strings;-DDEBUG>"
        "$<$<CONFIG:Release>:-pedantic;-Wall;-O3>"
    )
elseif (CMAKE_CXX_COMPILER STREQUAL "g++")
    add_compile_options(
        "$<$<CONFIG:Debug>:-pedantic;-Wall;-Wextra;-Wconversion;-Wshadow;-Wcast-qual;-Wwrite-strings;-O0;-ggdb3;-DDEBUG>"
        "$<$<CONFIG:Release>:-pedantic;-Wall;-O3>"
    )

elseif (CMAKE_CXX_COMPILER STREQUAL "cl")
    add_compile_options(
        "$<$<CONFIG:Debug>:/MDd;/RTC1;/permissive;/W3;/Wall;/DDEBUG;/Od;/Ob0;/Zi;/utf-8;/MP;/wd4820;/wd5045;/wd4668>"
        "$<$<CONFIG:Release>:/O2;/W3>"          # /O2: Optimización, /W3: Advertencias moderadas
   )
elseif (CMAKE_CXX_COMPILER STREQUAL "icx")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        message(STATUS "Configurando para Intel Compiler icx en modo MSVC")
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        message(STATUS "Configurando para Intel Compiler icx en modo Clang")
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "icx")
        message(STATUS "Configurando para Intel Compiler icx en modo icx")
    endif()
    add_compile_options(
        "$<$<CONFIG:Debug>:-Wpedantic;-Wall;-Wextra;-Wconversion;-Wshadow;-Wcast-qual;-Wwrite-strings;-DDEBUG>"
        "$<$<CONFIG:Release>:-pedantic;-Wall;-O3>"
    )
else()
    message(WARNING "Compilador no soportado. No se aplican banderas específicas.")
endif()

# Verificar compilador activo

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_CXX_COMPILER_VERSION: ${CMAKE_CXX_COMPILER_VERSION}")

# Configuración del ejecutable
add_executable(cmake src/main.cpp)

# Directorios de encabezados
target_include_directories(cmake PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Directorio de salida
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Instalación
install(TARGETS cmake RUNTIME DESTINATION bin)

# Pruebas automáticas para verificar la configuración
enable_testing()

add_test(
    NAME CompiladorCorrecto
    COMMAND ${CMAKE_COMMAND} -E echo "Compilador: ${CMAKE_CXX_COMPILER_ID}, Versión: ${CMAKE_CXX_COMPILER_VERSION}"
)
