#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "administration.h"

void initializeArray(ANIMAL animalArray[], int Size)
{	
	int i;
	for(i = 0; i < Size; i++)
	{
		animalArray[i].Age = 0;
	}
}

//change the name very well 
int checkArrayLimit(ANIMAL animalArray[], int size)
{
	int i = 0;
	int cnt;
	
	while(i < size)
	{
		if(animalArray[i].Age == 0)
		{
			cnt = i;
			return cnt;
		}
		i = i+1;
	}
	return fail;
}

int searchAnimal(char * name,ANIMAL animalArray[], int size)
{
   /* local variable definition */
   int a = 0;
   int arraylimit = checkArrayLimit(animalArray, size);
   /* while loop execution */
   //    printf("array size us  %d \n", arraylimit);
   
   while(a < arraylimit) {
      int result = strcmp(animalArray[a].Name, name);
      if(result == 0)
      {
		  int res = a + 1;
		  printf("its found at index %d \n", res);
		  return res;
	  }
      a++;
   }
	printf("The animal is not found \n");
	return fail;
}

//implement your own functionsx
void showAnimals(ANIMAL animalArray[], int size)
{


	int emptyslot = checkArrayLimit(animalArray, size);
	int i;
	char species[MaxNameLength];

	for(i = 0; i < emptyslot; i++)
	{ 
		//better to use switch 
		if(animalArray[i].Species == Cat)
		{
			strcpy(species,"Cat");
		}
		else if(animalArray[i].Species == Dog)
		{
			strcpy(species,"Dog");
		}
		else if(animalArray[i].Species == GuineaPig)
		{
			strcpy(species,"GuinieaPig");
		}
		else if(animalArray[i].Species == Parrot)
		{
			strcpy(species,"Parrot");
		}
		
		printf("Name: %s, Species: %s, Age: %d\n", animalArray[i].Name, species, animalArray[i].Age);
	}
}

int addAnimal(ANIMAL *AnimalPtr, ANIMAL animalArray[], int size)
{

	if (checkArrayLimit(animalArray, size) == fail)
	{
		return fail;
	}
	else{
		int pos = checkArrayLimit(animalArray, size);
		//animalArray[pos] = *(AnimalPtr);
		*(animalArray + pos) = *AnimalPtr;
		return success;
	}
	
}


int removeAnimal(char * name, ANIMAL animalArray[], int size)
{
	int newSize = size;
	int j =0;
	int i;
	int arraylimit = checkArrayLimit(animalArray, size);
	while(j < arraylimit)
	{
		int position = searchAnimal(name, animalArray, size);
		printf("postion %d ", position);
		if((position > newSize) || (position == fail))
		{ 
			printf("cant get this position \n");
		}
		else
		{
		  for (i = position - 1; i < newSize - 1; i++)
		   {
		     animalArray[i] = animalArray[i+1];
		   }
			newSize = newSize -1;
			return success;
		}
		j=j + 1;
	} 
	return fail;
} 
