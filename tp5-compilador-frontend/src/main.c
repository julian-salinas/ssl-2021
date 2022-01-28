#include "parser.h"
#include "symbol.h"

int yylexerrs = 0;
extern int yynerrs;
int yysemerrs = 0;

int main(int argc, const char *argv[]){
    lista_identificadores_declarados = NULL;
    // switch(yyparse()) {
    //     case 0: 
    //         printf("Compilación terminada con éxito\n");
    //         break;
        
    //     case 1: 
    //         printf("Errores de compilación\n");
    //         break;
        
    //     case 2:
    //         printf("Memoria insuficiente\n");
    //         break;
    // }

    // printf("Errores sintácticos: %d - Errores léxicos: %d - Errores semánticos: %d\n", yynerrs, yylexerrs, yysemerrs);

    declarar_nuevo_temporal();
    declarar_nuevo_temporal();
    declarar_nuevo_temporal();


    printf("\nLista de identificadores declarados:\n");
    ListaIdentificadores* actual = lista_identificadores_declarados;
    while (actual != NULL) {
        printf("%s\n", actual->identificador);
        actual = actual->siguiente;
        if (!actual) {
            printf("\n");
        }
    }

    return 0;
}
