#ifndef SEMANTIC_H_
#define SEMANTIC_H_

#include "generadores.h"
#include "symbol.h"
#include "parser.h"

void cargar_programa(char*);
void finalizar_programa();
void asignar(char*, char*);
int declarar_entero(char*);
void enviar_mensaje_error(char*, char*);
void leer(char*);
void escribir(char*);
char *declarar_nuevo_temporal();


#endif