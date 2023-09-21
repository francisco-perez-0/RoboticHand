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

uint8_t receivedData;

int main(void)
{
	boardConfig(); //Inicializacion placa EDU-CIAA-NXP
	uartConfig(UART_USB, 115200); //Configuracion de USB a 115200 baud

	//delay_t delay;
	//delayConfig(&delay, 500); // 0,5 ms retardo no bloqueante

	while(1){


			 uartReadByte(UART_USB, &receivedData);
			 	if(receivedData != 0){
			 		gpioWrite(LED_1, ON);
			 	} else {
			 		gpioWrite(LED_1, OFF);
			 	}

	}




   return 0;
}

/*==================[end of file]============================================*/

