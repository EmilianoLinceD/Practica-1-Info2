#include <iostream>
using namespace std;

int main(){

    int N;
    cout << "Ingrese un valor N: ";
    cin >> N;
    cout << "Multiplos de " << N << " Menores que 100: " << "\n";
    cout << "\n";
    for (int a=1; a<=100; ++a) {
        if (a%N==0) {
            cout << a << "\n";
        }
    }

 return 0;
}
