#include <stdio.h>
#include <string.h>
#include "TADPunto.h"
#include "TADCalendario.h"
#include "TADReserva.h"
#include "TADUtilidades.h"



void TipoPunto::CrearPtoRecarga(int p_id, int p_nivel, int p_rodaja){

      PtoEnUso=true;
      identificador=p_id;
      nivel=p_nivel;
      rodaja=p_rodaja;
      UltimaReserva=0;
      if(modo_debug){
        printf("\n\tCreado el punto %2d de nivel %d y rodaja %2d.",p_id,p_nivel,p_rodaja);
      }
      /* TODO: Asegurarse de que cuando se reutilza un punto de recarga se resetean las reservas */

}

void TipoPunto::ImprimirPtoRecarga(int p_id_electrolinera , int p_id_punto){
  if(PtoEnUso==true){
    printf("\tEl punto de recarga %d tiene el nivel %d y la rodaja es de %d minutos.\n",p_id_punto,nivel,rodaja);
    ListarTodasReservas();
  }else{
    /* printf("\tEl punto de recarga %2d no est%c definido.\n",p_id_punto,160) */;
  }

}

bool TipoPunto::AnadirReserva(TipoFecha p_inicio , int p_duracion){


  int ts_inicio=0;
  int ts_final=0;
  int ts_final_dia=0;
  int r;
  bool reserva_valida;
  int rodajas_necesarias=0;

  if(UltimaReserva==10000){
    printf("\n\tEste punto de recargas ha llegado a su l%cmite de reservas.",161);
    return false;
  }

 rodajas_necesarias = p_duracion/rodaja;
 if(p_duracion>rodajas_necesarias*rodaja){
   rodajas_necesarias++;
 }
 if(modo_debug){
  printf("\n\tLa duracion solicitada era de %2d , y la rodaja minima es de %2d, asi que necesitamos %2d rodajas",p_duracion,rodaja,rodajas_necesarias);
 }

  /* Vamos a calcular los minutos iniciales y finales de la reserva desde el 1/enero/2025 00:00 */
  ts_inicio=ReservaSecuencia(p_inicio.dia,p_inicio.mes,p_inicio.anio,p_inicio.horas,p_inicio.minutos);
  ts_final=ts_inicio + (rodajas_necesarias*rodaja);
  ts_final_dia=ReservaSecuencia(p_inicio.dia,p_inicio.mes,p_inicio.anio,23,59);
  if(ts_final>ts_final_dia){
    /* La duración de la reserva con la rodaja de este punto excede de las 23:59 horas del dia por lo que no sepuede hacer */
    printf("\n\tLa reserva excede la duración del d%ca indicado. Debe dividirla en 2 reservas, una para cada d%ca.",161,161);
    return false;
  }
  if(modo_debug){
    printf("\n\t Timestamp inicio %d , final %d , final_dia %d",ts_inicio,ts_final,ts_final_dia);
  }


  /* Comprobaremos que tenemos hueco en el vector de reservas */
  reserva_valida=true;
  r=0;
  while(reserva_valida==true && r<=UltimaReserva){
    r++;
    /* Vamos a recorrer todas las reservas del punto a ver si hay alguna reserva previa incompatible */
    reserva_valida=Reservas[r].ValidarReserva(ts_inicio,ts_final);
  } /* del while de reservas*/
  if(reserva_valida==true){
    /* Como no hemos encontrado ninguna reserva previa incompatible, la añadimos*/
    UltimaReserva++;
    Reservas[UltimaReserva].GrabarReserva(UltimaReserva,p_inicio,(rodaja*rodajas_necesarias),ts_inicio,ts_final);
    printf("\n\n\tReserva Correcta");
    printf("\n\t\tIdentificador: Punto de Recarga N%d-%d-%04d-%02d-%02d\n",nivel,identificador,UltimaReserva,p_inicio.mes,p_inicio.anio);
    printf("\t\tFecha y hora: %02d-%d-%4d %02d:%02d\n",p_inicio.dia,p_inicio.mes,p_inicio.anio,p_inicio.horas,p_inicio.minutos);
    printf("\t\tTiempo %d minutos (%dx%d)\n",(rodajas_necesarias*rodaja),rodajas_necesarias,rodaja);
    return true;
  } else {
    if(modo_debug){
      printf("\n\t\tEl punto %d no tiene hueco para esta reserva\n",identificador);
    }
    return false;
  } /* del else */



}

int TipoPunto::ListarReservas(int p_mes,int p_anio){

 int contador=0;
  if(UltimaReserva>0){
    for(int i=1;i<=UltimaReserva;i++){
      if((Reservas[i].Inicio.mes==p_mes) && (Reservas[i].Inicio.anio==p_anio)){
        printf("\t\tPunto de recarga %2d-%04d-%02d-%04d Fecha %02d-%02d-%02d Hora:%02d:%02d duraci%cn %3d min.\n ",
        identificador,i,Reservas[i].Inicio.mes,Reservas[i].Inicio.anio,Reservas[i].Inicio.dia,Reservas[i].Inicio.mes,Reservas[i].Inicio.anio,
        Reservas[i].Inicio.horas,Reservas[i].Inicio.minutos,162,Reservas[i].duracion);
        contador++;
      }
    }
  }
  return contador;
}


int TipoPunto::ListarTodasReservas(){

 int contador=0;
  if(UltimaReserva>0){
    for(int i=1;i<=UltimaReserva;i++){
      printf("\t\tReserva %d : inicio %02d-%02d-%02d con duracion %2d\n" , i , Reservas[i].Inicio.dia,Reservas[i].Inicio.mes,Reservas[i].Inicio.anio,Reservas[i].duracion);
      contador++;
    }
  }
  return contador;
}



void TipoPunto::CalendarioPunto(int id_ele, TipoNombreElectrolinera nombre,int id_pto, int p_mes, int p_anio){

  TipoVectorDiasOcupados ocupacion = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  TipoFecha fecha_max_ocupa;
  Calendario calendario;
  int dia_maximo=0;
  int maximo=0;
  fecha_max_ocupa.dia=0;
  fecha_max_ocupa.mes=p_mes;
  fecha_max_ocupa.anio=p_anio;

  /* Rellenamos el vector de los minutos reservados cada dia */
  if(UltimaReserva>0){
    for(int i=1;i<=UltimaReserva;i++){
      if((Reservas[i].Inicio.mes==p_mes) && (Reservas[i].Inicio.anio==p_anio)){
        ocupacion[Reservas[i].Inicio.dia-1]=ocupacion[Reservas[i].Inicio.dia-1]+Reservas[i].duracion;
      }
    }
    /* Recorremos la ocupacion de los dias para buscar el maximo */
    for(int i=1;i<=31;i++){
      if(ocupacion[i-1]>dia_maximo){
        dia_maximo=ocupacion[i-1];
        fecha_max_ocupa.dia=i;
      }
    }
    maximo = dia_maximo*100/1440;
  }




  printf("\n\n\t\t\t Ocupaci%cn Punto de Recarga: %2d\n",162,id_pto);
  printf("\t\t\t Electrolinera: %s\n",nombre);

  calendario.mostrar_calendario(p_anio, p_mes, ocupacion);

  printf("\n\nPunto de Carga %2d - N%d\n",id_pto,nivel);
  printf("Dia de m%cxima ocupaci%cn: %02d-%02d-%04d (%3d%%)\n",160,162,fecha_max_ocupa.dia,p_mes,p_anio,maximo);

}

