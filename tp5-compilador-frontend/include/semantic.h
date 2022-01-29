#ifndef SEMANTIC_H_INCLUDED
#define SEMANTIC_H_INCLUDED

#include "parser.h"
#include "symbol.h"

extern struct simbolo *tablaSimbolos;

void cargar_programa(char*);
void finalizar_programa();

void asignar(char*, char*);
int declarar_entero(char*);
int identificador_declarado_previamente(char*);
void enviar_mensaje_error(char*, char*);
char *declarar_nuevo_temporal();

void leer(char*);
void escribir(char*);

char *generar_unario(char*);
char *generar_infijo(char*, int, char*);

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
