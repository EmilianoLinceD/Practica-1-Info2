#include <iostream>

void Menu();

void Problema2();
int Problema4(char* cadena);
void Problema6();
void Problema8();
void Problema10();
void Problema12();
void Problema14();
void Problema16();
void Problema18();

void PruebaProblem4();


int main()
{
    Menu();
    return 0;
}


void Menu()
{
    int opcion;
    std::cout << "Cual es el problema a ejecutar: ";
    std::cin >> opcion;
    std::cout << std::endl;

    switch (opcion) {
    case 2:
        Problema2();
        break;
    case 4:
        PruebaProblem4();
        break;
    case 6:
        Problema6();
        break;
    case 8:
        Problema8();
        break;
    case 10:
        Problema10();
        break;
    case 12:
        Problema12();
        break;
    case 14:
        Problema14();
        break;
    case 16:
        Problema16();
        break;
    case 18:
        Problema18();
        break;
    default:
        std::cout << "Opcion no valida. " << std::endl;
    }
}

