#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



/* Parte Declarativa */

typedef char TipoPtoRecarga[2];
typedef char TipoNombreElectrolinera[20];
typedef int mi_array[10];
typedef struct Fecha {
  int dia;
  int mes;
  int anio;
};



bool seguir_ejecutando;
const int Max_Puntos_Electrolinera = 20;

void asignarfecha(){
 Fecha mifecha;
 mi_array vector;

 mifecha.dia=23;
 mifecha.mes=2;
 mifecha.anio=2005;


  for(int i=0;i<10;i++){
    vector[i]=i*i;
  }

  for(int i=0;i<10;i++){
    printf("%3d\t",vector[i]);
  }
  printf("\n %2d-%2d-%2d \n",mifecha.dia,mifecha.mes,mifecha.anio);


}


void editar_electrolinera(){
  int Identificador = 0;
  TipoNombreElectrolinera Nombre;
  int Npuntos_R = 0;
  int Npuntos_S = 0;
  int Npuntos_L = 0;
  char Tipo;
  float Latitud = 0;
  float Longitud = 0;
  char DatosCorrectos;
  int Numero_Total_Puntos = 0;


  fflush(stdin);

  printf("Editar Electrolinera\n\n");

  printf("\tIdentificador (numero entre 1 y 10)?: ");
  scanf("%d", &Identificador);
  fflush(stdin);

  printf("\tNombre (entre 1 y 20 caracteres)?: ");
  scanf("%[^\n]s", &Nombre);
  fflush(stdin);

  /* strcpy(mes,"Enero"); */

  printf("\tNumero de puntos de carga RAPIDOS?: ");
  scanf("%d", &Npuntos_R);
  fflush(stdin);

  printf("\tNumero de puntos de carga SEMI-RAPIDOS?: ");
  scanf("%d", &Npuntos_S);
  fflush(stdin);

  printf("\tNumero de puntos de carga LENTOS?: ");
  scanf("%d", &Npuntos_L);
  fflush(stdin);

  printf("\tTipo de Estacion (Urbana, Ruta, Mixta)?: ");
  scanf("%c", &Tipo);
  fflush(stdin);

  printf("\tLatitud (WGS84)?: ");
  scanf("%f", &Latitud);
  fflush(stdin);

  printf("\tLongitud (WGS84)?: ");
  scanf("%f", &Longitud);
  fflush(stdin);

  printf("IMPORTANTE: Esta opcion borra los datos anteriores.\n");
  printf("Son correctos los nuevos datos(S/N)?");
  scanf("%c", &DatosCorrectos);
  fflush(stdin);

  printf("\n%s\n",Nombre);

  DatosCorrectos = toupper(DatosCorrectos);

  /* Comprobamos si el número total de apartamentos no supera 20 */
  Numero_Total_Puntos = Npuntos_R + Npuntos_S + Npuntos_L;

  if (Numero_Total_Puntos > Max_Puntos_Electrolinera) {
    printf("\n\n ERROR: El número total de apartamentos no debe superar 20\n\n");
    return;
  }

  /* Preguntamos si los datos son correctos */
  if (DatosCorrectos == 'S') {
    // Son correctos: se guardan los datos con el subprograma guardar_datos_edificio(...);
    /*guardar_datos_edificio(IdentificadorEdificio, NombreEdificio, NumeroBasicos, NumeroNormales, NumeroLujo);*/

    /* Y ahora volvemos al menu principal */
    return;
  }

  else if (DatosCorrectos == 'N') {
    /* No son correctos: no se guarda nada, pero se vuelve al menú principal igualmente */
    printf("No se guardan los datos por incorrectos\n\n");
    return;
  }

  else {
    printf("\n*** Solo se admiten las opciones S (sí) o N (no) y has tecleado %c ***\n", DatosCorrectos);
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

  printf("\tIdentificador electrolinera (numero entre 1 y 10)?: ");
  scanf("%d", &Electrolinera);
  fflush(stdin);

  printf("\tIdentificador punto de carga (numero entre 1 y 20)?: ");
  scanf("%d", &Identificador);
  fflush(stdin);

  printf("\tTipo de corriente (DC/AC)?: ");
  scanf("%c", &TipoCorriente);
  fflush(stdin);

  printf("\tPotencia (kW)?: ");
  scanf("%d", &Potencia);
  fflush(stdin);

  printf("\tRodaja minima de recarga (minutos)?: ");
  scanf("%d", &Rodaja);
  fflush(stdin);



  printf("IMPORTANTE: Esta opcion borra los datos anteriores.\n");
  printf("Son correctos los nuevos datos(S/N)?");
  scanf("%c", &DatosCorrectos);
  fflush(stdin);

  DatosCorrectos = toupper(DatosCorrectos);

  /* Comprobamos si el número total de apartamentos no supera 20 */

  /* Preguntamos si los datos son correctos */
  if (DatosCorrectos == 'S') {
    // Son correctos: se guardan los datos con el subprograma guardar_datos_edificio(...);
    /*guardar_datos_edificio(IdentificadorEdificio, NombreEdificio, NumeroBasicos, NumeroNormales, NumeroLujo);*/

    /* Y ahora volvemos al menu principal */
    return;
  }

  else if (DatosCorrectos == 'N') {
    /* No son correctos: no se guarda nada, pero se vuelve al menú principal igualmente */
    printf("No se guardan los datos por incorrectos\n\n");
    return;
  }

  else {
    printf("\n*** Solo se admiten las opciones S (sí) o N (no) y has tecleado %c ***\n", DatosCorrectos);
    return;
  }

}

void reservar_pto_recarga(){

  int Electrolinera = 0;
  TipoPtoRecarga TipoPto;
  int dia=0;
  int mes=0;
  int anio=0;
  int hora=0;
  int minuto=0;
  int duracion=0;

  printf("Reservar Punto de Recarga:\n\n");

  printf("\tIdentificador de Electrolinera?");
  scanf("%d", &Electrolinera);
  fflush(stdin);

  printf("\tTipo de Punto de Recarga (Nivel 1/Nivel 2/Nivel 3)?");
  scanf("%c", &TipoPto);
  /* TipoPunto = toupper(TipoPunto); */

  fflush(stdin);

  printf("\tDatos Reserva: Dia?: ");
  scanf("%d", &dia);
  fflush(stdin);
  /* FechaEntradaSolicitada.Dia = FechaEntradaDia; */

  printf("\tDatos Reserva: Mes?:");
  scanf("%d", &mes);
  fflush(stdin);
  /* FechaEntradaSolicitada.Mes = FechaEntradaMes; */

  printf("\tDatos Reserva: Año?:");
  scanf("%d", &anio);
  fflush(stdin);


  printf("\tDatos Reserva: Hora?:");
  scanf("%d", &hora);
  fflush(stdin);


  printf("\tDatos Reserva: Minuto?:");
  scanf("%d", &minuto);
  fflush(stdin);



  printf("\tDatos Reserva: Duracion?: ");
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

/* Procedimiento: menú principal*/
void menu_principal() {

  char tecla_menu_principal;
  bool tecla_menu_principal_valida = false;

  printf("GesELECTRERA: Gestion de electrolineras\n\n");
  printf("\tEditar electrolinera\t\t\t (Pulsar E)\n");
  printf("\tEditar punto de recarga \t\t (Pulsar P)\n");
  printf("\tReservar punto de recarga \t\t (Pulsar R)\n");
  printf("\tListar reservas de electrolinera \t (Pulsar L)\n");
  printf("\tListar servicio mensual punto \t\t (Pulsar M)\n");
  printf("\tSalir\t\t\t\t\t (Pulsar S)\n");
  printf("\nTeclear una opcion valida (E|P|R|L|M|S)");

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
    printf("\n*** Opción \"%c\" no valida, solo son válidas (E|P|R|L|M|S ***\n", tecla_menu_principal);
    tecla_menu_principal_valida = false;
  }
  if (!tecla_menu_principal_valida) {
    menu_principal();
  } else {
    return;
  }
} /* Menú principal */



/* Programa principal */
int main() {

  /* precargar_datos();  */


  asignarfecha();

  seguir_ejecutando=true;

  while (seguir_ejecutando) {
    menu_principal();
  }

  return 0;

} /* Main*/
