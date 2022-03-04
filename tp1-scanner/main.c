#include <stdio.h>
#include <string.h>
#include "scanner.h"

int main(int argc, const char *argv[]){
    int resultado;

    do{
        resultado = get_token();
        switch(resultado){
            case SEP:
                printf("Separador: %c\n", buffer[0]);
                buffer[0] = '\0';
                break;
            
            case CAD:
                printf("Cadena: %s\n", buffer);
                memset(buffer, 0, 140); // vaciar el buffer, funcion incluida en <string.h>
                break;
        }

    }while(resultado != FDT);

    printf("Fin de Texto\n");

    return 0;
}
