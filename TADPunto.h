#pragma once

/* YYYY-MM-DD_HH:MM */
typedef char TipoTimeStamp[16];

typedef struct TipoReserva{

    int id;
    TipoTimeStamp TS_Inicio;
    TipoTimeStamp TS_Final;
    int duracion;
    TipoReserva* SiguienteReserva;


};

typedef TipoReserva* TipoPunteroReserva;

typedef struct TipoPunto{

  bool PtoEnUso;
  int identificador;
  int id_electrolinera;
  char TipoCorriente;
  float Potencia;
  int rodaja;
  int nivel;
  TipoPunteroReserva SecuenciaReservas;


  void ImprimirPtoRecarga(int id_electrolinera , int id_punto);
  void InsertarReserva(TipoTimeStamp inicio , TipoTimeStamp final,int duracion);
  void ListarReservas(TipoTimeStamp inicio , TipoTimeStamp final);


};
