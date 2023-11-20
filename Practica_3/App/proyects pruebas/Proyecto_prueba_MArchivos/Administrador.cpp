#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "DesencriptarMetodo2.cpp"
#include "EncriptarMetodo2.cpp"

std::string Desencriptado2(std::string);
char BinaryTostring(const std::string&);
std::string charToBinary(std::string);
std::string Encriptado2(std::string);

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
        std::string Resultado, Texto_bin_D;

        while (getline(ArchivoUA, Texto)) {
            Texto_bin_D= Desencriptado2(Texto);

            for (int i = 0; i < Texto_bin_D.length(); i += 8) {
                std::string octeto = Texto_bin_D.substr(i, 8);
                char caracter =BinaryTostring(octeto);
                Resultado += caracter;
            }
            std::size_t pos = Resultado.find('-');
            if (pos != std::string::npos) {
                UsuarioComp = Resultado.substr(0, pos);
                ClaveComp = Resultado.substr(pos + 1);

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
                std::string CedulaE,ClaveE,SaldoE,RepreBinCD, RepreBinCL, RepreBinSD;
                RepreBinCD+=charToBinary(Cedula);
                CedulaE=Encriptado2(RepreBinCD);
                RepreBinCL+=charToBinary(Clave);
                ClaveE=Encriptado2(RepreBinSD);
                RepreBinSD+=charToBinary(Saldo);
                SaldoE=Encriptado2(RepreBinSD);
                UsuarioNew = CedulaE + "." + ClaveE + "." + SaldoE;
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
