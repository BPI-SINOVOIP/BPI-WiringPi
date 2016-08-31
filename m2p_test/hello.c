#include <stdio.h>
#include <wiringPi.h>
#include <sr595.h>
 
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
 
unsigned char smile[8][8] = { \
        {0, 0, 1, 1, 1, 1, 0, 0}, \
        {0, 1, 0, 0, 0, 0, 1, 0}, \
        {1, 0, 1, 0, 0, 1, 0, 1}, \
        {1, 0, 0, 0, 0, 0, 0, 1}, \
        {1, 0, 1, 0, 0, 1, 0, 1}, \
        {1, 0, 0, 1, 1, 0, 0, 1}, \
        {0, 1, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 0, 0}  \
};
 
unsigned char H[8][8] ={ \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}  \
};
 
unsigned char  E[8][8] = { \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}  \
};
 
unsigned char  L[8][8] ={ \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}  \
};
 
unsigned char  O[8][8] ={ \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 0, 0, 1, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}  \
};

void * p[5] = {H, E, L, L, O};
 
void set(int x, int y, unsigned char color)
{
        int c;
        for(c=0; c<=2; c++)
        {
                if(bitRead(color, c))
                        digitalWrite(x + 100 + 8*c, 0);
        }
        digitalWrite(y + 124, 1);
 
        for(c=2; c>=0; c--)
        {
                if(bitRead(color, c))
                        digitalWrite(x + 100 + 8*c, 1);
        }
        digitalWrite(y + 124, 0);
}
 
 
int main(int argc, char *argv[])
{
        int i, j, color;

	//setup gpio pin to spi function
        wiringPiSetup();

	for(i = 10; i < 15; i++)
	{
		if(i == 11)
			continue;
		
		pinMode(i, SPI_PIN);
	}
		
        sr595Setup(100, 32, 12, 14, 10);
 
        for(i = 0; i < 32; i++)
        {
                pinMode(100 + i, OUTPUT);
        }
 
#if 1
        for(i =0; i< 24; i++)
        {
                digitalWrite(100 + i, 1);
        }
 
        for(i =0; i< 8; i++)
        {
                digitalWrite(124 + i, 0);
        }
 
#endif
 
        color = 0b010; //green
        if(argc > 1 )
        {
                color = atoi(argv[1]);
        }
 
        while(1)
        {
                int k;
                for(k=0; k<500; k++)
                {
                        for(i=0; i<8; i++)
                        {
                                for(j=0; j<8; j++)
                                {
                                        if(*(((unsigned char *)p[k/100])+j*8+i) == 1)
                                                //set(i, j, color);
                                                set(i, j, random()%7+1);
                                }
                        }
 
                        if(k%100 == 0)
                                delay(100);
                }
        }
}
