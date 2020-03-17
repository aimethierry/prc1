#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<stdio.h> 
# define  bool int 

uint8_t removeNoise(uint8_t pos, uint8_t value);
bool checkOddEven(uint8_t n);

//set bit into circles 
void setBit(uint8_t bit);

//set parity bits 
void setPBit(uint8_t bit);

//return bit which is well orderd 
uint8_t saveBit (uint8_t a, uint8_t b, uint8_t c);


//this check all bit and return it befotre its saved  
uint8_t checkBit(uint8_t a);

uint8_t msb,lsb, res_val,res, a;
uint8_t p0, p1, p2, d0, d1, d2,d3;
uint8_t pb0, pb1, pb2, db0, db1, db2,db3;

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
		  setBit(a);
		  uint8_t f =  checkBit(a);
		  msb = (f>>3)<<4;
		}
		
		if(count % 2 == 0)
		{
		  setBit(a);
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
  //check in parity 0
	if(checkOddEven(p0|d0|d1|d2) == 0)
	{
		 uint8_t save = saveBit(2, 7, 3);
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
	if(checkOddEven(p1|d0|d1|d3) == 0)
	{
		 printf("change in  p0, d2 , p2   %d \n",(p1|d0|d1|d3));
		 uint8_t save = saveBit(1, 6, 3);
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
	if(checkOddEven(p2|d1|d2|d3) == 0)
	{
	     printf("change  either p0, d0 , p1 %d \n",(p2|d1|d2|d3));
	     uint8_t save = saveBit(1, 4, 2);
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
	if((checkOddEven(p0|d0|d1|d2) == 1) && ((checkOddEven(p1|d0|d1|d3) == 1)) && ((checkOddEven(p2|d1|d2|d3) == 1)))
	{
	  uint8_t res =  removeNoise(5, a);
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
	// parity returns 1 when is odd 
	//and it return 0 when its even
    bool parity = 0; 
    while (n != 0) 
    { 
        parity = !parity; 
        n      = n & (n - 1); 
    }         
    return parity; 
} 


//this changes the bit from 0 to 1 or vice versa 
uint8_t removeNoise(uint8_t pos, uint8_t val)
{
	uint8_t out;
	out = val ^ (1<<(pos - 1));
	return out;
}

//this is set bit to its position 
void setBit(uint8_t a)
{
  p0 = 0b00000001 & a; p1 = 0b00000010 & a; p2 = 0b00000100 & a;
  d0 = 0b00001000 & a; d1 = 0b00010000 & a; d2 = 0b00100000 & a;
  d3 = 0b01000000 & a; 
}

//this set bit to its parity
uint8_t saveBit(uint8_t first, uint8_t second, uint8_t third)
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



