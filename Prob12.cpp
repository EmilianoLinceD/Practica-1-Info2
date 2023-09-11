#include <iostream>

int main() {
    
    int Num, N;
    std::cout << "Ingrese un numero: ";
    std::cin >> Num;
    N=Num;

    int MaxFacPrim = 0;
    int Div = 2;

    while (Num > 1) {
        if (Num % Div == 0) {
            MaxFacPrim = Div;
            Num /= Div;
        } else {
            Div++;
        }
    }

    std::cout << "El mayor factor primo de " << N << " es: " << MaxFacPrim << "." << std::endl;

    return 0;
}
