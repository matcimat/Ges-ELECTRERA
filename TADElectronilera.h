#pragma once

const int elemaxlongitudnombre = 20;
typedef char Nombre[elemaxlongitudnombre+1];
typedef enum TipoElectro {Urbana, Ruta, Mixta};

typedef struct Electrolinera{

  int id;
  Nombre nombre;
  int NPtosRapidos;
  int NPtosSemi;
  int NPtosLentos;
  TipoElectro tipo;
  float latitud;
  float longitud;

};

