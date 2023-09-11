#include <iostream>


int main()
{
    int N=0, num=0, rev=0, residuo=0;
    std::cout << "Ingrese un numero N: ";
    std::cin >> N;
    num = N;
    while (num!=0){
        residuo = num % 10;
        rev = rev * 10 + residuo;
        num = num/10;
    }
    if (rev==N){
        std::cout << N << " es un numero palindromo" << std::endl;
    }
    else{
        std::cout << N << " NO es un numero palindromo" << std::endl;
    }
    return 0;
}
