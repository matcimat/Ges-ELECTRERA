#pragma once

const int MAX_LONGITUD_NOMBRE = 20;
typedef char TipoNombreElectrolinera[MAX_LONGITUD_NOMBRE+1];
typedef enum TipoUbicacionElectrolinera {Urbana, Ruta, Mixta};

typedef struct TipoElectrolinera{

  int identificador;
  TipoNombreElectrolinera nombre;
  int NPtosRapidos;
  int NPtosSemi;
  int NPtosLentos;
  TipoUbicacionElectrolinera tipo;
  float latitud;
  float longitud;


  int CrearElectroninera(TipoNombreElectrolinera nombre, int NPuntos_R, int NPuntos_S, int NPuntos_L,
                         TipoUbicacionElectrolinera Tipo, float latitud, float longitud);
  void ImprimirElectrolinera(int identificador);

};

