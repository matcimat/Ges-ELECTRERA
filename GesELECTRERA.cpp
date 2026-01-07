#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TADElectrolinera.h"
#include "Constantes.h"
#include "TADUtilidades.h"
#include "TADCalendario.h"



/* Parte Declarativa */
const int MAX_NUMERO_ELECTROLINERAS = 11;

typedef TipoElectrolinera TipoListaElectrolineras[MAX_NUMERO_ELECTROLINERAS];
TipoListaElectrolineras electrolineras;
typedef int DiasOcupacion[31];

/* Codigos ASCII  á=160 , é=130 , í=161 , ó=162 , ú=163 , ñ=164  ¿=168 , ¡=173 */

bool modo_debug = false;
bool seguir_ejecutando;
int resultado;
TipoUtilidades utilidades;
TipoFecha Inicio,Final;


void IniciarValores(){

  /* Pondremos a 0 todo el vector de control de las electrolineras */
  for(int i=1;i<=MAX_NUMERO_ELECTROLINERAS-1;i++){
    electrolineras[i].ElectEnUso=false;
  }

  electrolineras[1].CrearElectroninera("Electro-1",2,3,2,"Urbana",11.11,21.21);
  electrolineras[1].CrearPuntoRecarga(1,3,"AC",10);
  electrolineras[1].PuntosRecarga[1].AnadirReserva(utilidades.TransformarFechaHora(12,4,2026,14,20),250);
  electrolineras[1].PuntosRecarga[1].AnadirReserva(utilidades.TransformarFechaHora(14,5,2026,12,20),35);
  electrolineras[1].CrearPuntoRecarga(5,15,"AC",20);
  electrolineras[1].PuntosRecarga[5].AnadirReserva(utilidades.TransformarFechaHora(1,1,2026,10,20),35);
  electrolineras[1].PuntosRecarga[5].AnadirReserva(utilidades.TransformarFechaHora(2,1,2026,12,10),5);
  electrolineras[1].PuntosRecarga[5].AnadirReserva(utilidades.TransformarFechaHora(15,1,2026,12,10),500);
  electrolineras[1].PuntosRecarga[5].AnadirReserva(utilidades.TransformarFechaHora(15,1,2026,12,20),5);
  electrolineras[1].PuntosRecarga[5].AnadirReserva(utilidades.TransformarFechaHora(1,2,2026,12,00),35);
  electrolineras[1].CrearPuntoRecarga(10,100,"DC",30);
  electrolineras[1].PuntosRecarga[10].AnadirReserva(utilidades.TransformarFechaHora(31,1,2026,12,00),35);

  electrolineras[2].CrearElectroninera("Electro-2",20,0,0,"Mixta",22.22,32.32);
  electrolineras[3].CrearElectroninera("Electro-3",0,20,0,"Ruta",33.33,43.43);
  electrolineras[4].CrearElectroninera("Electro-4",0,0,20,"Urbana",44.44,55.55);



}


void MostrarValores(){
  printf("\n ** DEBUG : Listado Electrolineras ** \n");
  for(int i=1;i<=MAX_NUMERO_ELECTROLINERAS-1;i++){
    electrolineras[i].ImprimirElectrolinera(i);
  }
}


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
  scanf("%20s", nombre);
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
  scanf("%7s", tipo);
  fflush(stdin);

  printf("\t%cLatitud (WGS84)?: ",168);
  scanf("%f", &latitud);
  fflush(stdin);

  printf("\t%cLongitud (WGS84)?: ",168);
  scanf("%f", &longitud);
  fflush(stdin);

  /* Vamos a comprobar si la electrolinera está libre o la reemplazamos */
  if(electrolineras[identificador].ElectEnUso==true){
    printf("AVISO IMPORTANTE: La Electrolinera %d ya existe y va reemplazar los datos anteriores.\n",identificador);
  }
  printf("%cDesea continurar (S/N)? ",168);
  scanf("%c", &DatosCorrectos);
  fflush(stdin);

  DatosCorrectos = toupper(DatosCorrectos);


  /* Preguntamos si los datos son correctos */
  if (DatosCorrectos == 'S') {
    /* Lo metemos en un try catch para capturar si ha fallado la creación y poder realizar las acciones oportunas */
    try {
        electrolineras[identificador].CrearElectroninera(nombre,npuntos_r,npuntos_s,npuntos_l,tipo,latitud,longitud);
        printf("Electrolinera creada correctamente.\n");
    }catch (int error){
       printf("Ha habido un error en los datos introducidos y no hemos podido crear la electrolinera. C%cdigo Error: %2d\n",162,error);
       return;
    }
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
}

void editar_pto_recarga(){

  int Electrolinera = 0;
  int Identificador = 0;
  TipoCorriente Corriente;
  int Potencia = 0;
  int Rodaja = 0;
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
  scanf("%2s", Corriente);
  fflush(stdin);
  utilidades.minus_a_mayus_corriente(Corriente);


  printf("\t%cPotencia (kW)?: ",168);
  scanf("%d", &Potencia);
  fflush(stdin);

  printf("\t%cRodaja m%cnima de recarga (minutos)?: ",168,161);
  scanf("%d", &Rodaja);
  fflush(stdin);

  if(electrolineras[Electrolinera].ElectEnUso==false){
    printf("\n*** ERROR: La Electrolinera %2d no est%c definida.\n",Electrolinera,160);
    return;
  }

  printf("\n%cSon correctos estos datos(S/N)? ",168);
  scanf("%c", &DatosCorrectos);
  fflush(stdin);

  DatosCorrectos = toupper(DatosCorrectos);

  if (DatosCorrectos == 'S') {
    try {
      electrolineras[Electrolinera].CrearPuntoRecarga(Identificador,Potencia,Corriente,Rodaja);
    }catch (int error)
    {
       printf("Ha habido un error en los datos introducidos y no hemos podido crear el punto de recarga. C%cdigo Error: %2d\n",162,error);
       return;
    }

    return;
  }
  else if (DatosCorrectos == 'N') {
    /* No son correctos: no se guarda nada, pero se vuelve al men  principal igualmente */
    printf("Operaci%c cancelada. n\n\n", 162);
    return;
  }

  else {
    printf("\n*** S%clo se admiten las opciones S (s ) o N (no) y has tecleado %c ***\n", DatosCorrectos,162);
    return;
  }

}

void reservar_pto_recarga(){

  typedef char TipoPtoRecarga[3];

  int Electrolinera = 0;
  TipoPtoRecarga TipoPunto;
  TipoFecha FechaInicio;
  int nivel=0;
  int dia=0;
  int mes=0;
  int anio=0;
  int hora=0;
  int minuto=0;
  int duracion=0;
  char DatosCorrectos;

  printf("Reservar Punto de Recarga:\n\n");

  printf("\t%cIdentificador de Electrolinera?: ", 168);
  scanf("%d", &Electrolinera);
  fflush(stdin);

  printf("\t%cTipo de Punto de Recarga (Nivel 1/Nivel 2/Nivel 3)?: ",168);
  scanf("%2s", TipoPunto);
  fflush(stdin);

  if(strcmp(TipoPunto,"N1")==0 || strcmp(TipoPunto,"n1")==0){
    nivel=1;
  }else if(strcmp(TipoPunto,"N2")==0 || strcmp(TipoPunto,"n2")==0){
    nivel=2;
  }else if(strcmp(TipoPunto,"N3")==0 || strcmp(TipoPunto,"n3")==0){
    nivel=3;
  }

  printf("\t%cDatos Reserva: Dia?: ",168);
  scanf("%d", &dia);
  fflush(stdin);

  printf("\t%cDatos Reserva: Mes?: ",168);
  scanf("%d", &mes);
  fflush(stdin);

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

  if((Electrolinera<1) || (Electrolinera>10) || (nivel<1) || (nivel>3)){
      printf("\n *** ERROR en los datos introducidos de electrolinera y/o nivel no son correctos ***\n");
      return;
  }

  FechaInicio=utilidades.TransformarFechaHora(dia,mes,anio,hora,minuto);

  if(FechaInicio.es_fecha_valida(FechaInicio)==false){
      printf("\n *** ERROR la fecha no es correcta ***\n");
      return;
  }

  if(FechaInicio.es_hora_valida(FechaInicio)==false){
      printf("\n *** ERROR la hora no es correcta ***\n");
      return;
  }

  if(electrolineras[Electrolinera].ElectEnUso==false){
    printf("\n*** ERROR: La Electrolinera %2d no est%c definida.\n",Electrolinera,160);
    return;
  }

  printf("\n%cSon correctos estos datos(S/N)? ",168);
  scanf("%c", &DatosCorrectos);
  fflush(stdin);

  DatosCorrectos = toupper(DatosCorrectos);

  if (DatosCorrectos == 'S'){
      printf("\nCreamos la reserva");
      try{
        electrolineras[Electrolinera].BuscarHuecoReserva(nivel,FechaInicio,duracion);
      }catch (int error){
        printf("No hay disponibilidad para hacer la reserva. Intente en otro horario.",162,error);
        return;
      }
      return;

  }else if (DatosCorrectos == 'N') {
    printf("Operaci%c cancelada. n\n\n", 162);
    return;
  }
  else {
    printf("\n*** S%clo se admiten las opciones S (s ) o N (no) y has tecleado %c ***\n", DatosCorrectos,162);
    return;
  }
}

void listar_reservas_electrolinera(){

  int Electrolinera = 0;
  int mes=0;
  int anio=0;

  printf("Reservas Mensuales Punto de Recarga:\n\n");

  printf("\t%cIdentificador de Electrolinera?: ", 168);
  scanf("%d", &Electrolinera);
  fflush(stdin);

  printf("\t%cSelecci%cn: Mes?: ",168,162);
  scanf("%d", &mes);
  fflush(stdin);

  printf("\t%cSelecci%cn: A%co?: ",168,162,164);
  scanf("%d", &anio);
  fflush(stdin);

  if((Electrolinera<1) || (Electrolinera>10) || (mes<1 || mes>12) || (anio<2025) || (anio>2030) ){
   printf("\n *** ERROR en los datos introducidos ***\n");
    }else if(electrolineras[Electrolinera].ElectEnUso==false){
      printf("\n *** ERROR La Electrolinera elegida no se encuentra definida ***\n");
      }else{
        /* Llamamos al método del punto para listar el calendario */
        electrolineras[Electrolinera].ListarReservas(Electrolinera,mes,anio);
      }


}

void listar_mensual_pto(){


  int Electrolinera = 0;
  int Punto;
  int mes=0;
  int anio=0;
  char continuar = 'S';

  printf("Reservas Mensuales Punto de Recarga:\n\n");

  printf("\t%cIdentificador de Electrolinera?: ", 168);
  scanf("%d", &Electrolinera);
  fflush(stdin);

  printf("\t%cPunto de Recarga?: ",168);
  scanf("%d", &Punto);
  fflush(stdin);


  while(continuar=='S'){
    printf("\t%cSelecci%cn: Mes?: ",168,162);
    scanf("%d", &mes);
    fflush(stdin);


    printf("\t%cSelecci%cn: A%co?: ",168,162,164);
    scanf("%d", &anio);
    fflush(stdin);

    if((Electrolinera<1 || Electrolinera>10) || (Punto<1 || Punto>20) || (mes<1 || mes>12) || (anio<2025 || anio>2030)){
     printf("\n *** ERROR en los datos introducidos ***\n");
      }else if(electrolineras[Electrolinera].ElectEnUso==false){
        printf("\n *** ERROR La Electrolinera elegida no se encuentra definida ***\n");
        }else if(electrolineras[Electrolinera].PuntosRecarga[Punto].PtoEnUso==false){
          printf("\n *** ERROR El punto de recarga elegido no se encuentra definido ***\n");
        }else{
          /* Llamamos al método del punto para listar el calendario */
          electrolineras[Electrolinera].PuntosRecarga[Punto].CalendarioPunto(Electrolinera,electrolineras[Electrolinera].nombre,Punto,mes,anio);

        }
    printf("\n\n%cQuiere mostrar otro mes (S/N)? ",168);
    scanf("%c", &continuar);
    fflush(stdin);
    continuar=toupper(continuar);
  }


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
  case 'I':
    /* Funcion no documentada para Cargar unos valores iniciales de pruebas */
    IniciarValores();
    tecla_menu_principal_valida = true;
    break;
  case 'T':
    /* Funcion no documentada para mostrar todos las Electrolineras, puntos y reservas en la memoria */
    MostrarValores();
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





/* Programa principal */
int main() {

  /* precargar_datos();  */


  IniciarValores();

  seguir_ejecutando=true;

  while (seguir_ejecutando) {

    if(modo_debug==true){
      MostrarValores();
      }
    menu_principal();
  }

  return 0;

} /* Main*/
