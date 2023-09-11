#include <iostream>

int main() {
    
    int n;
    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;

    int Cont = 0; 
    int NumPrim = 2;   

    while (true) {
        bool EsPrim = true;

        for (int i = 2; i * i <= NumPrim; i++) {
            if (NumPrim % i == 0) {
                EsPrim = false;
                break;
            }
        }

        if (EsPrim) {
            Cont++;
        }

        if (Cont == n) {
            break;
        }

        NumPrim++;
    }

    std::cout << "El primo numero " << n << " es: " << NumPrim << "." << std::endl;
    
    return 0;
}
