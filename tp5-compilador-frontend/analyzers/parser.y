%code top {
    #include "semantic.h"
    #include "symbol.h"
    #include "scanner.h"
}

%code provides {

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    void yyerror(const char *);
    extern char buffer[120];
    extern int yylexerrs;
    extern int yysemerrs;

}


%define api.value.type {char *}
%define parse.error verbose

%start programa_mini

%token ENTERO LEER ESCRIBIR PROGRAMA FIN_PROGRAMA IDENTIFICADOR CONSTANTE ASIGNACION

%left '+' '-'
%left '*' '/' '%'
%precedence NEG

%%

programa_mini: PROGRAMA IDENTIFICADOR { cargar_programa($2); } lista_sentencias FIN_PROGRAMA 
                { finalizar_programa(); if (yynerrs || yylexerrs) YYABORT; else YYACCEPT; };


sentencia:    IDENTIFICADOR ASIGNACION expresion ';' {asignar($1, $3); }
            | ENTERO IDENTIFICADOR ';'  { if (declarar_entero($3)) YYERROR; }
            | LEER '(' lista_identificadores ')' ';' 
            | ESCRIBIR '(' lista_expresiones ')' ';' 
            | error ';'
            ;

lista_sentencias: sentencia lista_sentencias 
                | %empty
                ;

lista_expresiones:   lista_expresiones ',' expresion { escribir($3); }
                    | expresion { escribir($1); }
                    ;

lista_identificadores:    lista_identificadores ',' identificador { leer($3); }
                        | identificador { leer($1); }
                        ;

identificador:  IDENTIFICADOR { if (identificador_ya_declarado($1)) YYERROR; }

expresion:    expresion '+' expresion { $$ = generar_infijo($1, '+', $3); }
            | expresion '-' expresion { $$ = generar_infijo($1, '-', $3); }
            | '-' expresion %prec NEG { generar_unario($2); }
            | expresion '*' expresion { $$ = generar_infijo($1, '*', $3); }
            | expresion '/' expresion { $$ = generar_infijo($1, '/', $3); }
            | expresion '%' expresion { $$ = generar_infijo($1, '%', $3); }
            | '(' expresion ')' { $$ = $2; }
            | CONSTANTE
            | IDENTIFICADOR
            ;
%%

void yyerror(const char *msg) {
    printf("Línea #%d: %s\n", yylineno, msg);
    return;
}
