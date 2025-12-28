#include <stdio.h>
#include <string.h>


int main(){

typedef char TipoNombre[20];
typedef struct TipoNodo{
  int id;
  TipoNombre nombre;
  TipoNodo* siguiente;
};

typedef TipoNodo* TipoSecuencia;

TipoSecuencia inicio,anterior,secuencia,cursor;


inicio = new TipoNodo;
inicio->id=1;
strcpy(inicio->nombre,"Posicion 1");

anterior=inicio;
secuencia = new TipoNodo;
anterior->siguiente = secuencia;

secuencia->id=2;
strcpy(secuencia->nombre,"Posicion 2");
anterior=secuencia;
secuencia = new TipoNodo;
anterior->siguiente=secuencia;

secuencia->id=5;
strcpy(secuencia->nombre,"Posicion 5");




// ahora vamos a intentar recorrer la secuencia
/* Nos situamos en el primer Elemento */
cursor = inicio;

/* hacemos un bucle hasta que el puntero al siguiente Nodo apunte a Null */
while(cursor != NULL){

  printf("El id es el %d y el nombre es %s\n",cursor->id,cursor->nombre);

 /* Aqui es donde avanzamos al siguiente elemento */
 cursor=cursor->siguiente;

}











}
