#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "channel.h"

uint8_t flipBit(uint8_t pos, uint8_t val);

int main(int argc, char * argv[])
{
	
	if(argc != 3)
	{
		printf("Incorrect number of arguement \n ");
	}
	
	channelFile(argv[1], argv[2]);	
	return success;
}

int channelFile(char * input , char * output)
{
	FILE * fpr = fopen(input, "r");
	FILE *fpw = fopen(output, "wb");
	int BitInPos[arraySize];
	uint8_t a;
	
	if(!fpr)
	{
		printf("There is no such file to open in input \n");
	}
	
	if(!fpw)
	{
		printf("there is no such file to write \n ");
	}


	for(int i =0; i < arraySize; i++)
	{
		BitInPos[i] = 0;
	}
			 
    while(fread(&a, sizeof(char), 1, fpr) != (int)NULL)
	{
	  srand(time(0));
	  int randBit = rand() % countmaxRandomBit;
	  BitInPos[randBit]++;
	  printf("flipped bit is %i \n", randBit);
	  uint8_t res = flipBit(randBit, a);
	  printf("the result is %d \n", res);
	  fwrite(&res, 1, 1, fpw);	
	  printf("\n");
	}
	fclose(fpr);
    fclose (fpw);

	for(int i =0; i < arraySize; i++)
	{
		printf ("position %i, and its value %d  percentage is \n", i, BitInPos[i]);
	}
	return success;
}

uint8_t flipBit(uint8_t pos, uint8_t val)
{
	uint8_t out;
	out = val ^ (1<<(pos - 1));
	return out;
}

