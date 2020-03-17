
#ifndef _ENCODE_H
#define _ENCODE_H

#include <stdint.h>
#include <stdlib.h>
# define  bool int 
#define success 0
#define fail -1

uint8_t getParity(uint8_t n);
bool checkOddEven(uint8_t n);

#endif