#ifndef SCANNERH
#define SCANNERH

enum TOKENS { FDT, SEP, CAD }; // fin de texto, separador, cadena

int get_token();
int still_string(char);

char buffer[140];

#endif