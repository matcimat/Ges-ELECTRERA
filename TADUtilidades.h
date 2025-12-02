/*
    Librería de utilidades y constantes
*/

#pragma once


const int MAX_STRING_LENGTH = 21;
typedef char TipoCadena[MAX_STRING_LENGTH];


typedef int TipoFechas[12];
const TipoFechas DIAS_EN_MES = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const TipoFechas DIAS_EN_MES_BISIESTO = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


const char RAPIDO = 'R';
const char SEMI = 'S';
const char LENTO = 'L';

typedef struct TipoUtilidades{

    bool es_fecha_valida(int day, int month, int year);
    bool es_anio_bisiesto(int year);
    bool es_hora_valida(int hora, int minuto);
};
