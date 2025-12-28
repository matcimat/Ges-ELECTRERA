#include <stdio.h>
#include "TADPunto.h"


void TipoPunto::ImprimirPtoRecarga(int p_id_electrolinera , int p_id_punto){
  if(PtoEnUso==true){
    printf("\tEl punto de recarga %2d tiene la potencia de %2.1f KW.\n",p_id_punto,Potencia);
  }else{
    printf("\tEl punto de recarga %2d no est%c definido.\n",p_id_punto,160);
  }

}

void TipoPunto::InsertarReserva(TipoTimeStamp inicio , TipoTimeStamp final,int duracion){

  }

void TipoPunto::ListarReservas(TipoTimeStamp inicio , TipoTimeStamp final){

}
