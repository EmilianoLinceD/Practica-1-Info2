#include <iostream>
using namespace std;

int main(){

    int Num, NumProm, div;
    cout << "Ingrese un numero:  ";
    cin >> Num;
    NumProm=Num;
    div=1;
    cout << "\n";
    while (Num!=0) {
        cout << "Ingrese un numero: ";
        cin >> Num;
        div+=1;
        NumProm=NumProm+Num;
    }
    NumProm=NumProm/div;
    cout << "El promedio es: " << NumProm;

 return 0;
}

