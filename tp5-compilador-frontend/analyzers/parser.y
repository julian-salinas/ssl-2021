%code top {
    #include <stdio.h>
    #include "scanner.h"
    #include "semantic.h"
    #include "symbol.h"
    #include "generadores.h"
}

%code provides {
    void yyerror(const char *);
    extern int yylexerrs;

    extern char buffer[120];

}

%defines "parser.h"
%output "parser.c"

%define api.value.type {char *}
%define parse.error verbose

%start programa_mini

%token ENTERO LEER ESCRIBIR PROGRAMA FIN_PROGRAMA IDENTIFICADOR CONSTANTE ASIGNACION

%left '+' '-'
%left '*' '/' '%'
%precedence NEG

%%

programa_mini: PROGRAMA IDENTIFICADOR { cargar_programa($2); } lista_sentencias FIN_PROGRAMA 
                { if (yynerrs || yylexerrs) YYABORT; else YYACCEPT; };

lista_sentencias: sentencia lista_sentencias 
                | %empty
                ;

sentencia:    IDENTIFICADOR ASIGNACION expresion ';' {asignar($1, $3); }
            | ENTERO IDENTIFICADOR ';'  { printf("entero %s\n", yylval); }
            | LEER '(' lista_identificadores ')' ';' { printf("leer\n"); }
            | ESCRIBIR '(' lista_expresiones ')' ';' { printf("escribir\n"); }
            | error ';'
            ;

lista_expresiones:    lista_expresiones expresion 
                    | expresion
                    ;

expresion:    expresion '+' expresion { $$ = generar_infijo($1, '+', $3); }
            | expresion '-' expresion { $$ = generar_infijo($1, '-', $3); }
            | '-' expresion %prec NEG { $$ = generar_unario($2); }
            | expresion '*' expresion { $$ = generar_infijo($1, '*', $3); }
            | expresion '/' expresion { $$ = generar_infijo($1, '/', $3); }
            | expresion '%' expresion { $$ = generar_infijo($1, '%', $3); }
            | '(' expresion ')' { $$ = $2; }
            | CONSTANTE
            | IDENTIFICADOR
            ;

lista_identificadores:    lista_identificadores ',' IDENTIFICADOR 
                        | IDENTIFICADOR
                        ;

%%

void yyerror(const char *msg) {
    printf("Línea #%d: %s\n", yylineno, msg);
    return;
}
