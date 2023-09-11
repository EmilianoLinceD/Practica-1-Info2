#include <iostream>
#include <cstdlib>

int main() {
    
    int NumAll = rand() % 101;
    int NumAdiv, Intentos = 0;

    

    std::cout << "-------Adivina el número entre 0 y 100--------" << std::endl;

    do {
        std::cout << "Ingresa tu Numero: ";
        std::cin >> NumAdiv;

        if (NumAdiv < NumAll) {
            std::cout << "El numero es mayor." << std::endl;
        } else if (NumAdiv > NumAll) {
            std::cout << "El numero es menor." << std::endl;
        }

        Intentos++;

    } while (NumAdiv != NumAll);

    std::cout << "¡¡¡Felicitaciones!!! Adivinaste el numero en " << Intentos << " intentos." << std::endl;

    return 0;
}


  //srand(static_cast<unsigned int>(time(nullptr))); #include <ctime>