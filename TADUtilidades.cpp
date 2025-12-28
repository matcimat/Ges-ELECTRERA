#include "TADUtilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


bool TipoUtilidades::es_fecha_valida(int dia, int mes, int anio) {

    if (anio < 2025 || mes < 1 || mes > 12 || dia < 1) {
        return false;
    }

    if (es_anio_bisiesto(anio)) {
        if (dia > DIAS_EN_MES_BISIESTO[mes - 1]) {
        return false;
        }
    }else if (dia > DIAS_EN_MES[mes - 1]) {
        return false;
    }

    return true;
}


bool TipoUtilidades::es_hora_valida(int hora, int minuto)
{
   if (hora < 0 || minuto < 0 || hora > 24 || minuto > 59 ) {
      return false;
  }
  return true;

}



/*
    Calcula si un año es bisiesto
*/
bool TipoUtilidades::es_anio_bisiesto(int anio){
    return ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0));

}



