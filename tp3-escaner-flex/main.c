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
            
            /* Caracteres de puntuacion */
            case ASIGNACION:    
                strcpy(resultado, "Token: Asignación");
                break;
            
            case OP_SUMA:
                strcpy(resultado, "Token: Operador Suma");
                break;

            case OP_RESTA:
                strcpy(resultado, "Token: Operador Resta");
                break;

            case OP_MULTIPLICACION:
                strcpy(resultado, "Token: Operador Multiplicación");
                break;

            case OP_DIVISION:
                strcpy(resultado, "Token: Operador División");
                break;

            case COMA:
                strcpy(resultado, "Token: Coma");
                break;

            case PAREN_IZQ:
                strcpy(resultado, "Token: Paréntesis Izquierdo");
                break;

            case PAREN_DER:
                strcpy(resultado, "Token: Paréntesis Derecho");
                break;

            case PUNTO_COMA:
                strcpy(resultado, "Token: Punto y Coma");
                break; 
            
            /* Palabra Reservada */

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