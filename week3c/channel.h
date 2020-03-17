
#ifndef _ENCODE_H
#define _ENCODE_H

#include <stdint.h>
#include <stdlib.h>
#include<time.h> 
# define  bool int 

#define success 0
#define fail -1

#define arraySize 8
#define countmaxRandomBit 8

int channelFile(char * input , char * output);
uint8_t flipBit(uint8_t pos, uint8_t val);
#endif