#include <iostream>

int main()
{
    int Num,NumSpace = 0;
    std :: string Ltr = "+";
    std :: string Ltr2 = "+";
    std :: string Space = " ";
    std::cout << "Ingrese un numero entero: ";
    std::cin >> Num;
    NumSpace = Num - 2;
    for(int m=0; m<(NumSpace-1); m++){
        Space = Space + " ";
    }
    for(int j=0; j<(Num-1); j++){
        Ltr2 = Ltr2 + Ltr;
    }
    for (int i=0; i<Num; i++){
        
       if (i==0){
           std::cout << Ltr2;
        }
        else if (i==(Num-1)){
            std::cout << Ltr2;
        }
        else{
            std::cout << Ltr << Space << Ltr;
        }
            
        std::cout << std::endl;
        
    }
    return 0;
}
