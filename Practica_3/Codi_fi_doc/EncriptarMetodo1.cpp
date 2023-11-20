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

std::string Encriptado1(std::string RepreBin){
    std::string Alm_string_E, Conv_string_E;
    int n_bit = 0, Conf_pos = 0, count_1 = 0, count_0 = 0, countbit=0;
    std::cout << "De cuantos bits quiere la codificacion: ";
    std::cin >> n_bit;
    for (int Pos_bit1 = 0; Pos_bit1 < n_bit; ++Pos_bit1){
        if (RepreBin[Pos_bit1]=='1'){
            RepreBin[Pos_bit1]='0';
        }else{
            RepreBin[Pos_bit1]='1';
        }
        Conv_string_E=Conv_string_E+RepreBin[Pos_bit1];
    }

    for (int Pos_bit2 = n_bit; Pos_bit2 < RepreBin.length(); ++Pos_bit2) {

        if (Conf_pos != n_bit) {
            ++Conf_pos;
            Alm_string_E=Alm_string_E+RepreBin[Pos_bit2];
        } else {
            std::cout << " Cada valor es: " << Alm_string_E << std::endl;
            countbit=0;
            count_0=0;
            count_1=0;
            for (int Pos_alm1 = 0; Pos_alm1 < n_bit; ++Pos_alm1) {
                if (Alm_string_E[Pos_alm1]=='1'){
                    ++count_1;
                }else {
                    ++count_0;
                }
            }
            for (int Pos_alm2 = 0; Pos_alm2 < n_bit; ++Pos_alm2) {
                if (count_0==count_1){
                    if (Alm_string_E[Pos_alm2]=='1'){
                        Alm_string_E[Pos_alm2]='0';
                    }else{
                        Alm_string_E[Pos_alm2]='1';
                    }
                }else if(count_0>count_1){
                    if ((countbit % 2) != 0){
                        if (Alm_string_E[Pos_alm2]=='1'){
                            Alm_string_E[Pos_alm2]='0';
                        }else{
                            Alm_string_E[Pos_alm2]='1';
                        }
                    }else{}
                }else if(count_1>count_0){
                    if ((countbit % 3) == 2){
                        if (Alm_string_E[Pos_alm2]=='1'){
                            Alm_string_E[Pos_alm2]='0';
                        }else{
                            Alm_string_E[Pos_alm2]='1';
                        }
                    }else{}
                }
                ++countbit;
            }
            Conv_string_E= Conv_string_E+Alm_string_E;
            Alm_string_E="";
            Conf_pos=0;
            Pos_bit2=Pos_bit2-1;
        }
    }

    return Conv_string_E;
}





