cmake_minimum_required(VERSION 3.6)

project(cmake)

# Especificación de C++ estándar
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Para evitar extensiones específicas del compilador
#set(CMAKE_CXX_COMPILER "clang++") # Alt "g++" GCC
#set(CMAKE_AR "llvm-ar")
#set(CMAKE_RANLIB "llvm-ranlib")

# Configuración de compilación (Debug/Release)
#set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build: Debug or Release")
set(CMAKE_BUILD_TYPE Debug)

# Configuración específica del compilador
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    message(STATUS "Configurando para Clang")
    add_compile_options(
        "$<$<CONFIG:Debug>:-pedantic;-Wall;-Wextra;-Wconversion;-Wshadow;-Wcast-qual;-Wwrite-strings;-O0;-ggdb3;-DDEBUG>"
        "$<$<CONFIG:Release>:-pedantic;-Wall;-O3>"
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Configurando para GCC")
    add_compile_options(
        "$<$<CONFIG:Debug>:-pedantic;-Wall;-Wextra;-Wconversion;-Wshadow;-Wcast-qual;-Wwrite-strings;-O0;-ggdb3;-DDEBUG>"
        "$<$<CONFIG:Release>:-pedantic;-Wall;-O3>"
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(STATUS "Configurando para MSVC")
    add_compile_options(
        "$<$<CONFIG:Debug>:/W4;/DDEBUG;/Od;/Zi>" # /W4: Nivel de advertencias alto, /Od: Sin optimización, /Zi: Depuración
        "$<$<CONFIG:Release>:/O2;/W3>"          # /O2: Optimización, /W3: Advertencias moderadas
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    message(STATUS "Configurando para Intel Compiler")
    add_compile_options(
        "$<$<CONFIG:Debug>:-Wall;-Wextra;-g;-O0;-debug>"
        "$<$<CONFIG:Release>:-O3;-ipo;-xHost>"
    )
else()
    message(WARNING "Compilador no soportado. No se aplican banderas específicas.")
endif()

# Verificar compilador activo
message(STATUS "Compilador detectado: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Compilador ejecutable: ${CMAKE_CXX_COMPILER}")


# Configuración del ejecutable
add_executable(cmake main.cpp)

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
