#include <iostream>
using namespace std;

int main(){

    int N, Res;
    cout << "Ingrese un valor N: ";
    cin >> N;
    cout << "Todas sus potencias son: " << "\n";
    cout << "\n";
    Res=1;
    for (int a=1; a<=5; ++a) {
        Res=Res*N;
        cout << N << "^" << a << " = " << Res << "\n";
    }

 return 0;
}
