#include <iostream>
#include "EncriptarMetodo2.cpp"
#include "EncriptarMetodo1.cpp"
#include "DesencriptarMetodo2.cpp"
#include "EscArch.cpp"


//declaraciones
void LeerArchivo(std::string);
void Encripto1Archivo(std::string);
void Encripto2Archivo(std::string);

// menu
void menu(){

    std::string archivo;
    int Opcion;

    std::cout << "Nombre del archivo al que desea procesar?: ";
    std::cin >> archivo;
    std::cout << std::endl;

    std::cout << "---Menu de opciones---" << std::endl;
    std::cout << "Elija una opcion de acuerdo a lo que desea:" << std::endl;
    std::cout << "1. Encriptar archivo Metodo 1" << std::endl;
    std::cout << "2. Encriptar archivo Metodo 2" << std::endl;
    std::cout << "3. Leer lo contenido en el archivo" << std::endl;
    std::cout << "4. Escribir en el archivo" << std::endl;
    std::cout << std::endl;
    std::cout << "Opcion: ";
    std::cin >> Opcion;

    switch (Opcion) {
    case 1:
        Encripto1Archivo(archivo);
        break;
    case 2:
        Encripto2Archivo(archivo);
        break;
    case 3:
        LeerArchivo(archivo);
        break;
    case 4:

        break;
    default:
        std::cout << "Error opcion no valida." << std::endl;
        break;
    }
}

void Encripto1Archivo(std::string archivo){

    std::string linea, Texto;
    std::ifstream Archivo1(archivo);
    std::ofstream Archivo1temp("Temp.txt");
    if (!Archivo1)
    {
        std::cout << "ERROR. Archivo no encontrado." << std::endl;
    }
    else
    {
        while (std::getline(Archivo1, linea)) {
            Texto=Texto+linea+"\n";
        }
        std::cout << Texto;
        int TamText=0;
        std::string RepreBin = "";
        char C;
        TamText = Texto.length();
        for (int i = 0; i < TamText; ++i) {
            if (Texto[i] == '\n'){
                C='\n';
            }
            else{
                C = Texto[i];
            }
            RepreBin = RepreBin + CharToBinary(C);
        }
        std::string TextEncrip= "";
        TextEncrip=Encriptado1(RepreBin);
        Archivo1temp << TextEncrip;
        Archivo1.close();
        Archivo1temp.close();
    }
}

void Encripto2Archivo(std::string archivo){

    std::string linea, Texto;
    std::ifstream Archivo1(archivo);
    std::ofstream Archivo1temp("Temp.txt");
    if (!Archivo1)
    {
        std::cout << "ERROR. Archivo no encontrado." << std::endl;
    }
    else
    {
        while (std::getline(Archivo1, linea)) {
            Texto=Texto+linea+"\n";
        }
        std::cout << Texto;
        int TamText=0;
        std::string RepreBin = "";
        char c;
        TamText = Texto.length();
        for (int i = 0; i < TamText; ++i) {
            if (Texto[i] == '\n'){
                c='\n';
            }
            else{
                c = Texto[i];
            }
            RepreBin = RepreBin + charToBinary(c);
        }
        std::string TextEncrip= "";
        TextEncrip=Encriptado2(RepreBin);
        Archivo1temp << TextEncrip;
        Archivo1.close();
        Archivo1temp.close();
    }
}
