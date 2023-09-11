#include <iostream>


int main() {
    
    int Hora, Duracion, DurHor, DurMin, NewHor, NewMin, Minx =0;

    std::cout << "Ingrese la hora en formato 24 horas: ";
    std::cin >> Hora;

    std::cout << "Ingrese la duracion: ";
    std::cin >> Duracion;

    DurHor = Duracion / 100;
    DurMin = Duracion % 100;

   
    if ((Hora < 0 || Hora > 2359) || (DurHor < 0 || DurHor > 23) || (DurMin < 0 || DurMin > 59)) {
        
        std::cout << Duracion << " es un tiempo invalido. " << std::endl;
        
    }
    else {
        if (((Hora%100)+DurMin)>59){
            Minx=1;
        }
        NewMin = ((Hora % 100) + DurMin)%60;
        NewHor = ((Hora/100) + DurHor + Minx)%2400;

        if (NewMin < 10) {
            std::cout << "La hora es " << NewHor << ":" << "0" << NewMin << std::endl;
        } 
        else {
            std::cout << "La hora es " << NewHor << ":" << NewMin << std::endl;
        }
    }
    return 0;
}
