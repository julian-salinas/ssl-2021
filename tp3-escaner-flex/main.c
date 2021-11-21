/*
Grupo 4
Integrantes: Copa, Rocío Belén; Iglesias, Tobías; Salinas, Julián
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "scanner.h"

int main(int argc, const char *argv[]){
    token token_leido;

    do{
        token_leido = yylex();  // El scanner de Flex devuelve el token
        char resultado[100];  // Acá se va a copiar lo que luego se escribe en el archivo de salida

        switch(token_leido){
            case FDT:
                strcpy(resultado, "Token: Fin de Texto");
                break;
            
            case IDENTIFICADOR:
                strcat(strcpy(resultado, "Token: Identificador \t Lexema: "), yytext);
                break;
            
            case CONSTANTE:
                strcat(strcpy(resultado, "Token: Constante \t Lexema: "), yytext);
                break;  
            
            case ASIGNACION:    
                strcat(strcpy(resultado, "Token: Asignación \t Lexema: "), yytext);
                break;
            
            case CARACTER_PUNTUACION:
                strcat(strcpy(resultado, "Token: Caracter de Puntuación: \t Lexema: "), yytext);
                break;

            // Acá todos los case de palabra reservada
            case ENTERO:
                strcpy(resultado, "Token: Entero");
                break;

            case LEER:
                strcpy(resultado, "Token: Leer");
                break;

            case ESCRIBIR:
                strcpy(resultado, "Token: Escribir");
                break;

            case PROGRAMA:
                strcpy(resultado, "Token: Programa");
                break;

            case FIN_PROGRAMA:
                strcpy(resultado, "Token: Fin Programa");
                break;

            // El scanner falló
            default:
                strcat(strcpy(resultado, "ERROR, El scanner implosionó al ver el caracter"), yytext);
                break;
        }

        // Escribir el archivo de salida
        puts(resultado);

    } while(token_leido != FDT);

    return 0;
}