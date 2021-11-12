%top{
#include "tokens.h"
}
%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput

digito_decimal     [0-9]
letra              [a-zA-Z] 
espacio            [[:space:]]
identificador      {letra}({letra}|{digito_decimal})* 
constante_entera   {digito_decimal}+

%%
entero                                                        return ENTERO;
leer                                                          return LEER;
escribir                                                      return ESCRIBIR;
programa                                                      return PROGRAMA;
fin-programa                                                  return FINPROGRAMA;
{identificador}                                               return IDENTIFICADOR;
{constante_entera}                                            return CONSTANTE;
"<<"                                                          return ASIGNACION;
"+"                                                           return '+';
"-"                                                           return '-';
"*"                                                           return '*';
"/"                                                           return '/';
"("                                                           return '(';
")"                                                           return ')';
","                                                           return ',';
";"                                                           return ';';
{constante_entera}({letra}|{digito_decimal})*                 printf("Error léxico: constante inválida: %s\n", yytext);
{espacio}+                                                    ;
"//"(.)*                                                      ;
.                                                             printf("Caracter no valido: %s\n", yytext);