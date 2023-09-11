#include <iostream>


int main() {
    
    int Val, CantBill, CantMone;
    std::cout << "Ingrese el valor: ";
    std::cin >> Val;

    int Billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
    int Monedas[] = {500, 200, 100, 50};

    std::cout << "Billetes y monedas necesarios para completar " << Val << ":" << std::endl;

    for (int i = 0; i < 6; i++) {
        
        CantBill = Val / Billetes[i];
        Val %= Billetes[i];
        std::cout << Billetes[i] << " : " << CantBill << std::endl;
    }

    for (int j = 0; j < 4; j++) {
        CantMone = Val / Monedas[j];
        Val %= Monedas[j];
        std::cout << Monedas[j] << " : " << CantMone << std::endl;
    }

    if (Val > 0) {
        std::cout << "Faltante: " << Val << std::endl;
    }
    return 0;
}