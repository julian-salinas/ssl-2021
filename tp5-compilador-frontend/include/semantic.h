#ifndef SEMANTIC_H_
#define SEMANTIC_H_

#define generar_codigo_seudo(...) generar_codigo_seudo_default((argumentos_esperados_impresion){__VA_ARGS__})

void cargar_programa(char* nombre_programa);
void finalizar_programa();

#endif