#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

#include "parser.h"
#include "symbol.h"

extern struct simbolo *tablaSimbolos;

void cargar_programa(char*);
void finalizar_programa();

void asignar(char *valorL, char *valorR);
int declarar_entero(char*);
int declarado_previamente(char *simbolo);
void enviar_mensaje_error(char* simbolo, char* status);
char *declarar_nuevo_temporal();

void leer(char *valorL);
void escribir(char *simbolo);

char *generar_unario(char *operando);
char *generar_infijo(char *operandoIzq, int operador, char *operandoDer);

// Esto es para imprimir codigo de seudo ensamblador
typedef struct {
    char* operacion;
    char* primer_parametro;
    char* segundo_parametro;
    char* tercer_parametro;
} argumentos_esperados_impresion;

void generar_codigo_seudo_base(char*, char*, char*, char*);
void generar_codigo_seudo_default(argumentos_esperados_impresion);
char* agregar_prefijo_coma(char*);

#define generar_codigo_seudo(...) generar_codigo_seudo_default((argumentos_esperados_impresion){__VA_ARGS__})


#endif 
