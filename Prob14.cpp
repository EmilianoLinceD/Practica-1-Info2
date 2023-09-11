#include <iostream>


int main() {
    
    int MaxPal=0, Num1=0, Num2=0, Producto;
    

    for (int i = 144; i >= 100; i--) {
        for (int j = 778; j >= 100; j--) {
            Producto = i * j;

            if (Producto <= MaxPal) {
                break;
            }

            int Original = Producto;
            int Inv = 0, Dig;

            while (Original > 0) {
                Dig = Original % 10;
                Inv = Inv * 10 + Dig;
                Original /= 10;
            }

            if (Producto == Inv) {
                MaxPal = Producto;
                Num1 = i;
                Num2 = j;
            }
        }
    }

    std::cout << Num1 << "*" << Num2 << "=" << MaxPal << std::endl;

    return 0;
}
