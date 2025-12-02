#pragma once
#include "TADPunto.h"

const int MAX_LONGITUD_NOMBRE = 20;
typedef char TipoNombreElectrolinera[MAX_LONGITUD_NOMBRE+1];
typedef enum TipoUbicacionElectrolinera {Urbana, Ruta, Mixta};
typedef TipoPunto ListaPuntosRecarga[20];


typedef struct TipoElectrolinera{

  bool EnUso;
  int identificador;
  TipoNombreElectrolinera nombre;
  int NPtosRapidos;
  int NPtosSemi;
  int NPtosLentos;
  TipoUbicacionElectrolinera tipo;
  float latitud;
  float longitud;
  ListaPuntosRecarga PuntosRecarga;


  int CrearElectroninera(TipoNombreElectrolinera nombre, int NPuntos_R, int NPuntos_S, int NPuntos_L,
                         TipoUbicacionElectrolinera Tipo, float latitud, float longitud);
  void ImprimirElectrolinera(int identificador);

  int CrearPuntoRecarga(int p_id, float p_potencia);



};

