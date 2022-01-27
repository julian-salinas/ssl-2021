#ifndef GENERADORES_H_
#define GENERADORES_H_

#include "parser.h"
#include "semantic.h"
#include "symbol.h"

#define generar_codigo_seudo(...) generar_codigo_seudo_default((argumentos_esperados_impresion){__VA_ARGS__})

typedef struct {
    char* operacion;
    char* primer_parametro;
    char* segundo_parametro;
    char* tercer_parametro;
} argumentos_esperados_impresion;

int cantidad_temporales = 0;

void generar_codigo_seudo_base(char*, char*, char*, char*);
void generar_codigo_seudo_default(argumentos_esperados_impresion);

char* agregar_prefijo_coma(char*);
char *generar_infijo(char*, int, char*);
char *generar_unario(char*);

#endif
