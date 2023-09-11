#include <iostream>

int main()
{
    int NumSeg, Horas, Minutos, Segundos, Resto = 0;
    
   std::cout << "Ingrese el numero de Segundos: ";
   std::cin >> NumSeg;
   Horas = NumSeg / 3600;
   Resto = NumSeg - (Horas * 3600);
   Minutos = Resto / 60;
   Resto = Resto - (Minutos * 60);
   Segundos = Resto;
   std::cout << Horas << ":" << Minutos << ":" << Segundos << std::endl;
   

    return 0;
}