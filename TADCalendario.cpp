#include "TADCalenatio.h"



bool TipoFecha::es_fecha_valida(TipoFecha p_fecha) {

    if (p_fecha.anio < 2025 || p_fecha.mes < 1 || p.fecha_mes > 12 || p.fecha_dia < 1) {
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
