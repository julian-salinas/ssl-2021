#include "semantic.h"

int cantidad_temporales = 0;
char buffer[140];

void cargar_programa(char* nombre_programa) {
    generar_codigo_seudo("Load rtlib", nombre_programa);
    return;
}

void finalizar_programa() {
    generar_codigo_seudo("Exit");
    return;
}

void asignar(char* valor_izquierda, char* valor_derecha) {
    generar_codigo_seudo("Store", valor_derecha, valor_izquierda);
    free(valor_izquierda);
    free(valor_derecha);
}

void leer(char* valor) {
    generar_codigo_seudo("Read", valor, "Integer");
    free(valor);
}

void escribir(char* nombre) {
    generar_codigo_seudo("Write", nombre, "Integer");
    free(nombre);
}


int declarar_entero(char* nombre) {
    if (identificador_ya_declarado(nombre)) {
        enviar_mensaje_error(nombre, "ya fue declarado");
        return 1;
    }

    agregar_identificador(nombre);
    generar_codigo_seudo("Reserve", nombre, "4");
    printf("SE DECLARO %s\n", nombre);
    return 0;
}

int identificador_declarado_previamente(char* nombre) {
    if(!identificador_ya_declarado(nombre)) {
        enviar_mensaje_error(nombre, "no fue declarado");
        return 1;
    }
    return 0;
}

void enviar_mensaje_error(char* nombre_identificador, char* situacion) {
    yysemerrs++;
    sprintf(buffer, "Error semántico: identificador %s %s ", nombre_identificador, situacion);
    yyerror(buffer);
    return;
}


void generar_codigo_seudo_base(char* operacion, char* primer_parametro, char* segundo_parametro, char* tercer_parametro){
    /* IMPORTANTE: Cuando se usa esta función, se la llama por generar_codigo_seudo
        Esta función va a escribir el archivo output del programa */
    printf("%s %s%s%s\n", operacion, primer_parametro, segundo_parametro, tercer_parametro);

    return;
}

void generar_codigo_seudo_default(argumentos_esperados_impresion argumentos_recibidos) {
    /* Esta es la función que hay que llamar para generar el código, se encarga de establecer valores
    default en caso de no querer enviar N argumentos */

    // Crear array de variables que representan los argumentos
    // char *operacion, *primer_parametro, *segundo_parametro, *tercer_parametro;
    char *operacion = (char*) calloc(10, sizeof(char));
    char *primer_parametro = (char*) calloc(10, sizeof(char));
    char *segundo_parametro = (char*) calloc(10, sizeof(char));
    char *tercer_parametro = (char*) calloc(10, sizeof(char));
    
    char *argumentos[4] = {operacion, primer_parametro, segundo_parametro, tercer_parametro};

    // Establecer valores por defecto de ser necesario
    operacion = argumentos_recibidos.operacion ? argumentos_recibidos.operacion : ""; 
    primer_parametro = argumentos_recibidos.primer_parametro ? argumentos_recibidos.primer_parametro : "";

    // Al tercer y cuarto parámetro les agrego una coma al principio para que coincida con el formato del output
    segundo_parametro = argumentos_recibidos.segundo_parametro ? agregar_prefijo_coma(argumentos_recibidos.segundo_parametro) : ""; 
    tercer_parametro = argumentos_recibidos.tercer_parametro ? agregar_prefijo_coma(argumentos_recibidos.tercer_parametro) : ""; 

    // Llamar a función original 
    generar_codigo_seudo_base(operacion, primer_parametro, segundo_parametro, tercer_parametro);

    // Liberar memoria
    for (int i = 0; i < 4; i++) {
        free(argumentos[i]);
    }
}

char* agregar_prefijo_coma(char* valor) {
    /* Agregar una Coma al principio de una cadena */
    
    char* prefijo = ",";

    char* valor_con_prefijo = malloc(strlen(valor) + strlen(prefijo) + 1);
    strcpy(valor_con_prefijo, prefijo);
    strcat(valor_con_prefijo, valor);

    return valor_con_prefijo;
}

char *generar_infijo(char* operando_izquierdo, int operador, char* operando_derecho) {
    char *nuevo_temporal = declarar_nuevo_temporal();
    switch(operador) {
        case '+':
            generar_codigo_seudo("ADD", operando_izquierdo, operando_derecho, buffer);
            break;
        
        case '-':
            generar_codigo_seudo("SUB", operando_izquierdo, operando_derecho, buffer);
            break;
        
        case '*':
            generar_codigo_seudo("MUL", operando_izquierdo, operando_derecho, buffer);
            break;
        
        case '%':
            generar_codigo_seudo("MOD", operando_izquierdo, operando_derecho, buffer);
            break;

        case '/':
            generar_codigo_seudo("DIV", operando_izquierdo, operando_derecho, buffer);
            break;
        
    }
    return nuevo_temporal;
}

char *generar_unario(char* operando) {
    char *temporal = declarar_nuevo_temporal();
    generar_codigo_seudo("INV", operando, buffer);
    return temporal;
}

char *declarar_nuevo_temporal() {
    sprintf(buffer, "Temp@%d", ++cantidad_temporales);
    char *temporal = strdup(buffer);
    declarar_entero(temporal);
    return temporal;
}
