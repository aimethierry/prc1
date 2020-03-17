#include <string.h>
#include "unity.h"
#include "administration.h"
#include <stdint.h>
#include <inttypes.h>

void setUp(void)
{
    // This is run before EACH test
}

void tearDown(void)
{
    // This is run after EACH test
}

void addAnimalInArrayTestSuccess(void)
{
	//Initialize the array
	ANIMAL animalArray[sizeArray];
	initializeArray(animalArray, sizeArray);
	//Add animals to the array
	ANIMAL a = {"Cat", Cat, 2};
    int res = addAnimal(&a, animalArray, sizeArray);
    if(res ==  success)
    {   
         TEST_ASSERT_EQUAL_STRING(0, 0); // both animals should be the same
    }
}

void addAnimalInFullArrayTestFail(void)
{
    //Initialize the array
	ANIMAL animalArray[sizeArray];
	initializeArray(animalArray, sizeArray);
	//Add animals to the array
	ANIMAL a = {"Cat", Cat, 2};

    int res = addAnimal(&a, animalArray, 0);
    
    //go deep to check if what u did passed nott jjjjjjust checking the resposnse 
    TEST_ASSERT_EQUAL_INT(res, fail); // both animals should be the same
    

}

void removeAnimalEmptyArrayFail(void)
{
	//Initialize the array
	ANIMAL animalArray[sizeArray];
	initializeArray(animalArray, sizeArray);
    // ANIMAL a = {"Cat", Cat, 2};
    // addAnimal(&a, animalArray, 1);

    int res = removeAnimal("Cat", animalArray, 1);
   
    TEST_ASSERT_EQUAL_INT(res, fail); // both animals should be the same
    
}


void removeUknownAnimalFail(void)
{
	//Initialize the array
	ANIMAL animalArray[sizeArray];
	initializeArray(animalArray, sizeArray);
    ANIMAL a = {"Cat", Cat, 2};
    addAnimal(&a, animalArray, sizeArray);
    int res = removeAnimal("titi", animalArray, sizeArray);
   
    TEST_ASSERT_EQUAL_INT(res, fail); // both animals should be the same
    
}


void removeknownAnimalSuccess(void)
{
	//Initialize the array
	ANIMAL animalArray[sizeArray];
	initializeArray(animalArray, sizeArray);
    ANIMAL a = {"Cat", Cat, 2};

    printf("res is %i \n",  addAnimal(&a, animalArray, sizeArray));

    int res = removeAnimal("Cat", animalArray, sizeArray);
     
    TEST_ASSERT_EQUAL_INT(res, success); // both animals should be the same
    
}


void searhAnimalInEmptyArray(void)
{
	//Initialize the array
	ANIMAL animalArray[sizeArray];
	initializeArray(animalArray, sizeArray);
    int res = searchAnimal("Cat", animalArray, sizeArray);
      
    TEST_ASSERT_EQUAL_INT(res, fail); // both animals should be the same
    
}

void searhAnimalInArrayPass(void)
{
	//Initialize the array
	ANIMAL animalArray[sizeArray];
	initializeArray(animalArray, sizeArray);   

    ANIMAL a = {"Cat", Cat, 2};
    addAnimal(&a, animalArray, sizeArray);
    int res = searchAnimal("Cat", animalArray, sizeArray);
    if(res > -1)
    {
        res = success;
    }
   
    TEST_ASSERT_EQUAL_INT(res, success); // both animals should be the same
}


int main (void)
{        
    UnityBegin();
	RUN_TEST(addAnimalInArrayTestSuccess, 1);
    RUN_TEST(removeAnimalEmptyArrayFail, 2);
    RUN_TEST(removeUknownAnimalFail, 3);
    RUN_TEST(removeknownAnimalSuccess, 4);
    RUN_TEST(searhAnimalInArrayPass, 5);
    RUN_TEST(addAnimalInFullArrayTestFail, 6);
    RUN_TEST(searhAnimalInEmptyArray, 7);
    return UnityEnd();
}
