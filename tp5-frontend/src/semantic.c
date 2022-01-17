#include "tp5.h"

/*
Funciones que hay que hacer (las que ya están hechas, tienen una X):
    - comenzar (cargar_programa) X
    - finalizar (finalizar_programa) X
    - leer
    - escribir
    - generar_infijo
    - declarar_variable
    - variable_ya_esta_declarada
    - declarar_variable
    - asignar
    
También, ver como hacer con los operadores unarios
*/

void cargar_programa(char* nombre_programa) {
    generar_codigo_seudo("Load rtlib", nombre_programa);
    return;
}


void finalizar_programa() {
    generar_codigo_seudo("Exit");
    return;
}


// Esto está puesto para probar que funcione
int main(void) {
    cargar_programa("hola");
    finalizar_programa();
    return 0;
}