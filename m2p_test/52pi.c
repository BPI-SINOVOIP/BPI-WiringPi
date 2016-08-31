#include <wiringPi.h>  
#include <wiringPiSPI.h>  
#include <stdio.h>    
#include <stdlib.h>    
#include <stdint.h>  
#include <string.h>  
#include <time.h>  
  
unsigned char initcode[] = {  
    0xAE, 0xA8, 0x3F, 0xD3, 0x00, 0x40, 0xA1, 0xC8,  
    0xA6, 0xD5, 0x80, 0xDA, 0x12, 0x81, 0x00, 0xB0,  
    0xA4, 0xDB, 0x40, 0x20, 0x00, 0x00, 0x10, 0x8D,  
    0x14, 0x2E, 0xA6, 0xAF   
};  
  
unsigned char poscode[] = {  
    0x20, 0x00, 0xB0, 0x00, 0x10  
};  
  
#define BUFFER_SIZE 1024  
unsigned char buffer[BUFFER_SIZE];  

void oled_begin();  
void oled_test();  
  
int main(void)  
{  
    time_t now;  
    struct tm *timenow;
	int i;

    //setup gpio pin to spi function
    wiringPiSetup();
    for(i = 10; i < 15; i++)
    {
    	if(i == 11)
		continue;
		
	pinMode(i, SPI_PIN);
    }
		
    oled_begin();  
  
    time(&now);     
    timenow = localtime(&now);      
    printf("Start time is %s/n",asctime(timenow));    
  
    oled_test();  
  
    time(&now);     
    timenow = localtime(&now);      
    printf("End time is %s/n",asctime(timenow));    
  
    return 0;  
}  
  
void oled_begin()  
{         
    pinMode (5, OUTPUT) ;  
    pinMode (6, OUTPUT) ;  
    wiringPiSPISetup(0, 32*1000*1000);  
    digitalWrite(6,  LOW) ;  
    delay(50);  
    digitalWrite(6,  HIGH) ;  
    digitalWrite(5, LOW);  
    wiringPiSPIDataRW(0, initcode, 28);  
}  
  
void oled_test()  
{ 
	int r;
	FILE *fphzk;
	digitalWrite(5, LOW);
	wiringPiSPIDataRW(0, poscode, 5);
	fphzk=fopen("apple.dat","rb");
	r=fread(buffer,1,BUFFER_SIZE,fphzk);
	while(r>0)
	{
		digitalWrite(5, HIGH);
		wiringPiSPIDataRW(0, buffer, 1024);
		r=fread(buffer,1,BUFFER_SIZE,fphzk);
		delay(66);
	}
	fclose(fphzk);
}

