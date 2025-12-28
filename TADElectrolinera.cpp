#include <string.h>
#include <stdio.h>
#include "TADElectrolinera.h"
#include "TADPunto.h"
#include "Constantes.h"

const int MAX_PUNTOS_ELECTROLINERA = 20;


void TipoElectrolinera::CrearElectroninera(TipoNombreElectrolinera p_nombre, int p_npuntos_r, int p_npuntos_s, int p_npuntos_l,
                         TipoUbicacionElectrolinera p_tipo, float p_latitud, float p_longitud){



  /* Primero tenemos que validar los datos introducidos y sólo si pasan las validaciones crear la electrolinera   */
  /* Debemos comprobar la calidad de todos los datos introducidos, que sean numeros enteros, positivos, la ubicación, etc etc */
  /* TODO : Validacion de datos creacion Electrolinera */


  /* Tambien comprobamos que el numero de puntos de recarga no exceda el maximo */

  if(p_npuntos_r<0 || p_npuntos_r>MAX_PUNTOS_ELECTROLINERA ||
     p_npuntos_s<0 || p_npuntos_s>MAX_PUNTOS_ELECTROLINERA ||
     p_npuntos_l<0 || p_npuntos_l>MAX_PUNTOS_ELECTROLINERA) {
    printf("Falla la creaci%cn de Electrolinera. El N%cmero de puntos de recarga debe estar entre 0 y 20. \n", 162,163);
    throw 1;
  }


  if(p_npuntos_r+p_npuntos_s+p_npuntos_l > MAX_PUNTOS_ELECTROLINERA){
    printf("Falla la creaci%cn de Electrolinera. Excedido n%cmero de puntos de recarga. \n", 162,163);
    throw 1;
  }

  /* Si llegamos a este punto es que los datos son correctos y vamos a crear la electrolinera */
  strcpy(nombre,p_nombre);
  NPtosRapidos=p_npuntos_r;
  NPtosSemi=p_npuntos_s;
  NPtosLentos=p_npuntos_l;
  strcpy(tipo,p_tipo);
  latitud=p_latitud;
  longitud=p_longitud;
  ElectEnUso=true;

  /* Ahora vamos a crear los puntos de recarga */
  for(int i=1;i<=20;i++){
   CrearPuntoRecarga(i,0.0);
  }

  return;
}

void TipoElectrolinera::ImprimirElectrolinera(int p_identificador){
  if(ElectEnUso==true){
    printf("La Elec=%2d ,nombre=%s , tipo=%s , Puntos: %d , %d , %d , latitud=%f , longitud=%f \n",p_identificador,nombre,tipo,
            NPtosRapidos,NPtosSemi,NPtosLentos,latitud,longitud);
    /* Tambien Imprimios los puntos de Recarga, para ello le pasamos a la función el identificador de la electrolinera y el número del punto de recarga */
    for(int i=1;i<=20;i++){
      PuntosRecarga[i].ImprimirPtoRecarga(p_identificador,i);
    };
  }else{
   printf("La Elec=%2d no est%c en uso.\n",p_identificador,160);
  }
}

void TipoElectrolinera::CrearPuntoRecarga(int p_id, float p_potencia){
  if(PuntosRecarga[p_id].PtoEnUso==false){
    PuntosRecarga[p_id].Potencia=p_potencia;
    PuntosRecarga[p_id].PtoEnUso=true;
  }else{
    printf("El punto de recarga %2d ya est%c en uso.\n",p_id,160);
  }
}


