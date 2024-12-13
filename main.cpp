#include "main.hpp"

int main() {
    // Información general del compilador
    std::cout << "Compilador: ";

    #if defined(__clang__)
    std::cout << "Clang " << __clang_major__ << "." << __clang_minor__ << "." << __clang_patchlevel__ << "\n";
    #elif defined(__GNUC__)
    std::cout << "GCC " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << "\n";
    #elif defined(_MSC_VER)
    std::cout << "MSVC " << _MSC_VER << "\n";
    #else
    std::cout << "Desconocido\n";
    #endif

    // Versión detallada del compilador
    std::cout << "Version de compilador: " << __VERSION__ << "\n";

    // Información del sistema operativo
    std::cout << "Sistema operativo: ";
    #if defined(__linux__)
    std::cout << "Linux\n";
    #elif defined(__APPLE__)
    std::cout << "macOS\n";
    #elif defined(_WIN32)
    std::cout << "Windows (32-bit)\n";
    #elif defined(_WIN64)
    std::cout << "Windows (64-bit)\n";
    #else
    std::cout << "Sistema operativo desconocido\n";
    #endif

    // Información de la arquitectura
    std::cout << "Arquitectura: ";
    #if defined(__x86_64__) || defined(_M_X64)
    std::cout << "x86_64\n";
    #elif defined(__i386__) || defined(_M_IX86)
    std::cout << "x86\n";
    #elif defined(__aarch64__)
    std::cout << "ARM 64-bit\n";
    #elif defined(__arm__) || defined(_M_ARM)
    std::cout << "ARM 32-bit\n";
    #else
    std::cout << "Arquitectura desconocida\n";
    #endif

    return 0;
}
