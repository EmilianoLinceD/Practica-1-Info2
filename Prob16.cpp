#include <iostream>


int main() {
    
    int k;
    std::cout << "Ingrese el valor de k: ";
    std::cin >> k;

    int SemMasLarg = 0, TerMasLarg = 0, n, Term;

    for (int j = 1; j < k; j++) {
        n = j;
        Term = 1;

        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            Term++;
        }

        if (Term > TerMasLarg) {
            TerMasLarg = Term;
            SemMasLarg = j;
        }
    }

    std::cout << "La serie mas larga es con la semilla: " << SemMasLarg << ", teniendo " << TerMasLarg << " términos." << std::endl;

    // Imprimir la serie
    int Num = SemMasLarg;
    std::cout << "Serie: ";
    while (Num != 1) {
        std::cout << Num << ", ";
        if (Num % 2 == 0) {
            Num /= 2;
        } else {
            Num = 3 * Num + 1;
        }
    }
    std::cout << "1" << std::endl;

    return 0;
}

