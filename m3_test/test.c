#include <stdio.h>
#include <wiringPi.h>


#define	LED 18

static int phy_led[] = {8, 10, 12, 16, 18, 22, 24, 26, 28, 32, 36, 38, 40,
			37, 35, 33, 31, 29, 27, 23, 21, 19, 15, 13, 11, 7, 5, 3};

static int bcm_led[] = {2, 3, 4, 17, 27, 22, 10, 9, 11, 0, 5, 6, 13, 19, 26,
			21, 20, 16, 12, 1, 7, 8, 25, 24, 23, 18, 15, 14};

static int wpi_led[] = {8, 9, 7, 0, 2, 3, 12, 13, 14, 30, 21, 22, 23, 24, 25,
			29, 28, 27, 26, 31, 11, 10, 6, 5, 4, 1, 16, 15};

int main (void)
{
  int i;
  
  printf ("Banana Pi blink\n") ;

  //wiringPiSetupPhys() ;	 //phy
  //wiringPiSetupGpio();	 //bcm
  wiringPiSetup();         //wpi

#if 0
  pinMode (LED, OUTPUT) ;

  for (;;)
  {
    digitalWrite (LED, HIGH) ;	// On
    delay (500) ;		// mS
    digitalWrite (LED, LOW) ;	// Off
    delay (500) ;
  }
#else

 for(;;){
  	for (i=0; i<28; i++){
		pinMode (wpi_led[i], OUTPUT) ;
		digitalWrite (wpi_led[i], HIGH) ;	// On
		delay (200) ;
 	 }

  	for (i=0; i<28; i++){
		pinMode (wpi_led[i], OUTPUT) ;
		digitalWrite (wpi_led[i], LOW) ;	// Off
		delay (200) ;
 	 }
 }

#endif

  return 0 ;
}
