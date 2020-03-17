#ifndef _ADMINISTRATION_H
#define _ADMINISTRATION_H

#include "animal.h"

#define success 0
#define fail -1


#define sizeArray 25

void initializeArray(ANIMAL animalArray[], int Size);

void showAnimals(ANIMAL animalArray[], int size);

int searchAnimal(char * name, ANIMAL animalArray[], int size);

int addAnimal(ANIMAL *AnimalPtr, ANIMAL animalArray[], int size);

int removeAnimal(char * name, ANIMAL animalArray[], int size);

int checkArrayLimit(ANIMAL animalArray[], int size);


#endif
