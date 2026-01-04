#pragma once
#include "TADReserva.h"
#include "TADCalendario.h"



typedef TipoReserva ListaReservas[100];


typedef struct TipoPunto{

  bool PtoEnUso;
  int identificador;
  int id_electrolinera;
  char TipoCorriente;
  float Potencia;
  int rodaja;
  int nivel;
  int UltimaReserva;
  ListaReservas Reservas;



  void ImprimirPtoRecarga(int id_electrolinera , int id_punto);
  int BuscarReserva(TipoFecha inicio , TipoFecha final);
  void AnadirReserva(TipoFecha inicio , int duracion);
  int ListarReservas(int mes, int anio);
  void CalendarioPunto(int mes, int anio);


};
