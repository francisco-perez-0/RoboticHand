/*==================[inclusions]=============================================*/
#include "../inc/app.h"

#include "sapi.h"

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/




/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

int main(void)
{
	boardConfig(); //Inicializacion placa EDU-CIAA-NXP
	uartConfig(UART_USB, 115200); //Configuracion de USB a 115200 baud

	while(1){

	}




   return 0;
}

/*==================[end of file]============================================*/

