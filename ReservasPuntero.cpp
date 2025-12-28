#include <stdio.h>
#include <string.h>

/* Vamos a definir las Reservas con punteros */


  typedef char TipoCodigoReserva[20];
  typedef struct TipoReserva {
    int id_electrolinera;
    int id_punto;
    TipoCodigoReserva codigo_reserva;
    int orden;
    TipoReserva* siguiente;
  };

  typedef TipoReserva* reservas;
  reservas primera_reserva,reserva_anterior,siguiente_reserva,cursor;


void InsertarReserva(reservas primera_reserva, reservas nueva_reserva){

  cursor=primera_reserva;
  printf("Por aqui 0");
  while(cursor != NULL){
    printf("Por aqui");
    if(cursor->orden>nueva_reserva->orden){
      printf("Hemos encontrado el punto para insertar");
    }
   cursor=cursor->siguiente;
  }

}

int main() {


  int id_e,id_pto,dias;
  TipoCodigoReserva codres;

  primera_reserva = new TipoReserva;
  reserva_anterior = primera_reserva;

  do{
    printf("Pon la electrolinera : ");
    scanf("%d",&id_e);
    printf("Pon el punto de recarga : ");
    scanf("%d",&id_pto);
    printf("Pon el codigo de reserva : ");
    scanf("%s",&codres);
    printf("Mete el numero de orden : ");
    scanf("%d",&dias);

    if(id_e!=0){

    siguiente_reserva = new TipoReserva;

    siguiente_reserva->id_electrolinera=id_e;
    siguiente_reserva->id_punto=id_pto;
    strcpy(siguiente_reserva->codigo_reserva,codres);
    siguiente_reserva->orden=dias;
    printf("llamada a la funcion");
    InsertarReserva(primera_reserva,siguiente_reserva);

    }

  } while (id_e!=0);


/* Ahora vamos a recorrer las reservas */

cursor = primera_reserva->siguiente;
while(cursor != NULL){
  printf("El orden de reserva es %d \n" , cursor->orden);
  cursor = cursor->siguiente;
}
}
