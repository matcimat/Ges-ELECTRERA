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

bool TipoFecha::es_hora_valida(TipoFecha p_fecha)
{
   if (p_fecha.horas < 0 || p_fecha.minutos < 0 || p_fecha.horas > 23 || p_fecha.minutos > 59 ) {
      return false;
  }
  return true;

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
int Calendario::dias_mes(int Anio, int Mes) {

  bool AnioBisiesto;
  AnioBisiesto = es_bisiesto(Anio);

  /* Febrero */

  if (Mes == 2) {

    /* Bisiesto: 29 días */
    if (AnioBisiesto == true) {
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
int Calendario::dia_semana(int Anio, int Mes) {

  int ContadorDias = 1;
  int ContadorMeses = 1;
  int ContadorAnios = AnioInicio;
  int Resto = 0;
  int DiaSemana = 1;
  int DiasMes;
  bool AnioBisiesto = false;

  /* Suma el número de días de cada año al contador de días */ {
    while (ContadorAnios < Anio ) {

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
    AnioBisiesto = es_bisiesto(Anio);

    while (ContadorMeses < Mes ) {
      DiasMes = dias_mes(Anio, ContadorMeses);
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

/* A este punto no se va a llegar nunca , pero lo pongo para que no me salga el warning */
  return 0;

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

    if (es_bisiesto(Anio)) {
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


