#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

void IngAdministrador(){

    std::string UsuarioIng, ClaveIng, UsuarioComp, ClaveComp, Texto;

    std::ifstream ArchivoUA("sudo.txt");

    if (!ArchivoUA.is_open()) {
        std::cout << "Error al abrir el archivo." << std::endl;
        std::cout << "Error 02." << std::endl;
    }
    bool UsuarioEncontrado = false;
    while (!UsuarioEncontrado) {
        std::cout << "Ingrese el usuario del administrador: ";
        std::cin >> UsuarioIng;
        std::cout << "\n";
        std::cout << "Ingrese clave del usuario administrativo: ";
        std::cin >> ClaveIng;
        std::cout << "\n";

        while (getline(ArchivoUA, Texto)) {
            std::size_t pos = Texto.find('-');
            if (pos != std::string::npos) {
                UsuarioComp = Texto.substr(0, pos);
                ClaveComp = Texto.substr(pos + 1);

                if (UsuarioIng == UsuarioComp && ClaveIng == ClaveComp) {
                    UsuarioEncontrado = true;
                    break;
                }
            }
        }

        if (UsuarioEncontrado) {
            std::cout << "Acceso concedido." << std::endl;
        } else {
            std::cout << "Usuario o clave incorrectos." << std::endl;
            std::cout << "Error 03." << std::endl;
            std::cout << "Intentelo nuevamente." << std::endl;
        }
    }
    ArchivoUA.close();

    if(UsuarioEncontrado){
        std::ofstream ArchivoAgregarUN("Usuarios.txt");

        int OpcAUN;
        std::string UsuarioNew, Cedula, Clave, Saldo, Usuarios;

        if (ArchivoAgregarUN.is_open()){
            std::cout << "Desea agregar usuario nuevo? " << std::endl;
            std::cout << "1.si" << std::endl;
            std::cout << "2.no" << std::endl;
            std::cout << "\n";
            std::cin >> OpcAUN;

            switch (OpcAUN) {
            case 1:
                std::cout << std::endl;
                std::cout << "Numero de cedula del usuario nuevo: ";
                std::cin >> Cedula;
                std::cout << std::endl;
                std::cout << "Clave del usuario nuevo: ";
                std::cin >> Clave;
                std::cout << std::endl;
                std::cout << "Saldo[COP] del usuario nuevo: ";
                std::cin >> Saldo;
                UsuarioNew = Cedula + "." + Clave + "." + Saldo;
                break;
            case 2:
                ArchivoAgregarUN.close();
                break;
            default:
                std::cout << std::endl;
                std::cout << "Error 01." << std::endl;
                std::cout << "Opcion no valida" << std::endl;
                break;
            }
            Usuarios = Usuarios + UsuarioNew + "\n";
            ArchivoAgregarUN << Usuarios << std::endl;
        }
        else {
            std::cout << "Error al abrir el archivo. ERROR 02." << std::endl;
        }

        ArchivoAgregarUN.close();
    }
}
