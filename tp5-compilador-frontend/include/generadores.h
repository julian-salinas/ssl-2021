#ifndef GENERADORES_H_
#define GENERADORES_H_

#include "parser.h"

#define generar_codigo_seudo(...) generar_codigo_seudo_default((argumentos_esperados_impresion){__VA_ARGS__})

typedef struct {
    char* operacion;
    char* primer_parametro;
    char* segundo_parametro;
    char* tercer_parametro;
} argumentos_esperados_impresion;

void generar_codigo_seudo_base(char*, char*, char*, char*);
void generar_codigo_seudo_default(argumentos_esperados_impresion);
char* agregar_prefijo_coma(char* valor);
char *generar_infijo(char *operandoIzq, int operador, char *operandoDer);

#endif
