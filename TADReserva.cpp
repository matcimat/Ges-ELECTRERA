#include "TADReserva.h"
#include "TADUtilidades.h"

bool TipoReserva::ValidarReserva(int R_Inicio, int R_Final){

  /* En esta función vamos a ver si la reserva tiene algún minuto coincidente con el intervalo que queremos reservar */

  /* R_Inicio y R_Final es el intervalo de la reserva */


 for(int i=ts_inicio;i<=ts_final;i++){
  /* Vamos recorriendo los minutos de la reserva */
  if(i>=R_Inicio && i< R_Final){
    /* el minuto i que está en una reserva previs, está dentro del intervalo que queremos reservar */
    /* por lo que no se puede hacer la reserva por no haber hueco completo libre */
    if(modo_debug){
    printf("\n\t\tSe ha encontrado incompatibilidad con la reserva %d en el minuto %d situado entre el inicio=%d y el final %d solicitado."
        ,id,i,R_Inicio,R_Final);
    }
    return false;
  }
 }
  if(modo_debug){
    printf("\n\t\tAnalizada la reserva %d, el punto si tiene hueco para la reserva de inicio %d y final %d.",id,R_Inicio,R_Final);
  }
  return true;
}


void TipoReserva::GrabarReserva(int p_id,TipoFecha p_inicio,int p_duracion,int p_ts_inicio,int p_ts_final){

    id=p_id;
    Inicio=p_inicio;
    duracion=p_duracion;
    ts_inicio=p_ts_inicio;
    ts_final=p_ts_final;

    if(modo_debug){
      printf("\n\t\tReserva correcta creada.\n\n");
    }

    return;

}
