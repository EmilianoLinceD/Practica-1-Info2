#include <iostream>
#include <fstream>
#include <cstring>
#include <bitset>

char BinaryTostring(const std::string& TextBin) {

    int valor = std::bitset<8>(TextBin).to_ulong();
    return static_cast<char>(valor);

    //    // Obtener el valor ASCII del carácter
    //    int asciiValue = static_cast<int>(c);
    //    std::string BinChar;

    //    // Convertir el valor ASCII a binario de 8 bits
    //    std::bitset<8> binaryRepresentation(asciiValue);

    //    // Convertir el binario a una cadena
    //    BinChar = binaryRepresentation.to_string();
}


std::string Desencriptado2(std::string TextArchi){
    std::string Alm_string_E, Conv_string_D;
    int n_bitsD = 0, Conf_posE = 0;
    bool Pos_CamE=false;
    std::cout << "De cuantos bits quiere la decodificacion: ";
    std::cin >> n_bitsD;

    for (int Pos_bitE = 0; Pos_bitE < TextArchi.length(); ++Pos_bitE) {
        if (Conf_posE != n_bitsD) {
            ++Conf_posE;
            Alm_string_E=Alm_string_E+TextArchi[Pos_bitE];
        } else {
            Pos_CamE=false;
            if (Alm_string_E[0]=='1'){
                Pos_CamE=true;
            }
            for (int Pos_almE = 0; Pos_almE < n_bitsD; ++Pos_almE){
                if (Pos_almE==(n_bitsD-1)){
                    if (Pos_CamE){
                        Alm_string_E[Pos_almE]='1';
                    }else{
                        Alm_string_E[Pos_almE]='0';
                    }
                }else{
                    if (Alm_string_E[Pos_almE+1]=='1'){
                        Alm_string_E[Pos_almE]='1';
                    }else{
                        Alm_string_E[Pos_almE]='0';
                    }
                }
            }
            Conv_string_D= Conv_string_D+Alm_string_E;
            Alm_string_E="";
            Conf_posE=0;
            Pos_bitE=Pos_bitE-1;
        }
    }
    return Conv_string_D;
}

