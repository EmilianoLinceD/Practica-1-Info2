#include <iostream>
using namespace std;

int main(){

    int N;
    cout << "Ingrese un numero N: ";
    cin >> N;
    cout << "\n";
    if (N%2 == 0) {
        cout << N << " Es par " << "\n";
    }
    else{
        cout << N << " No es par " << "\n";
    }

 return 0;
}
