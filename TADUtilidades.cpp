#include "TADUtilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


bool TipoUtilidades::es_fecha_valida(int day, int month, int year) {

    if (year < 2025 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    if (es_anio_bisiesto(year)) {
        if (day > DIAS_EN_MES_BISIESTO[month - 1]) {
        return false;
        }
    }else if (day > DIAS_EN_MES[month - 1]) {
        return false;
    }

    return true;
}


bool TipoUtilidades::es_hora_valida(int hora, int minuto)
{
   if (hora < 0 || minuto < 0 || hora > 24 || minuto > 59 ) {
      return false;
  }


}



/*
    Calcula si un año es bisiesto
*/
bool TipoUtilidades::es_anio_bisiesto(int year){
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
