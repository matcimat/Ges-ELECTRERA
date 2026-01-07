#pragma once
#include "TADPunto.h"

const int MAX_LONGITUD_NOMBRE = 20;
typedef char TipoNombreElectrolinera[MAX_LONGITUD_NOMBRE+1];
typedef char TipoUbicacionElectrolinera[7];  /* La cadena mas larga es Urbana -> 6+1 */
typedef TipoPunto ListaPuntosRecarga[20];
typedef char TipoCorriente[3];



typedef struct TipoElectrolinera{

  bool ElectEnUso;
  int identificador;
  TipoNombreElectrolinera nombre;
  int NPtosRapidos3;
  int NPtosSemi2;
  int NPtosLentos1;
  TipoUbicacionElectrolinera tipo;
  float latitud;
  float longitud;
  ListaPuntosRecarga PuntosRecarga;


  void CrearElectroninera(TipoNombreElectrolinera nombre, int NPuntos_R, int NPuntos_S, int NPuntos_L,
                         TipoUbicacionElectrolinera Tipo, float latitud, float longitud);
  void ImprimirElectrolinera(int identificador);
  void ListarReservas(int identificador,int mes, int anio);
  void CrearPuntoRecarga(int p_id,float p_potencia, TipoCorriente p_tipo, int rodaja);
  void BuscarHuecoReserva(int nivel,TipoFecha FechaInicio,int duracion);




};

