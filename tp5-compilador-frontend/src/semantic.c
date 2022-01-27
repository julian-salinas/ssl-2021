#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"

void cargar_programa(char* nombre_programa) {
    generar_codigo_seudo("Load rtlib", nombre_programa);
    return;
}

void finalizar_programa() {
    generar_codigo_seudo("Exit");
    return;
}

void asignar(char* valorL, char* valorR) {
    generar_codigo_seudo("Reserve", valorR, valorL);
    free(valorL);
    free(valorR);
}

int declarar_entero(char* nombre) {
    if (identificador_ya_declarado(nombre)) {
        enviar_mensaje_error(nombre, "ya fue declarado");
        return 1;
    }

    agregar_identificador(nombre);
    generar_codigo_seudo("Reserve", nombre, "4");
    return 0;
}

char *declarar_nuevo_temporal() {
    sprintf(buffer, "Temp#%d", ++cantidad_temporales);
    char *temporal = strdup(buffer);
    declarar_entero(temporal);
    return temporal;
}

void enviar_mensaje_error(char* nombre_identificador, char* situacion) {
    yysemerrs++;
    sprintf(buffer, "Error semántico: identificador %s %s ", nombre_identificador, situacion);
    yyerror(buffer);
    return;
}

void escribir(char* valor) {
    generar_codigo_seudo("Write", valor, "Integer");
    free(valor);
}

void leer(char* valor) {
    generar_codigo_seudo("Read", valor, "Integer");
    free(valor);
}

