#pragma once
#include "TADReserva.h"
#include "TADCalendario.h"


typedef TipoReserva ListaReservas[10000];
typedef char TipoNombreElectrolinera[21];


typedef struct TipoPunto{

  bool PtoEnUso;
  int identificador;
  int id_electrolinera;
  int rodaja;
  int nivel;
  int UltimaReserva;
  ListaReservas Reservas;


  void CrearPtoRecarga(int id,int nivel, int rodaja);
  bool AnadirReserva(TipoFecha inicio , int duracion);
  int ListarReservas(int mes, int anio);
  void CalendarioPunto(int id_ele,TipoNombreElectrolinera nombre ,int id_pto,int mes, int anio);
  void ImprimirPtoRecarga(int id_electrolinera , int id_punto);
  int ListarTodasReservas();
};
