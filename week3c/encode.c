#include <stdio.h>
#include "encode.h"


int main(int argc, char * argv[]) 
{ 
	if(argc != 3)
	{
		printf("Incorrect number of arguement \n ");
	}
	encodeFile(argv[1], argv[2]);
  return success;
} 


int encodeFile(char * input, char * output)
{
	FILE * fpr = fopen(input, "r");
	FILE *fpw = fopen(output, "wb");
	uint8_t msb,lsb, a;
	if(!fpr)
	{
		printf("There is no such file to open in input \n");
	}
	
	if(!fpw)
	{
		printf("there is no such file to write \n ");
	}
    while(fread(&a, 1, 1, fpr) != 0)
	{ 
	  printf(" a value  is %c \n", a);
	  msb = a >> 4;
      lsb = a&0x0F;
	  printf("%d \n", msb);
	  printf("%d \n", lsb);
	  uint8_t fmsb =  getParity(msb);
	  uint8_t flsb =  getParity(lsb);
	  fwrite(&fmsb, 1, 1, fpw);	
	  fwrite(&flsb, 1, 1, fpw);		
	} 
	return success;
}
uint8_t getParity(uint8_t n) 
{ 
	uint8_t res = n << 3;
	uint8_t po, p1, p2, d0, d1, d2, d3, fres;  
    uint8_t maskD0 = 0b00001000;
	int i = 1;
    uint8_t maskD1 = maskD0<<1;
    uint8_t maskD2 = maskD1<<1;
    uint8_t maskD3 = maskD2<<1; 
	


    //settin d0
    if((res & maskD0)){
        d0 = maskD0;
    }else{
    	d0 = 0b00000000;
    }
    //setting d1
    if((res & maskD1)){
    	d1 = maskD1;
    }else{
    	d1 = 0b00000000;
    }
    //setting d2
    if((res & maskD2)){
    	d2 = maskD2;
    }
    else{
    	d2 = 0b00000000;
    }
    //setting d3
    if((res & maskD3)){
    	d3 = maskD3;
    }else{
    	d3 = 0b00000000;
    }

	if( checkOddEven(((d0 ^ d1) ^ d2)) == 1){
		po = 0b00000001;
	}else{
		po = 0;
	}
	if( checkOddEven(((d0 ^ d1) ^ d3)) == 1){
		p1 = 0b00000010;
	}else{
		p1 = 0;
	}
	if( checkOddEven(((d1 ^ d2) ^ d3)) == 1){
		p2 = 0b00000100;
	}else{
		p2 = 0;
	}
	fres = po | p1 | p2  | d0 | d1 | d2 | d3;
	printf("res is %d \n", res);
	return fres;
} 

bool checkOddEven(uint8_t n) 
{ 
    bool parity = 0; 
    while (n != 0) 
    { 
        parity = !parity; 
        n      = n & (n - 1); 
    }         
    return parity; 
} 






