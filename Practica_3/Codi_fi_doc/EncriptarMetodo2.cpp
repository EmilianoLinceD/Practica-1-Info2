#include <iostream>
#include <fstream>
#include <cstring>
#include <bitset>


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


std::string Encriptado2(std::string RepreBin){
    std::string Alm_string_E, Conv_string_E;
    int n_bit = 0, Conf_pos = 0;
    bool Pos_Cam=false;
    std::cout << "De cuantos bits quiere la codificacion: ";
    std::cin >> n_bit;

    for (int Pos_bit = 0; Pos_bit < RepreBin.length(); ++Pos_bit) {
        if (Conf_pos != n_bit) {
            ++Conf_pos;
            Alm_string_E=Alm_string_E+RepreBin[Pos_bit];
        } else {

            if (Alm_string_E[(n_bit-1)]=='1'){
                Pos_Cam=true;
            }
            for (int Pos_alm = 0; Pos_alm < n_bit; ++Pos_alm) {
                if (Alm_string_E[Pos_alm]=='1'){
                    if (Pos_Cam){
                        Alm_string_E[Pos_alm]='1';
                    }else{
                        Alm_string_E[Pos_alm]='0';
                    }
                   Pos_Cam=true;
                }else if (Alm_string_E[Pos_alm]=='0'){
                   if (Pos_Cam){
                        Alm_string_E[Pos_alm]='1';
                   }else{
                        Alm_string_E[Pos_alm]='0';
                   }
                   Pos_Cam=false;
                }
            }
            Conv_string_E= Conv_string_E+Alm_string_E;
            Alm_string_E="";
            Conf_pos=0;
            Pos_bit=Pos_bit-1;
        }
    }
    return Conv_string_E;
}




