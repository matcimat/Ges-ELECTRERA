#pragma once
#include "TADCalendario.h"


typedef struct TipoReserva{


    int id;
    TipoFecha Inicio;
    TipoFecha Final;
    int ts_inicio;
    int ts_final;
    int duracion;
    int rodajas;

bool ValidarReserva(int T_Inicio , int T_Final);
void GrabarReserva(int id,TipoFecha p_inicio,int p_duracion,int ts_inicio,int ts_final);
};
