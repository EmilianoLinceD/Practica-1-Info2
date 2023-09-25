#include <iostream>
#include <ctime>
#include <cstdlib>

int Problema4(char*);
void Problema14();

//---------------------------------------------------------------------------------------------------------------------------------//
//PROBLEMA4
void PruebaProblem4()
{
    char entrada[100];
    std::cout << "Ingrese una cadena de caracteres numericos: ";
    std::cin >> entrada;

    int numero = Problema4(entrada);

    if (numero != 0) {
        std::cout << "Numero entero obtenido: " << numero << std::endl;
    } else {
        std::cout << "Error: La cadena no es un numero entero valido." << std::endl;
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------//
//PROBLEMA12
bool CuadradoMagico(int **matriz, int n) {
    int suma_diagonal1 = 0;
    int suma_diagonal2 = 0;

    // Calcula la suma de la primera diagonal
    for (int i = 0; i < n; i++) {
        suma_diagonal1 += matriz[i][i];
    }

    // Calcula la suma de la segunda diagonal
    for (int i = 0; i < n; i++) {
        suma_diagonal2 += matriz[i][n - 1 - i];
    }

    // Si las sumas de las diagonales no son iguales, no es un cuadrado mágico
    if (suma_diagonal1 != suma_diagonal2) {
        return false;
    }

    // Compara la suma de cada fila y columna con la suma de la primera diagonal
    for (int i = 0; i < n; i++) {
        int suma_fila = 0;
        int suma_columna = 0;

        for (int j = 0; j < n; j++) {
            suma_fila += matriz[i][j];
            suma_columna += matriz[j][i];
        }

        if (suma_fila != suma_diagonal1 || suma_columna != suma_diagonal1) {
            return false;
        }
    }

    return true;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//PROBLEMA14
void OutMatriz(int matriz[5][5]) {
    for (int fila = 0; fila < 5; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            std::cout << matriz[fila][columna] << "\t";
        }
        std::cout << std::endl;
    }
}

void RotarMatrizGrados(int matriz[5][5]) {
    int nuevaMatriz[5][5];

    for (int fila = 0; fila < 5; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            nuevaMatriz[fila][columna] = matriz[4 - columna][fila];
        }
    }

    // Copiar la matriz rotada de vuelta a la matriz original
    for (int fila = 0; fila < 5; fila++) {
        for (int columna = 0; columna < 5; columna++) {
            matriz[fila][columna] = nuevaMatriz[fila][columna];
        }
    }
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//PROBLEMA16 Y LA FUNCION Factorial(int) TAMBIEN PARA EL PROBLEMA 18

// Función para calcular el factorial de un número
unsigned long long int Factorial(int n) {
    if (n == 0) return 1;
    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
unsigned long long int CaminosPosibles(int n) {
    unsigned long long int numerador = Factorial(2 * n);
    unsigned long long int denominador = Factorial(n) * Factorial(n);
    return numerador / denominador;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//PROBLEMA18

// Función para encontrar la enésima permutación lexicográfica de los números del 0 al 9
std::string EncontrarPermLexi(int n) {
    int numeros[10];
    for (int i = 0; i <= 9; i++) {
        numeros[i] = i;
    }

    std::string permutacion;
    n--; // Restamos 1 porque las permutaciones comienzan desde 0.

    for (int i = 9; i >= 0; i--) {
        unsigned long long fact = Factorial(i);
        int indice = n / fact;
        permutacion += std::to_string(numeros[indice]);

        // Eliminar el número usado
        for (int j = indice; j < i; j++) {
            numeros[j] = numeros[j + 1];
        }

        n %= fact;
    }

    return permutacion;
}

