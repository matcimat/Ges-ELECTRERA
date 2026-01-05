#include <stdio.h>
#include <string.h>
#include "TADPunto.h"
#include "TADCalendario.h"
#include "TADReserva.h"



void TipoPunto::CrearPtoRecarga(int p_id, int p_nivel, int p_rodaja){

      PtoEnUso=true;
      nivel=p_nivel;
      rodaja=p_rodaja;
      printf("\n\tCreado el punto %2d de nivel %d y rodaja %2d.",p_id,p_nivel,p_rodaja);

}

void TipoPunto::ImprimirPtoRecarga(int p_id_electrolinera , int p_id_punto){
  if(PtoEnUso==true){
    printf("\tEl punto de recarga %2d tiene el nivel %2d.\n",p_id_punto,nivel);
    /* ListarReservas(); */
  }else{
    printf("\tEl punto de recarga %2d no est%c definido.\n",p_id_punto,160);
  }

}

int TipoPunto::BuscarReserva(TipoFecha p_inicio , TipoFecha p_final){
  /* Busca si está libre el hueco de la reserva en en punto indicado */
  return 0;

}
void TipoPunto::AnadirReserva(TipoFecha p_inicio , int p_duracion){


  UltimaReserva++;
  /* Comprobaremos que tenemos hueco en el vector de reservas */

  if(UltimaReserva==100){
    return;
  }else{
    /* Creamos la reserva */
    Reservas[UltimaReserva].Inicio=p_inicio;
    Reservas[UltimaReserva].duracion=p_duracion;
    strcpy(Reservas[UltimaReserva].Identificador,"Sergio");
    Reservas[UltimaReserva].ts_inicio=100;
    Reservas[UltimaReserva].ts_final=150;

  }


}

int TipoPunto::ListarReservas(int p_mes,int p_anio){

 int contador=0;
  if(UltimaReserva>0){
    for(int i=1;i<=UltimaReserva;i++){
      if((Reservas[i].Inicio.mes==p_mes) && (Reservas[i].Inicio.anio==p_anio)){
        printf("\t\tReserva %d : inicio %02d-%02d-%02d con duracion %02d\n" , i , Reservas[i].Inicio.dia,Reservas[i].Inicio.mes,Reservas[i].Inicio.anio,Reservas[i].duracion);
        contador++;
      }
    }
  }
  return contador;
}

void TipoPunto::CalendarioPunto(int p_mes, int p_anio){

  TipoVectorDiasOcupados ocupacion = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  TipoFecha fecha_max_ocupa;
  Calendario calendario;
  int dia_maximo=0;
  float maximo=0.0;
  int contador=0;
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
    /* TODO: El % de uso del maximo dia no se pinta bien */
    maximo = float((dia_maximo/1440)*100);
  }




  printf("\n\n\t\t\t Ocupaci%cn Punto de Recarga: %d\n",162,identificador);
  printf("\t\t\t Electrolinera: %d\n",1);

  calendario.mostrar_calendario(p_anio, p_mes, ocupacion);

  printf("\n\nPunto de Carga %d - N%d\n",identificador,nivel);
  printf("Dia de m%cxima ocupaci%cn: %02d-%02d-%04d (%d minutos)\n",160,162,fecha_max_ocupa.dia,p_mes,p_anio,dia_maximo);

}

