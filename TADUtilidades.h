/*
    Librería de utilidades y constantes
*/

#pragma once
#include "TADCalendario.h"


extern bool modo_debug;
const int MAX_STRING_LENGTH = 21;
typedef char TipoCadena[MAX_STRING_LENGTH];
typedef char TipoRellenaCeros[4];
typedef char TipoIdReserva[18];
typedef char TipoCorriente[3];



 TipoFecha TransformarFechaHora(int p_dia, int p_mes, int p_anio, int p_hora , int p_minuto);
 bool es_anio_bisiesto(int anio);
 int FechaSecuencia(int dia , int mes , int anio);
 int ReservaSecuencia(int dia, int mes, int anio , int hora, int minuto);
 void minus_a_mayus_corriente(TipoCorriente &cadena);
