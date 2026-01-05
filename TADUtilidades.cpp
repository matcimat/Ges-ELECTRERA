#include "TADUtilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void TipoUtilidades::RellenaCeros(int numero, TipoRellenaCeros &resultado){

  typedef char TipoResultado[5];
  TipoResultado temp;
  strcpy(resultado,"");
  sprintf(temp,"%d",numero);

  if (numero >= 1000) {
    /* no hay que hacer nada */
  } else if (numero >= 100) {
      strcpy(resultado,"0");
  } else if (numero >= 10) {
      strcpy(resultado,"00");
  } else {
      strcpy(resultado,"000");
  }

  strcat(resultado,temp);

  /* printf("04d",numero) */

}

void TipoUtilidades::GenerarIdReserva(int nivel , int punto , int numreserva,int mes, int anyo, TipoIdReserva &id_reserva){

  TipoIdReserva tmp_id_reserva="N";
  char s_nivel;
  /* sprintf(s_nivel,"%d",nivel);*/

  /* strcat(tmp_id_reserva,s_nivel); */


  strcpy(id_reserva,tmp_id_reserva);

}

bool TipoUtilidades::ValidarReserva(int R_Inicio, int R_Final, int T_Inicio , int T_Final){

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

void TipoUtilidades::minus_a_mayus_corriente(TipoCorriente &cadena){

  /* Aqui convertimos la cadena apuntada por el puntero a mayusculas */
  int longitud;
  longitud=strlen(cadena);
  for(int i=0;i<longitud;i++){
    cadena[i]=toupper(cadena[i]);
  }

}

TipoFecha TipoUtilidades::TransformarFechaHora(int p_dia, int p_mes, int p_anio, int p_hora , int p_minuto){

  TipoFecha fecha;
  fecha.dia=p_dia;
  fecha.mes=p_mes;
  fecha.anio=p_anio;
  fecha.horas=p_hora;
  fecha.minutos=p_minuto;

  return fecha;
}
