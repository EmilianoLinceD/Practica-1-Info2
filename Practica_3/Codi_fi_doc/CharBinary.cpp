#include <iostream>
#include <fstream>
#include <cstring>
#include <bitset>

std::string CharToBinary(char C) {
    // Obtener el valor ASCII del carácter
    int asciiValue = static_cast<int>(C);
    std::string BinChar;

    // Convertir el valor ASCII a binario de 8 bits
    std::bitset<8> binaryRepresentation(asciiValue);

    // Convertir el binario a una cadena
    BinChar = binaryRepresentation.to_string();
    return BinChar;
}

std::string charToBinary(char c) {
    // Obtener el valor ASCII del carácter
    int asciiValue = static_cast<int>(c);
    std::string BinChar;

    // Convertir el valor ASCII a binario de 8 bits
    std::bitset<8> binaryRepresentation(asciiValue);

    // Convertir el binario a una cadena
    BinChar = binaryRepresentation.to_string();
    return BinChar;
}

