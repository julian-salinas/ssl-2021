#include <stdio.h>
#include <stdlib.h>
#include "generadores.h"
#include "semantic.h"
#include "symbol.h"
#include "valores.h"


void cargar_programa(char* nombre_programa) {
    generar_codigo_seudo("Load rtlib", nombre_programa);
    return;
}

void finalizar_programa() {
    generar_codigo_seudo("Exit");
    return;
}

void asignar(char *valorL, char *valorR) {
    generar_pseudo("Reserve", valorR, valorL);
    free(valorL);
    free(valorR);
}

int declarar_entero(char *nombre) {
    if (identificador_ya_declarado(lista_identificadores, nombre)) {
        enviar_mensaje_error(nombre, "ya fue declarado");
        return 1;
    }

    agregar_identificador(&lista_identificadores, nombre);
    generar_pseudo("Reserve", nombre, "4");
    return 0;
}

void enviar_mensaje_error(char* nombre_identificador, char* situacion) {
    errores_semanticos++;
    sprintf(buffer, "Error semántico: identificador %s %s ", nombre_identificador, situacion);
    yyerror(buffer);
    return;
}
