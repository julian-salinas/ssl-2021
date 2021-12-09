%code top {
    #include <stdio.h>
    #include "scanner.h"
}

%code provides {
    void yyerror(char const *);
    extern int yylexerrs;
}

%defines "parser.h"
%output "parser.c"

%start programa-mini

%define api.value.type {char *}

%token ENTERO LEER ESCRIBIR PROGRAMA FIN_PROGRAMA IDENTIFICADOR CONSTANTE
%token ASIGNACION "<<"

%left '+' '-'
%left '*' '/' '%'
%precedence NEG

%%
programa-mini: PROGRAMA IDENTIFICADOR {printf("Programa %s \n", yylval);} lista-sentencias FIN_PROGRAMA { if (yynerrs || yylexerrs) YYABORT; else YYACCEPT; };

lista-sentencias: sentencia
                | sentencia lista-sentencias
                | %empty
                ;

sentencia: IDENTIFICADOR ASIGNACION expresion ';' {printf("Asignacion \n");}
         | ENTERO IDENTIFICADOR ';'  {printf("Entero %s \n", yylval);}
         | LEER '(' lista-identificadores ')' ';' {printf("Leer \n");}
         | ESCRIBIR '(' lista-expresiones ')' ';' {printf("Escribir \n");}
         ;

lista-expresiones: expresion lista-expresiones
                 | expresion
                 ;

expresion: expresion '+' expresion {printf("suma\n");}
        | expresion '-' expresion {printf("resta\n");}
        | expresion '*' expresion {printf("multiplicación\n");}
        | expresion '/' expresion {printf("división\n");}
        | expresion '%' expresion {printf("modulo\n");}
        | '-' expresion %prec NEG {printf("inversión\n");}
        | '(' expresion ')' {printf("paréntesis\n");}
        | IDENTIFICADOR
        | CONSTANTE
        ;

lista-identificadores: IDENTIFICADOR ',' lista-identificadores
                     | IDENTIFICADOR
                     ;

%%

void yyerror(const char *msg){
    printf("Error en la línea %d: %s: ", yylineno, msg);
    return;
}
