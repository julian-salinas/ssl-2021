// TODO: Acá van las rutinas de diccionario (si un elemento existe, lista de identificadores, agregar elemento a la lista de identificadores,etc.)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

ListaIdentificadores* inicializar_lista_identificadores(ListaIdentificadores* lista_identificadores){
    lista_identificadores = (ListaIdentificadores*)malloc(sizeof(ListaIdentificadores));
    lista_identificadores->cantidad_elementos = 0;
    lista_identificadores->identificador = NULL;
    return lista_identificadores ; 
}

void agregar_identificador(ListaIdentificadores** lista, char *identificador) {
    struct ListaIdentificadores* nuevo = malloc(sizeof(struct ListaIdentificadores));
    nuevo->identificador = identificador;
    nuevo->siguiente = *lista;
    *lista = nuevo;
}

void imprimir_lista_identificadores(ListaIdentificadores* lista_identificadores) {
    ListaIdentificadores* actual = lista_identificadores;
    while (actual != NULL) {
        printf("%s\n", actual->identificador);
        actual = actual->siguiente;
    }
}

int identificador_ya_declarado(ListaIdentificadores* lista_identificadores, char* identificador) {
    // devuelve 1 si el identificador ya está declarado, 0 si no lo está
    ListaIdentificadores* actual = lista_identificadores;

    while (actual != NULL) {
        if (strcmp(actual->identificador, identificador) == 0) {
            return 1;
        }
        actual = actual->siguiente;
    }

    return 0;
}
