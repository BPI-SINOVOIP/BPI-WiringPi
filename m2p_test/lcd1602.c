#include <stdio.h>  
#include <wiringPi.h>  
#include <mcp23017.h>  
#include <lcd.h>  
#include <time.h>  
int main()  
{  
        time_t timep;  
        struct tm *ptm;  
        int display,i;  
		
        wiringPiSetup();  
	pinMode(8,I2C_PIN);
	pinMode(9,I2C_PIN);
		
        mcp23017Setup (100, 0x20);  
		
        for(i=0;i<16;i++)  
        	pinMode(100+i,OUTPUT);  
		
        digitalWrite(107,1);  
        digitalWrite(101,0);  
		
        display=lcdInit(2,16,4,100,102,103,104,105,106,0,0,0,0);  
        lcdHome(display);  
        lcdClear(display);  
		
        while(1)  
        {  
                time(&timep);  
                ptm=localtime(&timep);  
                lcdPosition(display,3,0);  
                lcdPrintf(display,"%04d/%02d/%02d",1900+ptm->tm_year, 1+ptm->tm_mon, ptm->tm_mday);  
                lcdPosition(display,4,1);  
                lcdPrintf(display,"%02d:%02d:%02d",ptm->tm_hour, ptm->tm_min, ptm->tm_sec);  
                delay(100);  
        }  
}  
