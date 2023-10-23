#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Administrador.cpp"
#include "Usuario.cpp"

void IngAdministrador();
void IngUsuario();

void menu()
{
    int OpcionIngreso=0;
    bool OpcIngCorrecta= true;

    std::cout << "\n" << "------Sistema de registro de usuario------" << std::endl;
    std::cout << std::endl;


    while (OpcIngCorrecta) {

        std::cout << std::endl;
        std::cout << "Elije el metodo de ingreso:" << std::endl;
        std::cout << "1. Ingreso como administrador." << std::endl;
        std::cout << "2. Ingreso como usuario." << std::endl;
        std::cout << "Ingrese su opcion:";
        std::cin >> OpcionIngreso;

        switch (OpcionIngreso) {
        case 1:
            std::cout << std::endl;
            IngAdministrador();
            OpcIngCorrecta = false;
            break;
        case 2:
            std::cout << std::endl;
            IngUsuario();
            OpcIngCorrecta = false;
            break;
        default:
            std::cout << std::endl;
            std::cout << "Error 01." << std::endl;
            std::cout << "Opcion no valida" << std::endl;
            OpcIngCorrecta = true;
            break;
        }
    }
}
