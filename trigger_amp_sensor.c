#include "starter.h"

#define TRIG	100
#define INTER	10000
#define TIMES 100

int main(){
	
	volatile struct io_peripherals *io;
	io = import_registers();
	int times = 0;
	
	
  if (io != NULL)
  {
    /* print where the I/O memory was actually mapped to */
    printf( "mem at 0x%8.8X\n", (unsigned int)io );

    io->gpio.GPFSEL2.field.FSEL4 = GPFSEL_OUTPUT;
    io->gpio.GPFSEL2.field.FSEL5 = GPFSEL_OUTPUT;
 
    GPIO_CLR( &(io->gpio), 24);
    GPIO_CLR( &(io->gpio), 25);

    int ground = INTER - TRIG - 40*3;
    
    
    
    for (int i = 0; i< TIMES; i++){
      
        GPIO_SET( &(io->gpio), 24);
        usleep(TRIG);
        GPIO_CLR( &(io->gpio), 24);
        GPIO_SET( &(io->gpio), 25);
        usleep(TRIG);
        GPIO_SET( &(io->gpio), 24);
        GPIO_CLR( &(io->gpio), 25);
        usleep(TRIG);
        GPIO_CLR( &(io->gpio), 24);
        GPIO_SET( &(io->gpio), 25);
        usleep(TRIG);
        GPIO_CLR( &(io->gpio), 25);
        usleep(ground);
	}
}
else
  {
    ; /* warning message already issued */
  }
  
  return 0;
}

	
