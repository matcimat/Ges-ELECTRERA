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
  NPtosRapidos3=p_npuntos_r;
  NPtosSemi2=p_npuntos_s;
  NPtosLentos1=p_npuntos_l;
  strcpy(tipo,p_tipo);
  latitud=p_latitud;
  longitud=p_longitud;
  ElectEnUso=true;

  /* Ahora vamos a inicializar los puntos de recarga */
  for(int i=1;i<=20;i++){
   CrearPuntoRecarga(i,0.0,"IN",1);
  }

  return;
}

void TipoElectrolinera::ImprimirElectrolinera(int p_identificador){
  if(ElectEnUso==true){
    printf("La Electrolinera=%2d ,nombre=%s , tipo=%s , Puntos:R=%d , S=%d , L=%d , latitud=%f , longitud=%f \n",p_identificador,nombre,tipo,
            NPtosRapidos3,NPtosSemi2,NPtosLentos1,latitud,longitud);
    /* Tambien Imprimios los puntos de Recarga, para ello le pasamos a la función el identificador de la electrolinera y el número del punto de recarga */
    for(int i=1;i<=20;i++){
      PuntosRecarga[i].ImprimirPtoRecarga(p_identificador,i);
    };
  }else{
   printf("La Elec=%2d no est%c en uso.\n",p_identificador,160);
  }
}


void TipoElectrolinera::CrearPuntoRecarga(int p_id, float p_potencia, TipoCorriente p_tipo, int p_rodaja){

  int ant_nivel = 0;
  bool liberada = false;
  char reemplazar = 'x';

    /* Si la potencia es >0 creamos el punto */
    /* Si la potencia es <=0 liberamos ell punto */

  /* TODO: Hay que comprobar si el punto está en uso para sobrescribirlo y recuperar el slot del tipo de punto */

  if((p_id<1) || (p_id>20)){
    printf("\n *** ERROR:El n%cmero del punto de recarga debe estar entre 1 y 20.***\n ",163);
    return;
    /* throw 1; */
  }
  if((p_rodaja<1) || (p_rodaja>60)){
      printf("\n *** ERROR:El tama%co de la rodaja debe estar entre 1 y 60.***\n ",164);
      /* throw 1; */
  }
  if(PuntosRecarga[p_id].PtoEnUso==true){
    while(reemplazar != 'S' && reemplazar != 's' && reemplazar != 'N' && reemplazar != 'n'){
      printf("\nEl punto de recarga %2d , de nivel %d est%c en uso. %cDeseas reemplazarlo (S/N)?",p_id,PuntosRecarga[p_id].nivel,160,168);
      scanf("%c", &reemplazar);
      fflush(stdin);
    }

    if(reemplazar=='N' || reemplazar =='n'){
      printf("\nCreaci%cn de punto de recarga abortada.",162);
      return;
    }
      ant_nivel = PuntosRecarga[p_id].nivel;
      liberada = true;
  }

  if(strcmp(p_tipo,"DC")==0){
    /* Nivel 3: La potencia debe estar entre 50 y 300 */
    if((p_potencia<50) || (p_potencia>300)){
     /* Potencia Incorrecta */
      printf("\n *** ERROR:Potencia incorrecta para tipo de corriente DC ***\n ");
      /* throw 1; */
    }else{
      /* Comprobamos que no excedemos el numero de puntos de nivel 3 */
      if(NPtosRapidos3<1){
        printf("\n *** ERROR:No quedan puntos disponibles de Nivel 3 ***\n ");
        /* throw 1; */
      }else{
        printf("\n Creando punto %d , de nivel 3",p_id);
        PuntosRecarga[p_id].CrearPtoRecarga(p_id,3,p_rodaja);
        NPtosRapidos3--;
        return;
      }
    }
  }else if(strcmp(p_tipo,"AC")==0){

    /* Tenemos que ver la potencia para ver el nivel */

    if((p_potencia>=2) && (p_potencia<=4)){
    /* Nivel 1: Potencia entre 2 y 4 */
     if(NPtosLentos1<1){
        printf("\n *** ERROR:No quedan puntos disponibles de Nivel 1 ***\n ");
        /* throw 1; */
      }else{
        printf("\n Creando punto %d , de nivel 1",p_id);
        PuntosRecarga[p_id].CrearPtoRecarga(p_id,1,p_rodaja);
        NPtosLentos1--;
        return;
      }
    }else if((p_potencia>=11) && (p_potencia<=22)){
    /* Nivel 2: Potencia entre 11 y 22 */
     if(NPtosSemi2<1){
        printf("\n *** ERROR:No quedan puntos disponibles de Nivel 2 ***\n ");
        /* throw 1; */
      }else{
        printf("\n Creando punto %d , de nivel 2",p_id);
        PuntosRecarga[p_id].CrearPtoRecarga(p_id,2,p_rodaja);
        NPtosSemi2--;
        return;
      }
    }else{
      printf("\n *** ERROR:Potencia incorrecta para tipo de corriente AC ***\n ");
      /* throw 1; */
    }

  }else if(strcmp(p_tipo,"IN")==0){

    /* Aqui inicializamos los puntos de recarga */
      PuntosRecarga[p_id].rodaja=0;
      PuntosRecarga[p_id].nivel=0;
      PuntosRecarga[p_id].UltimaReserva=0;
      PuntosRecarga[p_id].PtoEnUso=false;
      /* printf("\nEl punto de recarga %d ha sido inicializado",p_id); */
      return;

  }else{
    /* Error en el tipo de corriente */
    printf("\n *** ERROR:El tipo de corriente debe ser AC o DC ***\n ");
    /* throw 1; */
  }


}



void TipoElectrolinera::ListarReservas(int identificador,int mes, int anio){

  int NumReservas = 0;
  printf("\nLa Electrolinera %s tiene las siguientes reservas para el mes %2d del a%co %4d\n",nombre,mes,164,anio);

  for(int n=1;n<=3;n++){
    /* Recorremos los puntos de recarga para cada nivel */
    printf("\t Nivel: %d\n",n);
    for(int p=1;p<=20;p++){
      /* Recorremos los puntos para imprimir los de cada nivel */
      if(PuntosRecarga[p].nivel==n){
       /* El punto p es del nivel que estamos listando */
       /*TODO ojo que hay que pasarle el mes y el año para que solo imprima esas */
       NumReservas=NumReservas+PuntosRecarga[p].ListarReservas(mes,anio);

      }
    }

  }
  if(NumReservas==0){
    printf("\nLa Electrolinera %s no tiene reservas para el mes %2d del a%co %4d\n",nombre,mes,164,anio);
  }

}


