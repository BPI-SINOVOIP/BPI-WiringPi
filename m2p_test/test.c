#include <stdio.h>
#include <wiringPi.h>


#define	LED 18

static int phy_led[] = {8, 10, 12, 16, 18, 22, 24, 26, 28, 32, 36, 38, 40,
			37, 35, 33, 31, 29, 27, 23, 21, 19, 15, 13, 11, 7, 5, 3};

static int bcm_led[] = {2, 3, 4, 17, 27, 22, 10, 9, 11, 0, 5, 6, 13, 19, 26,
			21, 20, 16, 12, 1, 7, 8, 25, 24, 23, 18, 15, 14};

static int wpi_led[] = {8, 9, 7, 0, 2, 3, 12, 13, 14, 30, 21, 22, 23, 24, 25,
			29, 28, 27, 26, 31, 11, 10, 6, 5, 4, 1, 16, 15};

static void phy_led_test(void)
{
    int i;

    printf("[BPI] phy led test\n");

    wiringPiSetupPhys();

    for(;;){
        for (i=0; i<28; i++){
                pinMode (phy_led[i], OUTPUT) ;
                digitalWrite (phy_led[i], HIGH) ;       // On
                delay (100) ;
         }

        for (i=0; i<28; i++){
                pinMode (phy_led[i], OUTPUT) ;
                digitalWrite (phy_led[i], LOW) ;        // Off
                delay (100) ;
         }
    }	
}

static void bcm_led_test(void)
{
    int i;

    printf("[BPI] bcm led test\n");

    wiringPiSetupGpio();

    for(;;){
        for (i=0; i<28; i++){
                pinMode (bcm_led[i], OUTPUT) ;
                digitalWrite (bcm_led[i], HIGH) ;       // On
                delay (100) ;
         }

        for (i=0; i<28; i++){
                pinMode (bcm_led[i], OUTPUT) ; 
                digitalWrite (bcm_led[i], LOW) ;        // Off
                delay (100) ;
         }
    }   
}

static void wpi_led_test(void)
{
    int i;

    printf("[BPI] wpi led test\n");

    wiringPiSetup();

    for(;;){
        for (i=0; i<28; i++){
                pinMode (wpi_led[i], OUTPUT) ;
                digitalWrite (wpi_led[i], HIGH) ;       // On
                delay (100) ;
         }

        for (i=0; i<28; i++){
                pinMode (wpi_led[i], OUTPUT) ;
                digitalWrite (wpi_led[i], LOW) ;        // Off
                delay (100) ;
         }
    }
}

static void single_led_test(void)
{
    wiringPiSetupPhys();
    pinMode (LED, OUTPUT) ;

    for (;;)
    {
        digitalWrite (LED, HIGH) ;
        delay (500) ;
        digitalWrite (LED, LOW) ;
        delay (500) ;
    }
}

int main (void)
{
    //single_led_test();
    phy_led_test();
    //bcm_led_test();
    //wpi_led_test();
    
    return 0 ;
}
