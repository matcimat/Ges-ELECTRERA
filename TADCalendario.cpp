#include "TADCalendario.h"





bool TipoFecha::es_fecha_valida(TipoFecha p_fecha) {

    if (p_fecha.anio < 2025 || p_fecha.mes < 1 || p_fecha.mes > 12 || p_fecha.dia < 1) {
        return false;
    }

    if (es_anio_bisiesto(p_fecha.anio)) {
        if (p_fecha.dia > DIAS_EN_MES_BISIESTO[p_fecha.mes - 1]) {
        return false;
        }
    }else if (p_fecha.dia > DIAS_EN_MES[p_fecha.mes - 1]) {
        return false;
    }

    return true;
}

/*
    Calcula si un año es bisiesto
*/
bool TipoFecha::es_anio_bisiesto(int anio){
    return ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0));

}

bool TipoFecha::es_hora_valida(int hora, int minuto)
{
   if (hora < 0 || minuto < 0 || hora > 24 || minuto > 59 ) {
      return false;
  }
  return true;

}


int TipoFecha::FechaSecuencia(int dia , int mes , int anyo){
 /* Devuelve el numero de días que han pasado desde el 01/01/2025 hasta la fecha indicada */

 int SecuenciaDias = 0;
 bool bisiesto = false;


 /* Primero vamos a ver si hay años que contar */
 if(anyo>2025){
   for(int i=2025;i<anyo;i++){
    if(es_anio_bisiesto(i)){
      bisiesto = true;
      SecuenciaDias = SecuenciaDias+366;
    }else{
      bisiesto = false;
      SecuenciaDias = SecuenciaDias+365;
    }
   }
 }
  /* Ya tenemos los años , ahora vamos con los meses */
  if(mes>1){
   for(int i=1;i<mes;i++){
    if(bisiesto==false){
     SecuenciaDias = SecuenciaDias+DIAS_EN_MES[i-1];
    }else{
     SecuenciaDias = SecuenciaDias+DIAS_EN_MES_BISIESTO[i-1];
    }
   }
  }

  /* Ya tenemos los meses , ahora ya sumamos los dias */

  SecuenciaDias = SecuenciaDias+dia-1;

  return SecuenciaDias;

 }

int TipoFecha::ReservaSecuencia(int dia, int mes, int anyo , int hora , int minutos){
 /* En esta función pasamos la Fecha secuencia a minutos y le sumamos los minutos correspondientes a la hora pasada */

 int fecha_minutos;
 int dia_minutos;

 fecha_minutos = FechaSecuencia(dia, mes , anyo) * 24 * 60;
 dia_minutos = hora*60 + minutos - 1;

 return fecha_minutos + dia_minutos;

}


/* ----------------------------------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------------------------------- */
/* ----------------------------------------------------------------------------------------------------------------------- */


/* TAD Calendario: Métodos y variables privadas */
/* Método: año bisiesto */
bool Calendario::es_bisiesto(int Anno) {

  /*-- Divisible por 4, no por 100 (sí por 400) --*/
  if (((Anno % 4 == 0) && (Anno % 100 != 0)) || (Anno % 400 == 0)) {
    return true;
  }

  else {
    return false;
  }
}

/* Método: número de días del mes */
int Calendario::dias_mes(int Anno, int Mes) {

  bool AnnoBisiesto;
  AnnoBisiesto = es_bisiesto(Anno);

  /* Febrero */

  if (Mes == 2) {

    /* Bisiesto: 29 días */
    if (AnnoBisiesto == true) {
      return 29;
    }

    /* No bisiesto: 28 días*/
    else {
      return 28;
    }
  }

  /* Mes de 30 días*/
  else if (Mes == 4 || Mes == 6 || Mes == 9 || Mes == 11) {
    return 30;
  }
  /* Mes de 31 días */
  else {
    return 31;
  }

} /* Número de días del mes */

/*-- Función: día de la semana del primer día del mes que se imprime --*/
int Calendario::dia_semana(int Anno, int Mes) {

  int ContadorDias = 1;
  int ContadorMeses = 1;
  int ContadorAnnos = AnioInicio;
  int Resto = 0;
  int DiaSemana = 1;
  int DiasMes;
  bool AnnoBisiesto = false;

  /* Suma el número de días de cada año al contador de días */ {
    while (ContadorAnnos < Anno ) {

      AnnoBisiesto = es_bisiesto(ContadorAnnos);

      if (AnnoBisiesto) {
        ContadorDias = ContadorDias + 366;
      }

      else {
        ContadorDias = ContadorDias + 365;
      }

      ContadorAnnos++;

    }
  }

  /* Suma el número de días de cada mes al contador de días */ {
    AnnoBisiesto = es_bisiesto(Anno);

    while (ContadorMeses < Mes ) {
      DiasMes = dias_mes(Anno, ContadorMeses);
      ContadorDias = ContadorDias + DiasMes;
      ContadorMeses++;
    }
  }
  Resto = ContadorDias % 7;

  switch (Resto) {
  case 0:
    return 7;
    break;
  case 1:
    return 1;
    break;
  case 2:
    return 2;
    break;
  case 3:
    return 3;
    break;
  case 4:
    return 4;
    break;
  case 5:
    return 5;
    break;
  case 6:
    return 6;
    break;
  }

} /* Dia de la semana*/

/* Método: dias desde el inicio de los tiempos (1 de enero de 1601) */
int Calendario::dias_desde_inicio(TipoFecha Fecha) {
  int ContadorDias = 0;
  int ContadorMeses = 1;
  int ContadorAnios = AnioInicio;
  int DiasMes;
  bool AnioBisiesto = false;

  /* Suma el número de días de cada año al contador de días */ {
    while (ContadorAnios < Fecha.anio ) {

      AnioBisiesto = es_bisiesto(ContadorAnios);

      if (AnioBisiesto) {
        ContadorDias = ContadorDias + 366;
      }

      else {
        ContadorDias = ContadorDias + 365;
      }

      ContadorAnios++;

    }
  }

  /* Suma el número de días de cada mes al contador de días */ {

    AnioBisiesto = es_bisiesto(Fecha.anio);
    while (ContadorMeses < Fecha.mes ) {
      DiasMes = dias_mes(Fecha.anio, ContadorMeses);
      ContadorDias = ContadorDias + DiasMes;
      ContadorMeses++;
    }
  }
  /* Suma el día de la fecha al contador de días */ {

    ContadorDias = ContadorDias + Fecha.dia;
  }

  return ContadorDias;

} /* Días desde inicio */

/* Funcion: Obtener fecha a partir de días desde inicio */
TipoFecha Calendario::numero_fecha(int Dias) {
  TipoFecha FechaFinal;
  int Anio = AnioInicio;
  int Mes = 1;
  int Dia = 0;
  int DiasAnio = 365;
  bool Bisiesto;
  int DiasMes = 31;

  while (Dias > DiasAnio) {

    if (es_bisiesto(Anno)) {
      DiasAnio = 366;
    } else {
      DiasAnio = 365;
    }

    Anio++;
    Dias = Dias - DiasAnio;
  }

  while (Dias > DiasMes) {
    Dias = Dias - dias_mes(Anio, Mes);
    Mes++;
  }

  FechaFinal.anio = Anio;
  FechaFinal.mes = Mes;
  FechaFinal.dia = Dias;

  return FechaFinal;
}

/* Procedimiento: Mostrar el calendario */
void Calendario::mostrar_calendario(int Anio, int Mes, TipoVectorDiasOcupados DiasOcupadosMes) {
  int DiasMes;
  int Dia = 1;
  int PrimerDiaSemana; /* Día de la semana de primero de mes*/
  int EspaciosIniciales = 1;

  DiasMes = dias_mes(Anio, Mes);
  PrimerDiaSemana = dia_semana(Anio, Mes);


  /* Cabecera del calendario */ {

    printf("\n\n"); /* Salto de línea tras preguntar año*/

    switch (Mes) {
    case 1:
      printf("Enero                  ");
      break;
    case 2:
      printf("Febrero                ");
      break;
    case 3:
      printf("Marzo                  ");
      break;
    case 4:
      printf("Abril                  ");
      break;
    case 5:
      printf("Mayo                   ");
      break;
    case 6:
      printf("Junio                  ");
      break;
    case 7:
      printf("Julio                  ");
      break;
    case 8:
      printf("Agosto                 ");
      break;
    case 9:
      printf("Septiembre             ");
      break;
    case 10:
      printf("Octubre                ");
      break;
    case 11:
      printf("Noviembre              ");
      break;
    case 12:
      printf("Diciembre              ");
      break;
    }

    printf("%4d\n", Anio);
    printf(" L   M   M   J   V   S   D \n");
    printf("---------------------------\n");

  }
  /*- Espacios, puntos y plecas iniciales -*/ {
    while (EspaciosIniciales < (PrimerDiaSemana )) {

      if (EspaciosIniciales == 6) {
        printf("    ");
      } else if (EspaciosIniciales == 5) {
        printf("    ");
      } else {
        printf("    ");
      }

      EspaciosIniciales++;
    }
  }

  /* Números de días o Re, lo que corresponda */ {

    for (int i = 0; i < DiasMes; i++) {

      /* Domingo: fin de línea y sin espacio*/
      if ((i + 1 + PrimerDiaSemana) % 7 == 1) {
        if (DiasOcupadosMes[i]>720 ) {
          printf("Al\n");
        } else if ((DiasOcupadosMes[i]>=180) && (DiasOcupadosMes[i]<720)){
          printf("Me\n");
        } else if ((DiasOcupadosMes[i]>=1) && (DiasOcupadosMes[i]<180)){
          printf("Ba\n");
        } else if (DiasOcupadosMes[i]==0){
          printf("00\n");
        }
      }

      /* Resto de la semana */
      else {
        if (DiasOcupadosMes[i]>720 ) {
          printf("Al  ");
        } else if ((DiasOcupadosMes[i]>=180) && (DiasOcupadosMes[i]<720)){
          printf("Me  ");
        } else if ((DiasOcupadosMes[i]>=1) && (DiasOcupadosMes[i]<180)){
          printf("Ba  ");
        } else if (DiasOcupadosMes[i]==0){
          printf("00  ");
        }
      }
    }

  }

  printf("\n\n");

  return;

} /* Mostrar calendario */


