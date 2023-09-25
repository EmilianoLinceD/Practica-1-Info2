#include <iostream>
#include <ctime>
#include <cstdlib>

bool CuadradoMagico(int**, int);
void OutMatriz(int[5][5]);
void RotarMatrizGrados(int[5][5]);
unsigned long long int CaminosPosibles(int);
std::string EncontrarPermLexi(int);
//-------------------------------------------------------------------------------------------------------------------------------------//

void Problema2()
{
    // Inicializar la semilla para generar numeros aleatorios
    std::srand(std::time(nullptr));

    // Crear un arreglo de 200 letras mayusculas aleatorias
    const int TamArreglo = 200;
    char arreglo[TamArreglo];

    // Llenar el arreglo con letras aleatorias
    for (int i = 0; i < TamArreglo; i++) {
        arreglo[i] = 'A' + std::rand() % 26;  // Letras mayusculas de la 'A' a la 'Z'
    }

    // Imprimir el arreglo
    std::cout << "Arreglo: ";
    for (int i = 0; i < TamArreglo; i++) {
        std::cout << arreglo[i];
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Contar la frecuencia de cada letra
    int frecuencia[26] = {0};  // Inicializar un arreglo para las frecuencias

    for (int i = 0; i < TamArreglo; i++) {
        char letra = arreglo[i];
        if (letra >= 'A' && letra <= 'Z') {
            frecuencia[letra - 'A']++;
        }
    }

    // Imprimir la frecuencia de cada letra
    std::cout << "Frecuencia de cada letra:" << std::endl;
    for (int i = 0; i < 26; i++) {
        char letra = 'A' + i;
        if (frecuencia[i]>0){
           std::cout << letra << ": " << frecuencia[i] << std::endl;
        }

    }
}

//-------------------------------------------------------------------------------------------------------------------------//

int Problema4(char* cadena) {
    int resultado = 0;
    int signo = 1;
    int indice = 0;

    // Manejar el signo si la cadena comienza con '-' (negativo)
    if (cadena[0] == '-') {
        signo = -1;
        indice = 1;
    }

    // Iterar a traves de cada caracter en la cadena
    for (; cadena[indice] != '\0'; indice++) {
        // Verificar si el carácter es un digito numérico
        if (cadena[indice] >= '0' && cadena[indice] <= '9') {
           // Convertir el caracter a un digito numerico y agregarlo al resultado
           resultado = resultado * 10 + (cadena[indice] - '0');
        } else {
           // Si se encuentra un caracter no numerico, retornar un valor especial o manejar el error
           // En este caso, simplemente retornamos 0 como indicación de error
           return 0;
        }
    }

    return resultado * signo;
}
//-----------------------------------------------------------------------------------------------------------------------------//

void Problema6()
{
    const int MAX_LONGITUD = 100;

    char entrada[MAX_LONGITUD];
    std::cout << "Ingrese una cadena de caracteres: ";
    std::cin >> entrada;

    std::cout << "Original: " << entrada << std::endl;


    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] >= 'a' && entrada[i] <= 'z') {
           // Si es una letra minuscula, convertirla a mayuscula
           entrada[i] = entrada[i] - ('a' - 'A');
        }
    }

    std::cout << "En mayuscula: " << entrada << std::endl;
}

//--------------------------------------------------------------------------------------------------------------------------------------------//

void Problema8()
{
    const int MAX_LONGITUD = 100;

    char entrada[MAX_LONGITUD];
    std::cout << "Ingrese una cadena de caracteres: ";
    std::cin >> entrada;
    //std::cin.getline(entrada, MAX_LONGITUD);     //Revisa entrada que este menos del MAX_LONGITUD, si no la trunca.

    char texto[MAX_LONGITUD];
    char numeros[MAX_LONGITUD];
    int indiceTexto = 0;
    int indiceNumeros = 0;

    // Separar letras y numeros
    for (int i = 0; entrada[i] != '\0'; i++) {
        // Verificar si el caracter es un numero (0-9)
        if (entrada[i] >= '0' && entrada[i] <= '9') {
           // Si es un numero, agregarlo a la cadena de numeros
           numeros[indiceNumeros++] = entrada[i];
        } else {
           // Si no es un numero, agregarlo a la cadena de texto
           texto[indiceTexto++] = entrada[i];
        }
    }

    // Agregar terminadores nulos a ambas cadenas
    texto[indiceTexto] = '\0';
    numeros[indiceNumeros] = '\0';

    std::cout << "Original: " << entrada << std::endl;
    std::cout << "Texto: " << texto << ". Numero: " << numeros << "." << std::endl;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------//

void Problema10()
{
    std::string NumRomano;
    std::cout << "Ingrese un número romano: ";
            std::cin >> NumRomano;

    int NumArabigo = 0;
    int prev_valor = 0;

    for (int i = NumRomano.length() - 1; i >= 0; i--) {
        int valor;
        switch (NumRomano[i]) {
        case 'M':
           valor = 1000;
           break;
        case 'D':
           valor = 500;
           break;
        case 'C':
           valor = 100;
           break;
        case 'L':
           valor = 50;
           break;
        case 'X':
           valor = 10;
           break;
        case 'V':
           valor = 5;
           break;
        case 'I':
           valor = 1;
           break;
        default:
           valor = 0;
        }

        if (valor < prev_valor) {
           NumArabigo -= valor;
        } else {
           NumArabigo += valor;
        }

        prev_valor = valor;
    }

    std::cout << "El numero ingresado fue: " << NumRomano << std::endl;
            std::cout << "Que corresponde a: " << NumArabigo << std::endl;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------//

void Problema12()
{
    int N;
    std::cout << "Ingrese el tamano de la matriz cuadrada: ";
    std::cin >> N;

    // Crear una matriz dinámica
    int **matriz = new int*[N];
    for (int i = 0; i < N; i++) {
        matriz[i] = new int[N];
    }

    std::cout << "Ingrese los elementos de la matriz cuadrada:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
           std::cin >> matriz[i][j];
        }
    }

    std::cout << "Matriz ingresada:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
           std::cout << matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }

    if (CuadradoMagico(matriz, N)) {
        std::cout << "La matriz es un cuadrado magico." << std::endl;
    } else {
        std::cout << "La matriz no es un cuadrado magico." << std::endl;
    }

    // Liberar la memoria de la matriz dinámica
    for (int i = 0; i < N; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}
//------------------------------------------------------------------------------------------------------------------------------------------------//

void Problema14()
{
    int matriz[5][5];
    int valor = 1;
    for (int fila = 0; fila < 5; fila++) {
        for (int columna = 0; columna < 5; columna++) {
           matriz[fila][columna] = valor++;
        }
    }
    std::cout << "Matriz original:" << std::endl;
    OutMatriz(matriz);

    std::cout << "Matriz rotada 90 grados:" << std::endl;
    RotarMatrizGrados(matriz);
    OutMatriz(matriz);

    std::cout << "Matriz rotada 180 grados:" << std::endl;
    RotarMatrizGrados(matriz);
    RotarMatrizGrados(matriz);
    OutMatriz(matriz);

    std::cout << "Matriz rotada 270 grados:" << std::endl;
    RotarMatrizGrados(matriz);
    RotarMatrizGrados(matriz);
    RotarMatrizGrados(matriz);
    OutMatriz(matriz);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------//

void Problema16()
{
    int n;
    std::cout << "Ingrese el tamano de la cuadricula (n): ";
    std::cin >> n;

    unsigned long long int NumCaminos = CaminosPosibles(n);

    std::cout << "Para una malla de " << n << "x" << n << " puntos hay " << NumCaminos << " caminos." << std::endl;

}
//---------------------------------------------------------------------------------------------------------------------------------------------------//

void Problema18()
{
    int n;
    std::cout << "Ingrese el valor de n: ";
    std::cin >> n;

    std::string permutacion = EncontrarPermLexi(n);

    std::cout << "La permutacion numero " << n << " es: " << permutacion << "." << std::endl;

}
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
