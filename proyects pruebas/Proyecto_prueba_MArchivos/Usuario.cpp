#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

void IngUsuario(){

    std::ifstream archivo("Usuarios.txt");
    std::ofstream archivoTemporal("Usuarios_temp.txt");

    if (!archivo.is_open() || !archivoTemporal.is_open()) {
        std::cout << "Error al abrir el archivo. ERROR 02." << std::endl;
    }

    std::string Cedula, Clave, CedulaRegistrada, ClaveRegistrada;
    std::cout << "Ingrese la cedula: ";
            std::cin >> Cedula;
    std::cout << "Ingrese la clave: ";
            std::cin >> Clave;

    bool UsuarioEncontrado = false;
    int SaldoActual = 0;

    std::string Texto;
    while (std::getline(archivo, Texto)) {
        std::size_t pos1 = Texto.find('.');
        std::size_t pos2 = Texto.rfind('.');
        if (pos1 != std::string::npos && pos2 != std::string::npos) {
            CedulaRegistrada = Texto.substr(0, pos1);
            ClaveRegistrada = Texto.substr(pos1 + 1, pos2 - pos1 - 1);
            SaldoActual = stod(Texto.substr(pos2 + 1));

            if (Cedula == CedulaRegistrada && Clave == ClaveRegistrada) {
                UsuarioEncontrado = true;
                std::cout << "Usuario si esta registrado. " << std::endl;
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "1.Desea consultar saldo. " << std::endl;
                std::cout << "2.Desea Realizar un retiro. " << std::endl;
                std::cout << "3.Salir. " << std::endl;
                int OpcionRetiro;
                std::cin >> OpcionRetiro;


                switch (OpcionRetiro) {
                case 1:
                    std::cout << "Saldo actual: " << SaldoActual << std::endl;
                    SaldoActual -= 1000;
                    std::cout << "Saldo actualizado. Su saldo con la rebaja de 1000 es actualmente: " << SaldoActual << std::endl;
                    archivoTemporal << CedulaRegistrada << "." << ClaveRegistrada << "." << SaldoActual << std::endl;
                    std::remove("Usuarios.txt");
                    std::rename("usuarios_temp.txt", "Usuarios.txt");
                    archivo.close();
                    archivoTemporal.close();

                    break;
                case 2:
                    int Retiro;
                    std::cout << "Ingrese el monto a retirar en [COP]: ";
                    std::cin >> Retiro;
                    if (Retiro <= SaldoActual) {
                        SaldoActual -= Retiro;
                        SaldoActual -= 1000;
                        std::cout << "Retiro exitoso." << std::endl;
                    } else {
                        std::cout << "Saldo insuficiente." << std::endl;
                    }
                    archivoTemporal << CedulaRegistrada << "." << ClaveRegistrada << "." << SaldoActual << std::endl;
                    std::remove("Usuarios.txt");
                    std::rename("usuarios_temp.txt", "Usuarios.txt");
                    archivo.close();
                    archivoTemporal.close();


                    break;
                case 3:
                    std::remove("Usuarios.txt");
                    std::rename("usuarios_temp.txt", "Usuarios.txt");
                    archivo.close();
                    archivoTemporal.close();

                    break;
                default:
                    std::cout << std::endl;
                    std::cout << "Error 01." << std::endl;
                    std::cout << "Opcion no valida" << std::endl;
                    archivo.close();
                    archivoTemporal.close();
                    break;
                }
                std::remove("Usuarios.txt");
                std::rename("usuarios_temp.txt", "Usuarios.txt");
                archivo.close();
                archivoTemporal.close();

            }
            else{
                std::cout << "Usuario no resgistrado. Error 04." << std::endl;
            }

        } else {
            archivoTemporal << Texto << std::endl;
            std::remove("Usuarios.txt");
            std::rename("usuarios_temp.txt", "Usuarios.txt");
            archivo.close();
            archivoTemporal.close();

            //remove("Usuarios.txt");
        }
    }

}
