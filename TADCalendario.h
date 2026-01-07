#pragma once
#include <stdio.h>
#include <time.h>

typedef int DiasMeses[12];
const DiasMeses DIAS_EN_MES = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const DiasMeses DIAS_EN_MES_BISIESTO = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int AnioInicio = 1601;
const int AnioFin = 3000;
const int MesInicio = 1;
const int MesFin = 12;
const int FinDeLosTiempos = 1000000 ; /* días a contar desde inicio de los tiempos (1 de enero de 1601) */
/* const int MaxEstancia = 100;  duración máxima posible de la estancia en un hotel */
typedef int TipoVectorDiasOcupados[32];

typedef struct TipoFecha{

  int dia;
  int mes;
  int anio;
  int horas;
  int minutos;

 bool es_fecha_valida(TipoFecha fecha);
 bool es_anio_bisiesto(int anio);
 bool es_hora_valida(TipoFecha fecha);

};

typedef struct Calendario {
  int Anio;
  int Mes;
  int Dias;
  TipoFecha Fecha;
  /* Métodos */
  bool es_bisiesto(int Anio);
  int dias_mes(int Anio, int Mes);
  int dia_semana(int Anio, int Mes);
  int dias_desde_inicio(TipoFecha Fecha);
  TipoFecha numero_fecha(int Dias);
  void mostrar_calendario(int Anio, int Mes, TipoVectorDiasOcupados DiasOcupadosMes);
};


