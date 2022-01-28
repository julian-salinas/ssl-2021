#ifndef SYMBOL_H_INCLUDED
#define SYMBOL_H_INCLUDED

#include "parser.h"
#include "semantic.h"

typedef struct {
    int cantidad_elementos;
    char *identificador;
    struct ListaIdentificadores* siguiente;
}ListaIdentificadores;

ListaIdentificadores* inicializar_lista_identificadores(ListaIdentificadores*);
void agregar_identificador(char*);
int identificador_ya_declarado(char*);

ListaIdentificadores* lista_identificadores_declarados;

#endif 
