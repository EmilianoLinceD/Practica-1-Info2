#include <iostream>

int main() {
    
    int a=0, b=0, c=0,Sum=0;
    
    std::cout << "Ingrese el valor de a: ";
    std::cin >> a;
    std::cout << "Ingrese el valor de b: ";
    std::cin >> b;
    std::cout << "Ingrese el valor de c: ";
    std::cin >> c;

    for (int i = 1; i < c; i++) {
        if (i % a == 0 || i % b == 0) {
            Sum += i;
        }
    }

    std::cout << "m" << a << "1";
    for (int j = 2; j <= c / a; j++) {
        std::cout << " + m" << a << j;
    }

    std::cout << " + m" << b << "1";
    for (int m = 2; m <= c / b; m++) {
        std::cout << " + m" << b << m;
    }

    std::cout << " = " << Sum << std::endl;
    return 0;
}
