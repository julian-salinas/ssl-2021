#include "symbol.h"

void agregar_identificador(char* identificador) {
    ListaIdentificadores* nuevo = malloc(sizeof(ListaIdentificadores));
    nuevo->identificador = identificador;
    nuevo->siguiente = *(&lista_identificadores_declarados);
    *(&lista_identificadores_declarados) = nuevo;
}

int identificador_ya_declarado(char* identificador) {
    // devuelve 1 si el identificador ya está declarado, 0 si no lo está
    ListaIdentificadores* actual = lista_identificadores_declarados;

    while (actual != NULL) {
        if (strcmp(actual->identificador, identificador) == 0) {
            return 1;
        }
        actual = actual->siguiente;
    }

    return 0;
}
