#include <string.h>
#include <stdio.h>
#include "TADElectrolinera.h"
#include "Constantes.h"

const int MAX_PUNTOS_ELECTROLINERA = 20;


int TipoElectrolinera::CrearElectroninera(TipoNombreElectrolinera p_nombre, int p_npuntos_r, int p_npuntos_s, int p_npuntos_l,
                         TipoUbicacionElectrolinera p_tipo, float p_latitud, float p_longitud){

  bool datoscorrectos = true;
  int codigoretorno = 0;

  /* Primero tenemos que validar los datos introducidos y sólo si pasan las validaciones crear la electrolinera   */
  /* Debemos comprobar la calidad de todos los datos introducidos, que sean numeros enteros, positivos, la ubicación, etc etc */
  /* TODO : Validacion de datos creacion Electrolinera */

  /* Tambien comprobamos que el numero de puntos de recarga no exceda el maximo */

  if(p_npuntos_r+p_npuntos_s+p_npuntos_l > MAX_PUNTOS_ELECTROLINERA){
    datoscorrectos = false;
    codigoretorno = 1;
    printf("Falla creaci%cn Electrolinera. Excedido n%cmero de puntos de recarga. \n", 162,163);
  }




  if(datoscorrectos==false){
    return codigoretorno;  /* Devolvemos 1 indicando que ha habido errores */
  }


  /* Si llegamos a este punto es que los datos son correctos y vamos a crear la electrolinera */
  strcpy(nombre,p_nombre);
  NPtosRapidos=p_npuntos_r;
  NPtosSemi=p_npuntos_s;
  NPtosLentos=p_npuntos_l;
  tipo=p_tipo;
  latitud=p_latitud;
  longitud=p_longitud;
  return codigoretorno;  /* Devolvemos 0 para indicar que no ha habido errores */
  }

void TipoElectrolinera::ImprimirElectrolinera(int p_identificador){
  printf("La Elec=%d ,nombre=%s , tipo=%c , Puntos: %d , %d , %d , latitud=%f , longitud=%f \n",p_identificador,nombre,tipo,
          NPtosRapidos,NPtosSemi,NPtosLentos,latitud,longitud);
}



