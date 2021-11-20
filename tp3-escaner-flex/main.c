#include <stdio.h>
#include "tokens.h"

//hago funcion get_token() para que me devuelva el token
int get_token(void)
{
    int token;
    token = yylex();
    return token;
}


int main(void){
    int token;

// FDT,
//     ENTERO, LEER, ESCRIBIR, PROGRAMA, FINPROGRAMA,  // Palabras reservadas
//     IDENTIFICADOR,
//     CONSTANTE,
//     ASIGNACION,




    do{
        token = get_token();

        switch(token){
            case FDT:
                printf("FDT\n");
                break;
            case ENTERO:
                printf("ENTERO\n");
                break;
            case LEER:
                printf("LEER\n");
                break;
            case ESCRIBIR:
                printf("ESCRIBIR\n");
                break;
            case PROGRAMA:
                printf("PROGRAMA\n");
                break;
            case FINPROGRAMA:
                printf("FINPROGRAMA\n");
                break;
            case IDENTIFICADOR:
                printf("IDENTIFICADOR\n");
                break;
            case CONSTANTE:
                printf("CONSTANTE\n");
                break;  
            case ASIGNACION:    
                printf("ASIGNACION\n");
                break;
            default:
                printf("Error %d\n", token);
                break;
        }




    } while(token != FDT);






    return 0;
}