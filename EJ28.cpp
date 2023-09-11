#include <iostream>

int main() {
    
    int n;
    double pi, Sum = 0.0;
    std::cout << "Ingrese el numero de elementos para la aproximacion de pi: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        
        Sum = 1.0 / (2 * i + 1);
        
        if (i % 2 == 0) {
            
            pi += Sum;
        } 
        else {
        
            pi -= Sum;
        }
    }

    pi *= 4;

    std::cout << "pi es aproximadamente: " << pi << std::endl;

    return 0;
}