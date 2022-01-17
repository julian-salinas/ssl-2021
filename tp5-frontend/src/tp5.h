/* En este archivo van todos los imports del tp (ademas de defines necesarios) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generadores.h"

#define generar_codigo_seudo(...) generar_codigo_seudo_default((argumentos_esperados_impresion){__VA_ARGS__})