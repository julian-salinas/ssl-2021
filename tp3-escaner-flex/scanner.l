%top{
#include "tokens.h"
}

%option outfile="scanner.c"
%option header-file="scanner.h"
%option noinput
%option nounput

digito_decimal      [0-9]
letra               [a-zA-Z] 
espacio             [[:space:]]
identificador       {letra}({letra}|{digito_decimal})* 
constante_entera    {digito_decimal}+
cualquier_valor     . 
otros               [[:^alnum:]]{-}[[:space:]]{-}[-+*/();,>%]

%%
entero                               return ENTERO;
leer                                 return LEER;
escribir                             return ESCRIBIR;
programa                             return PROGRAMA;
fin-programa                         return FIN_PROGRAMA;
{identificador}                      return IDENTIFICADOR;
{constante_entera}                   return CONSTANTE;
"<<"                                 return ASIGNACION;
"+"                                  return '+';
"-"                                  return '-';
"*"                                  return '*';                                
"/"                                  return '/';
"%"                                  return '%';
","                                  return ',';
"("                                  return '(';
")"                                  return ')';
";"                                  return ';'; 
{espacio}+                           ;
"//".*                               ;


{identificador}{otros}({letra}|{digito_decimal}|{otros})*   printf("Error léxico: identificador inválido: %s\n", yytext);
{constante_entera}({letra}|{digito_decimal})*               printf("Error léxico: constante inválida: %s\n", yytext);
{otros}+                                                    printf("Cadena inválida: %s\n", yytext);
