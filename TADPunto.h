#pragma once

typedef struct TipoPunto{

  bool EnUso;
  int identificador;
  int id_electrolinera;
  char TipoCorriente;
  float Potencia;
  int rodaja;
  int nivel;


  void ImprimirPtoRecarga(int id_electrolinera , int id_punto);

};
