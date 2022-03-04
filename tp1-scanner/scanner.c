#include <stdio.h>
#include <ctype.h>
#include "scanner.h"

int get_token(void){
    char caracter_leido = getchar(); // caracter que va leyendo el input
    
    if (caracter_leido != EOF){
        while (isspace(caracter_leido)){
            caracter_leido = getchar();
        }
        
        if (caracter_leido == ','){
            buffer[0] = ',';
            return SEP;
        }

        int i = 0;
        while (still_string(caracter_leido)){ // leo caracteres de a uno y los guardo en el buffer       
            buffer[i] = caracter_leido;
            i++;
            caracter_leido = getchar();
        }

        ungetc(caracter_leido, stdin); // devuelvo caracter que leí demás

        return CAD;
    }

    return FDT;
}

int still_string(char c)
{
    if (c != ',' && !isspace(c) && c != EOF){
        return 1;
    }
    
    return 0;
}