#include <stdio.h>
#include "decode.h"

int main(int argc, char * argv[])
{
	
	if(argc != 3)
	{
		printf("Incorrect number of arguement \n ");
	}
	
	decodeFile(argv[1], argv[2]);	
	return 0;
}

int decodeFile(char * input , char * output)
{
	uint8_t msb,lsb, res_val,a;
	FILE * fprchannel  = fopen(input, "r");
	FILE * fpw = fopen(output, "w");
	
	if(!fprchannel)
	{
		printf("There is no such file to open in input \n");
	}
	
	if(!fpw)
	{
		printf("there is no such file to write \n ");
	}
	
	int count = 1;
	while(fread(&a, 1, 1, fprchannel) != 0)
	{
		if(count % 2 == 1)
		{
		//   setBit(a);
		  uint8_t f =  checkBit(a);
		  msb = (f>>3)<<4;
		}
		
		if(count % 2 == 0)
		{
		//   setBit(a);
		  uint8_t f_2 =  checkBit(a);
          lsb = f_2>>3;
          res_val = (msb|lsb);
          printf("save only this %c \n", res_val);
          fwrite(&res_val, 1, 1, fpw);	
		}
		count++;	
	}
	
	return 0;
}

uint8_t checkBit(uint8_t bit)
{
	uint8_t p0, p1, p2, d0, d1, d2,d3, res;
	p0 = 0x1;   d0=0x8;
	p1 = 0x2;	d1=0x10;
	p2 = 0x4;	d2=0x20;
				d3=0x40;
	
	int diagramA = p0|d0|d1|d2;
	int diagramB = p1|d0|d1|d3;
	int diagramC = p2|d1|d2|d3;

  //check for diagram 1
	if(checkOddEven(diagramA) == 0)
	{
		 uint8_t save = saveBit(2, 7, 3, bit);
		 if(save == 1)
		 {
		   printf("there is an error  \n");
		 }
		 else
		 {
		   return save;
		 }	 
	}
	
	//check in parity 1
	if(checkOddEven(diagramB) == 0)
	{
		 printf("change in  p0, d2 , p2   %d \n",(p1|d0|d1|d3));
		 uint8_t save = saveBit(p0, d2, p2, bit);
		 if(save == 1)
		 {
		   printf("there is an error  \n");
		 }
		 else
		 {
		   return save;
		 }
	 
	}	
	//check in parity 2
	if(checkOddEven(diagramC) == 0)
	{
	     printf("change  either p0, d0 , p1 %d \n",(p2|d1|d2|d3));
	     uint8_t save = saveBit(1, 4, 2, bit);
		 if(save == 1)
		 {
		   printf("there is an error  \n");
		 }
		 else
		 {
		   return save;
		 }    
	}
	//check in all intersection
	if((checkOddEven(diagramA) == 1) && ((checkOddEven(diagramB) == 1)) && ((checkOddEven(diagramC) == 1)))
	{
	  uint8_t res =  removeNoise(5, bit);
	  printf("change d1 %d \n", res);
	  return res;
	}
	else
	{
		printf("its well  balanced \n");
		return bit;
	}
  return 0;
}

//check whether the bits are odd or even
bool checkOddEven(uint8_t n) 
{ 
    bool parity = 0; 
    while (n != 0) { 
        parity = !parity; 
        n      = n & (n - 1); 
    }         
    return parity; 
} 

uint8_t removeNoise(uint8_t pos, uint8_t val)
{
	uint8_t out;
	out = val ^ (1<<(pos - 1));
	return out;
}

uint8_t pb0, pb1, pb2, db0, db1, db2,db3;
uint8_t saveBit(uint8_t first, uint8_t second, uint8_t third, uint8_t a)
{	
	uint8_t res = removeNoise(first, a);
	setPBit(res);
	if((checkOddEven(pb0|db0|db1|db2) == 0) && (checkOddEven(pb2|db1|db2|db3)==0) && (checkOddEven(pb1|db0|db1|db3) == 0))
	{
	   a = removeNoise(first, a);
	   return a;
	}
	res = removeNoise(second, a);
	setPBit(res);
	if((checkOddEven(pb0|db0|db1|db2) == 0) && (checkOddEven(pb2|db1|db2|db3)==0) && (checkOddEven(pb1|db0|db1|db3) == 0))
	{
	  a = removeNoise(second, a);
	  return a;
	}	 
	res = removeNoise(third, a);
	setPBit(res);
	if((checkOddEven(pb0|db0|db1|db2) == 0) && (checkOddEven(pb2|db1|db2|db3)==0) && (checkOddEven(pb1|db0|db1|db3) == 0))
	{
	   a = removeNoise(third, a);
	   return a;
	} 
	return 1;
}

void setPBit(uint8_t a)
{
  pb0 = 0b00000001 & a; pb1 = 0b00000010 & a; db1 = 0b00010000 & a;
  pb2 = 0b00000100 & a; db0 = 0b00001000 & a; db2 = 0b00100000 & a;
  db3 = 0b01000000 & a;
}



