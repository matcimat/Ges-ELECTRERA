/*
    Librería de utilidades y constantes
*/

#pragma once
#include "TADCalendario.h"


const int MAX_STRING_LENGTH = 21;
typedef char TipoCadena[MAX_STRING_LENGTH];
typedef char TipoRellenaCeros[4];
typedef char TipoIdReserva[18];
typedef char TipoCorriente[3];


const char RAPIDO = 'R';
const char SEMI = 'S';
const char LENTO = 'L';



 TipoFecha TransformarFechaHora(int p_dia, int p_mes, int p_anio, int p_hora , int p_minuto);
 bool es_anio_bisiesto(int anio);
 int FechaSecuencia(int dia , int mes , int anio);
 int ReservaSecuencia(int dia, int mes, int anio , int hora, int minuto);
 bool ValidarReserva(int R_Inicio, int R_Final, int T_Inicio , int T_Final);
void minus_a_mayus_corriente(TipoCorriente &cadena);
