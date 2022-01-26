#ifndef SYMBOL_H_
#define SYMBOL_H_

typedef struct ListaIdentificadores {
    int cantidad_elementos;
    char *identificador;
    struct ListaIdentificadores* siguiente;
}ListaIdentificadores;

ListaIdentificadores* inicializar_lista_identificadores(ListaIdentificadores*);
void agregar_identificador(ListaIdentificadores**, char*);
void imprimir_lista_identificadores(ListaIdentificadores*);
int identificador_ya_declarado(ListaIdentificadores*, char*);

ListaIdentificadores *lista_identificadores = NULL;

#endif