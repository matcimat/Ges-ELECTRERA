#pragma once

typedef struct TipoFecha{

 int dia;
 int mes;
 int anyo;

  bool es_fecha_valida (Tipofecha fecha);
};

typedef struct TipoHora{

  int horas;
  int minutos;

};

typedef struct TipoFechaHora{

  TipoFecha fecha;
  TipoHora hora;

};
