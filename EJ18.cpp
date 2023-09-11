#include <iostream>


int main()
{
    int N=0, Comp=0;
    std::cout << "Ingrese un numero N: ";
    std::cin >> N;
    for (int i=0; i<=N; i++){
        Comp = i*i;
        if (Comp==N){
            std::cout << N << " es un cuadrado pefecto" << std::endl;
            break;
        }
        
        
    }
    if(Comp!=N){
        std::cout << N << " NO es un cuadrado perfecto" << std::endl;
    }
    
    return 0;
}