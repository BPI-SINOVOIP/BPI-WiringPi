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
unsigned char buffer_temp[BUFFER_SIZE];  
  
void oled_begin();  
void oled_test();  
  
int main(void)  
{  
    FILE *fphzk;  
    time_t now;  
    struct tm *timenow;  
  
    wiringPiSetup();  
    fphzk=fopen("1024","rb");  
    fread(buffer,1,BUFFER_SIZE,fphzk);  
    fclose(fphzk);  
  
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
    int i,j,k;  
    unsigned char temp;  
  
    for(k=0;k<10000;k++)  
    {  
        digitalWrite(5, LOW);  
        wiringPiSPIDataRW(0, poscode, 5);  
        memcpy(buffer_temp, buffer, BUFFER_SIZE);                 
        digitalWrite(5, HIGH);  
        wiringPiSPIDataRW(0, buffer_temp, 1024);  
  
        for(i=0;i<BUFFER_SIZE;i+=128)  
        {  
            for(j=0;j<((i<256)?2:1);j++)  
            {  
                temp=buffer[i];  
                memcpy(&buffer[i], &buffer[i+1], 127);            
                buffer[i+127]=temp;  
            }  
        }  
        delay(10);  
    }  
}  
