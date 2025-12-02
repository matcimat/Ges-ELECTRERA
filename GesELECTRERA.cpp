#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TADElectrolinera.h"
#include "Constantes.h"



/* Parte Declarativa */
const int MAX_NUMERO_ELECTROLINERAS = 10;


/* typedef char TipoNombreElectrolinera[20]; */
typedef int TipoVector[MAX_NUMERO_ELECTROLINERAS];

/* En este vector controleremoa las Electrolineras que ya están creadas y cuales libres */
TipoVector VectorElectrolineras;


typedef TipoElectrolinera TipoListaElectrolineras[MAX_NUMERO_ELECTROLINERAS];
TipoListaElectrolineras electrolineras;

/* Codigos ASCII  á=160 , é=130 , í=161 , ó=162 , ú=163 , ñ=164  ¿=168 , ¡=173 */

bool modo_debug = true;
bool seguir_ejecutando;
int resultado;

void editar_electrolinera(){
  int identificador = 0;
  TipoNombreElectrolinera nombre;
  int npuntos_r = 0;
  int npuntos_s = 0;
  int npuntos_l = 0;
  TipoUbicacionElectrolinera tipo;
  float latitud = 0;
  float longitud = 0;
  char DatosCorrectos;



  fflush(stdin);

  printf("Editar Electrolinera\n\n");

  printf("\t%cIdentificador (n%cmero entre 1 y 10)?: ", 168,163);
  scanf("%d", &identificador);
  fflush(stdin);

  printf("\t%cNombre (entre 1 y 20 caracteres)?: ",168);
  /*scanf("%[^\n]", &nombre);  Esto se hace para que se puedan meter espacios*/
  scanf("%20s", &nombre);
  fflush(stdin);

  printf("\t%cN%cmero de puntos de carga RAPIDOS?: ",168,163);
  scanf("%d", &npuntos_r);
  fflush(stdin);

  printf("\t%cN%cmero de puntos de carga SEMI-RAPIDOS?: ",168,163);
  scanf("%d", &npuntos_s);
  fflush(stdin);

  printf("\t%cN%cmero de puntos de carga LENTOS?: ",168,163);
  scanf("%d", &npuntos_l);
  fflush(stdin);

  printf("\t%cTipo de Estaci%cn (Urbana, Ruta, Mixta)?: ",168,162);
  scanf("%c", &tipo);
  fflush(stdin);

  printf("\t%cLatitud (WGS84)?: ",168);
  scanf("%f", &latitud);
  fflush(stdin);

  printf("\t%cLongitud (WGS84)?: ",168);
  scanf("%f", &longitud);
  fflush(stdin);

  /* Vamos a comprobar si la electrolinera está libre o la reemplazamos */
  if(VectorElectrolineras[identificador]==1){
    printf("IMPORTANTE: La Electrolinera %d ya existe y va reemplazar los datos anteriores.\n",identificador);
  }
  printf("%cDesea continurar (S/N)? ",168);
  scanf("%c", &DatosCorrectos);
  fflush(stdin);

  DatosCorrectos = toupper(DatosCorrectos);


  /* Preguntamos si los datos son correctos */
  if (DatosCorrectos == 'S') {
    /* Son correctos: se guardan los datos con el subprograma guardar_datos_edificio(...); */
    /* guardar_datos_edificio(IdentificadorEdificio, NombreEdificio, NumeroBasicos, NumeroNormales, NumeroLujo); */
    resultado = electrolineras[identificador].CrearElectroninera(nombre,npuntos_r,npuntos_s,npuntos_l,tipo,latitud,longitud);
    if(resultado==0){
      /* La creación se ha hecho correctamente , la marcamos en el Vector de control */
      VectorElectrolineras[identificador]=1;
    }else{
      /* Se ha producido un error en la creación */
      printf("Ha habido un error en los datos introducidos y no hemos podido crear la electrolinera.\n");
    }
    /* Y ahora volvemos al menu principal */
    return;
  }

  else if (DatosCorrectos == 'N') {
    /* No son correctos: no se guarda nada, pero se vuelve al men  principal igualmente */
    printf("\n**Operaci%cn Cancelada **\n\n",162);
    return;
  }

  else {
    printf("\n*** S%clo se admiten las opciones S(si) o N(no) y has tecleado %c ***\n",162, DatosCorrectos);
    return;
  }
} /* Ediar edificio*/



void editar_pto_recarga(){

  int Electrolinera = 0;
  int Identificador = 0;
  /*TipoNombreElectrolinera Nombre;*/
  char TipoCorriente;
  int Potencia = 0;
  int Rodaja = 0;
  int Numero_Total_Puntos = 0;
  char DatosCorrectos;

  fflush(stdin);

  printf("Editar punto de carga\n\n");

  printf("\t%cIdentificador electrolinera (numero entre 1 y 10)?: ",168);
  scanf("%d", &Electrolinera);
  fflush(stdin);

  printf("\t%cIdentificador punto de carga (numero entre 1 y 20)?: ",168);
  scanf("%d", &Identificador);
  fflush(stdin);

  printf("\t%cTipo de corriente (DC/AC)?: ",168);
  scanf("%c", &TipoCorriente);
  fflush(stdin);

  printf("\t%cPotencia (kW)?: ",168);
  scanf("%d", &Potencia);
  fflush(stdin);

  printf("\t%cRodaja m%nima de recarga (minutos)?: ",168,161);
  scanf("%d", &Rodaja);
  fflush(stdin);



  printf("IMPORTANTE: Esta opci%cn borra los datos anteriores.\n",162);
  printf("%cSon correctos los nuevos datos(S/N)? ",168);
  scanf("%c", &DatosCorrectos);
  fflush(stdin);

  DatosCorrectos = toupper(DatosCorrectos);

  /* Comprobamos si el n mero total de apartamentos no supera 20 */

  /* Preguntamos si los datos son correctos */
  if (DatosCorrectos == 'S') {
    // Son correctos: se guardan los datos con el subprograma guardar_datos_edificio(...);
    /*guardar_datos_edificio(IdentificadorEdificio, NombreEdificio, NumeroBasicos, NumeroNormales, NumeroLujo);*/

    /* Y ahora volvemos al menu principal */
    return;
  }

  else if (DatosCorrectos == 'N') {
    /* No son correctos: no se guarda nada, pero se vuelve al men  principal igualmente */
    printf("No se guardan los datos por incorrectos\n\n");
    return;
  }

  else {
    printf("\n*** S%clo se admiten las opciones S (s ) o N (no) y has tecleado %c ***\n", DatosCorrectos,162);
    return;
  }

}

void reservar_pto_recarga(){

  typedef char TipoPtoRecarga[2];

  int Electrolinera = 0;
  TipoPtoRecarga TipoPto;
  int dia=0;
  int mes=0;
  int anio=0;
  int hora=0;
  int minuto=0;
  int duracion=0;

  printf("Reservar Punto de Recarga:\n\n");

  printf("\t%cIdentificador de Electrolinera?: ", 168);
  scanf("%d", &Electrolinera);
  fflush(stdin);

  printf("\t%cTipo de Punto de Recarga (Nivel 1/Nivel 2/Nivel 3)?: ",168);
  scanf("%c", &TipoPto);
  /* TipoPunto = toupper(TipoPunto); */

  fflush(stdin);

  printf("\t%cDatos Reserva: Dia?: ",168);
  scanf("%d", &dia);
  fflush(stdin);
  /* FechaEntradaSolicitada.Dia = FechaEntradaDia; */

  printf("\t%cDatos Reserva: Mes?: ",168);
  scanf("%d", &mes);
  fflush(stdin);
  /* FechaEntradaSolicitada.Mes = FechaEntradaMes; */

  printf("\t%cDatos Reserva: A%co?: ",168,164);
  scanf("%d", &anio);
  fflush(stdin);


  printf("\t%cDatos Reserva: Hora?: ",168);
  scanf("%d", &hora);
  fflush(stdin);


  printf("\t%cDatos Reserva: Minuto?: ",168);
  scanf("%d", &minuto);
  fflush(stdin);



  printf("\t%cDatos Reserva: Duraci%cn?: ",168,162);
  scanf("%d", &duracion);

  fflush(stdin);

}

void listar_reservas_electrolinera(){
}

void listar_mensual_pto(){
}


/* Procedimiento: salir del programa */
void salir() {
  seguir_ejecutando = false;
  exit(0);
  return;
} /* Salir*/

/* Procedimiento: men  principal*/
void menu_principal() {

  char tecla_menu_principal;
  bool tecla_menu_principal_valida = false;

  printf("\n\nGesELECTRERA: Gesti%cn de electrolineras\n\n",162);
  printf("\tEditar electrolinera\t\t\t (Pulsar E)\n");
  printf("\tEditar punto de recarga \t\t (Pulsar P)\n");
  printf("\tReservar punto de recarga \t\t (Pulsar R)\n");
  printf("\tListar reservas de electrolinera \t (Pulsar L)\n");
  printf("\tListar servicio mensual punto \t\t (Pulsar M)\n");
  printf("\tSalir\t\t\t\t\t (Pulsar S)\n");
  printf("\nTeclear una opci%cn valida (E|P|R|L|M|S)",162);

  scanf("%c", &tecla_menu_principal);
  fflush(stdin);

  tecla_menu_principal = toupper(tecla_menu_principal);

  switch (tecla_menu_principal) {
  case 'E':
    editar_electrolinera();
    tecla_menu_principal_valida = true;
    break;
  case 'P':
    editar_pto_recarga();
    tecla_menu_principal_valida = true;
    break;
  case 'R':
    reservar_pto_recarga();
    tecla_menu_principal_valida = true;
    break;
  case 'L':
    listar_reservas_electrolinera();
    tecla_menu_principal_valida = true;
    break;
  case 'M':
    listar_mensual_pto();
    tecla_menu_principal_valida = true;
    break;
  case 'S':
    printf("\n***\nFin\n***\n");
    salir(); /* Sale del programa */
    break;
  default:
    printf("\n*** Opci%cn \"%c\" no v%clida, solo son v%clidas (E|P|R|L|M|S ***\n", 162,tecla_menu_principal,160,160);
    tecla_menu_principal_valida = false;
  }
  if (!tecla_menu_principal_valida) {
    menu_principal();
  } else {
    return;
  }
} /* Men  principal */


void IniciarValores(){

  if(modo_debug==true) {
    printf("IniciarValores\n");
  }

  /* Pondremos a 0 todo el vector de control de las electrolineras */
  for(int i=0;i<=MAX_NUMERO_ELECTROLINERAS;i++){
    VectorElectrolineras[i]=0;
    if(modo_debug==true) {
      printf("\n DEBUG : Inicializando VectorElectrolinera[%d)\n",i);
    }
  }


  resultado=electrolineras[1].CrearElectroninera("Electro-1",8,6,6,Urbana,11.11,21.21);
  if(resultado==0){
    VectorElectrolineras[1]=1;
  }
  resultado=electrolineras[2].CrearElectroninera("Electro-2",20,0,0,Mixta,22.22,32.32);
  if(resultado==0){
    VectorElectrolineras[2]=1;
  }
  resultado=electrolineras[3].CrearElectroninera("Electro-3",0,20,0,Ruta,33.33,43.43);
  if(resultado==0){
    VectorElectrolineras[3]=1;
  }
  resultado=electrolineras[4].CrearElectroninera("Electro-4",0,0,20,Urbana,44.44,55.55);
  if(resultado==0){
    VectorElectrolineras[4]=1;
  }
  /* Esta Electrolinera no se va a crear porque excede el numero de puntos de recarga */
  resultado=electrolineras[5].CrearElectroninera("Electro-5",20,0,20,Urbana,44.44,55.55);
  electrolineras[7].PuntosRecarga[0].nivel=1;
  if(resultado==0){
    VectorElectrolineras[4]=1;
  }




}


void ListarValores(){
  printf("\n ** DEBUG : Listado Electrolineras ** \n");
  for(int i=1;i<=MAX_NUMERO_ELECTROLINERAS;i++){
    electrolineras[i].ImprimirElectrolinera(i);
  }
  printf("\n ** DEBUG : Vector Electrolineras Libres/Ocupadas ** \n");
  for(int i=1;i<=MAX_NUMERO_ELECTROLINERAS;i++){
    printf("%2d - ",VectorElectrolineras[i]);
  }

}

/* Programa principal */
int main() {

  /* precargar_datos();  */

  IniciarValores();

  seguir_ejecutando=true;

  while (seguir_ejecutando) {

    if(modo_debug){ListarValores();}
    menu_principal();
  }

  return 0;

} /* Main*/
