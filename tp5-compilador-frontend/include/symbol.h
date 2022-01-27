#ifndef SYMBOL_H_
#define SYMBOL_H_

#include "parser.h"
#include "semantic.h"
#include "generadores.h"

typedef struct ListaIdentificadores {
    int cantidad_elementos;
    char *identificador;
    struct ListaIdentificadores* siguiente;
}ListaIdentificadores;

ListaIdentificadores* inicializar_lista_identificadores(ListaIdentificadores*);
void agregar_identificador(char*);
void imprimir_lista_identificadores(ListaIdentificadores*);
int identificador_ya_declarado(char*);

ListaIdentificadores *lista_identificadores_declarados = NULL;

#endif