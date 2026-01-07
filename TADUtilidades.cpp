#include "TADUtilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



bool ValidarReserva(int R_Inicio, int R_Final, int T_Inicio , int T_Final){

  /* R_Inicio y R_Final es el intervalo de la reserva */
  /* T_Inicio y T_Final es el intervalo del tramo de una reserva existente */

 for(int i=T_Inicio;i<=T_Final;i++){
  /* Vamos recorriendo los minutos de la reserva */
  if(i>=R_Inicio && i< R_Final){
    /* el minuto i que está en una reserva previs, está dentro del intervalo que queremos reservar */
    /* por lo que no se puede hacer la reserva por no haber hueco completo libre */
    return false;
  }
 }

 return true;
}

void minus_a_mayus_corriente(TipoCorriente &cadena){

  /* Aqui convertimos la cadena apuntada por el puntero a mayusculas */
  int longitud;
  longitud=strlen(cadena);
  for(int i=0;i<longitud;i++){
    cadena[i]=toupper(cadena[i]);
  }

}

TipoFecha TransformarFechaHora(int p_dia, int p_mes, int p_anio, int p_hora , int p_minuto){

  TipoFecha fecha;
  fecha.dia=p_dia;
  fecha.mes=p_mes;
  fecha.anio=p_anio;
  fecha.horas=p_hora;
  fecha.minutos=p_minuto;

  return fecha;
}


bool es_anio_bisiesto(int anio){
    return ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0));

}

int FechaSecuencia(int dia , int mes , int anyo){
 /* Devuelve el numero de días que han pasado desde el 01/01/2025 hasta la fecha indicada */

 int SecuenciaDias = 0;
 bool bisiesto = false;


 /* Primero vamos a ver si hay años que contar */
 if(anyo>2025){
   for(int i=2025;i<anyo;i++){
    if(es_anio_bisiesto(i)){
      bisiesto = true;
      SecuenciaDias = SecuenciaDias+366;
    }else{
      bisiesto = false;
      SecuenciaDias = SecuenciaDias+365;
    }
   }
 }
  /* Ya tenemos los años , ahora vamos con los meses */
  if(mes>1){
   for(int i=1;i<mes;i++){
    if(bisiesto==false){
     SecuenciaDias = SecuenciaDias+DIAS_EN_MES[i-1];
    }else{
     SecuenciaDias = SecuenciaDias+DIAS_EN_MES_BISIESTO[i-1];
    }
   }
  }

  /* Ya tenemos los meses , ahora ya sumamos los dias */

  SecuenciaDias = SecuenciaDias+dia-1;

  return SecuenciaDias;

 }

 int ReservaSecuencia(int dia, int mes, int anyo , int hora , int minutos){
 /* En esta función pasamos la Fecha secuencia a minutos y le sumamos los minutos correspondientes a la hora pasada */

 int fecha_minutos;
 int dia_minutos;

 fecha_minutos = FechaSecuencia(dia, mes , anyo) * 24 * 60;
 dia_minutos = hora*60 + minutos - 1;

 return fecha_minutos + dia_minutos;

}
