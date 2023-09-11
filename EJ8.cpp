#include <iostream>
using namespace std;

int main(){

    int N, Fac;
    cout << "Ingrese un valor N: ";
    cin >> N;
    Fac=1;
    cout << "\n";
    for (int a=1; a<=N; ++a) {
        Fac=Fac*a;
    }
    cout << N << "! " << "= " << Fac;

 return 0;
}
