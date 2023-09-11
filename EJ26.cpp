#include <iostream>

int main()
{
    int Lado1, Lado2, Lado3 = 0;
    std::cout << "Ingrese el primer lado del triangulo: ";
    std::cin >> Lado1;
    std::cout << "Ingrese el segundo lado del triangulo: ";
    std::cin >> Lado2;
    std::cout << "Ingrese el tercer lado del triangulo: ";
    std::cin >> Lado3;
    if (Lado1 + Lado2 > Lado3 && Lado1 + Lado3 > Lado2 && Lado2 + Lado3 > Lado1) {
        if (Lado1 == Lado2 && Lado1 == Lado3) {
            std::cout << "Se forma un triangulo equilatero. " << std::endl;
        } else if (Lado1 == Lado2 || Lado1 == Lado3 || Lado2 == Lado3) {
            std::cout << "Se forma un triangulo isosceles. " << std::endl;
        } else {
            std::cout << "Se forma un triangulo escaleno. " << std::endl;
        }
    } else {
        std::cout << "Las longitudes ingresadas no forman un triangulo. " << std::endl;
    }