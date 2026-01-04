/*
    Librería de utilidades y constantes
*/

#pragma once


const int MAX_STRING_LENGTH = 21;
typedef char TipoCadena[MAX_STRING_LENGTH];
typedef char TipoRellenaCeros[4];
typedef char TipoIdReserva[18];


const char RAPIDO = 'R';
const char SEMI = 'S';
const char LENTO = 'L';

typedef struct TipoUtilidades{




    void RellenaCeros(int numero, TipoRellenaCeros &resultado);
    void GenerarIdReserva(int nivel , int punto , int numreserva,int mes, int anyo, TipoIdReserva &id_reserva);
    bool ValidarReserva(int R_Inicio, int R_Final, int T_Inicio , int T_Final);
};
