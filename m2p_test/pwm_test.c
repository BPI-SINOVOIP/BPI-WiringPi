#include <stdio.h>
#include <wiringPi.h>


#define	LED 7

int main (void)
{
  int i;
  
  printf ("Banana Pi blink\n") ;

  wiringPiSetupPhys() ;
  //wiringPiSetupGpio();
  //wiringPiSetup();

  pinMode (LED, PWM_OUTPUT) ;

  //for (;;)
  //{
  //  digitalWrite (LED, HIGH) ;	// On
   // delay (500) ;		// mS
   // digitalWrite (LED, LOW) ;	// Off
   // delay (500) ;
 // }

  return 0 ;
}

