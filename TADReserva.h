#pragma once
#include "TADCalendario.h"

/* YYYY-MM-DD_HH:MM */
typedef char TipoIdentificador[20];

typedef struct TipoReserva{

    TipoIdentificador Identificador;
    int id;
    TipoFecha Inicio;
    TipoFecha Final;
    int ts_inicio;
    int ts_final;
    int duracion;
    int rodajas;

};
