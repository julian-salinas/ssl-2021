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
                strcat(strcpy(resultado, "Token: Constante \t\t Lexema: "), yytext);
                break;  
            
            /* Caracteres de puntuacion */
            case ASIGNACION:    
                strcpy(resultado, "Token: Asignación");
                break;
            
            case '+':
                strcpy(resultado, "Token: '+'");
                break;

            case '-':
                strcpy(resultado, "Token: '-");
                break;

            case '*':
                strcpy(resultado, "Token: '*'");
                break;

            case '/':
                strcpy(resultado, "Token: '/'");
                break;

            case '%':
                strcpy(resultado, "Token: '\%'");
                break;

            case ',':
                strcpy(resultado, "Token: ','");
                break;

            case '(':
                strcpy(resultado, "Token: '('");
                break;

            case ')':
                strcpy(resultado, "Token: ')'");
                break;

            case ';':
                strcpy(resultado, "Token: ';'");
                break; 
            
            /* Palabra Reservada */

            case ENTERO:
                strcpy(resultado, "Token: entero");
                break;

            case LEER:
                strcpy(resultado, "Token: leer");
                break;

            case ESCRIBIR:
                strcpy(resultado, "Token: escribir");
                break;

            case PROGRAMA:
                strcpy(resultado, "Token: programa");
                break;

            case FIN_PROGRAMA:
                strcpy(resultado, "Token: fin-programa");
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