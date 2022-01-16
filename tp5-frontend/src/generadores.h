#ifndef GENERADORESH
#define GENERADORESH

typedef struct {
    char* operacion;
    char* primer_parametro;
    char* segundo_parametro;
    char* tercer_parametro;
} argumentos_default;

void generar_codigo_seudo_base(char*, char*, char*, char*);
void generar_codigo_seudo_default(argumentos_default);
char* agregar_prefijo_coma(char* valor);

#endif