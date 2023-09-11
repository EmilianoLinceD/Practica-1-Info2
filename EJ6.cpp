#include <iostream>
using namespace std;

int main(){

    int A, B, Res;
    cout << "Ingrese un valor A: ";
    cin >> A;
    Res = 1;
    cout << "Ingrese un valor B: ";
    cin >> B;
    cout << "\n";
    for (int N = 0; N < B; ++N) {
        Res = Res*A;
    }
    cout << A << "^" << B << " = " << Res;

 return 0;
}
