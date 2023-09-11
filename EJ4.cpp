#include <iostream>
using namespace std;

int main(){

    int A, B;
    cout << "Ingrese un valor A: ";
    cin >> A;
    cout << "Ingrese un valor B: ";
    cin >> B;
    cout << "\n";
    if (A>=B) {

        /* cout << "EL mayor es " << A; */

        cout << "El menor es " << B;

    }
    else{
        /* cout << "El mayor es " << B;*/

        cout << "El menor es " << A;
    }

 return 0;
}
