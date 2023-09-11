#include <iostream>

int main() {
    int Num=0;
    double euler = 1.0, Fact = 1.0;

    std::cout << "Ingrese el nunmero de elementos usados en la aproximacion: ";
    std::cin >> Num;

    if (Num > 0) {
        
        for (int i = 1; i < Num; i++) {
            Fact *= i;  
            euler += 1.0 / Fact;  
        }
    }

    std::cout << "e es aproximadamente: " << euler << std::endl;

    return 0;
}

