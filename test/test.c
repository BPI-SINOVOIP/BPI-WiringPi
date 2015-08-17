#include <stdio.h>
#include <wiringPi.h>


#define	LED	7     //use wpi define

int main (void)
{
  printf ("Banana Pi blink\n") ;

  wiringPiSetup() ;
  pinMode (LED, OUTPUT) ;

  for (;;)
  {
    digitalWrite (LED, HIGH) ;	// On
    delay (500) ;		// mS
    digitalWrite (LED, LOW) ;	// Off
    delay (500) ;
  }
  return 0 ;
}
