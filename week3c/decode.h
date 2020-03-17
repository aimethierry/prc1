
#ifndef _ENCODE_H
#define _ENCODE_H

#include <stdlib.h>
#include <stdint.h>
#include<stdio.h> 
# define  bool int 
#define fail -1
#define success 0
 

uint8_t removeNoise(uint8_t pos, uint8_t value);
bool checkOddEven(uint8_t n);

//set bit into circles 
void setBit(uint8_t bit);

//set parity bits 
void setPBit(uint8_t bit);

//return bit which is well orderd 
uint8_t saveBit (uint8_t a, uint8_t b, uint8_t c,  uint8_t data);


//this check all bit and return it befotre its saved  
uint8_t checkBit(uint8_t a);


#endif