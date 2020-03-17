/*
 * Menu animal_shelter.c
 *
 *  
 */

#include <stdio.h>
#include "animal.h"
#include <string.h>
#include <stdlib.h>

#include "administration.h"

#include <ctype.h>

int main (void)
{
    printf ("PRC assignment 'Animal Shelter' (version april 2019)\n");
          
    ANIMAL AnimalArray[sizeArray];
    ANIMAL NewAnimal;     
    
    initializeArray(AnimalArray, sizeArray);
    
          
    int choice = -1;
    while (choice != 0)
    {
        printf ("\nMENU\n====\n");
        printf ("1: Show Animals \n");
        printf ("2: Add Animal \n");
        printf ("3: Remove Animal \n");
        printf ("4: Find Animal by name \n");
        printf ("0: quit \n");
        // int ageSize = 5;
        scanf ("%d", &choice);
		
        switch (choice)
        {
            case 1: //Show Animals
				printf ("show Animals\n");
				showAnimals(AnimalArray, sizeArray);
                break;
            case 2: //Add Animal
				//Reading a given string to add to data to the array
				
                

                printf ("add Animal\n");
                printf("Name: \n");
				scanf("%s", NewAnimal.Name);
				
				// scanf("%d", &NewAnimal.Age);
                int newAge;
                printf("Age: \n");
                scanf("%i", &newAge);

                if(newAge < 0 )
                {
                    printf("please enter the right age \n");
                    printf("Age: \n");
                    scanf("%i", &newAge);
                }
                else
                {
                    NewAnimal.Age =newAge;
                }

				//Converting string to enum and read the data
				char species_temp[MaxNameLength];
				printf("Species: \n");
				scanf("%s", species_temp);
				if(strcmp(species_temp,"Cat") == 0)
				{
					NewAnimal.Species = Cat;
				}
				if(strcmp(species_temp,"Dog") == 0)
				{
					NewAnimal.Species = Dog;
				}
				if(strcmp(species_temp,"GuineaPig") == 0)
				{
					NewAnimal.Species = GuineaPig;
				}
				if(strcmp(species_temp,"Parrot") == 0)
				{
					NewAnimal.Species = Parrot;
				}

                //species which does exist 
                //check if the ret
				if(addAnimal(&NewAnimal, AnimalArray, sizeArray) == fail)
                {
                    printf("the animal is not added \n");
                }
                else
                {
                    printf("the animal is well added \n");
                }
                break;
            
            case 3: //Remove Animal
				 printf ("remove Animal\n");
				 char removeName[MaxNameLength];
                 scanf("%s", removeName);

                if(removeAnimal(removeName, AnimalArray, sizeArray) == fail)
                {
                    printf("element is not well removed \n");
                }
                if(removeAnimal(removeName, AnimalArray, sizeArray) == success)
                {
                    printf("the element is well removed \n");
                }
                 break;
            case 4://find by name
                 printf ("find by name\n");
                 char name[MaxNameLength];
                 scanf("%s", name);
                 if(searchAnimal((name), AnimalArray, sizeArray) == success)
                 {
                    printf("done well \n");
                 }

                 if(searchAnimal((name), AnimalArray, sizeArray) == success)
                 {
                    printf("done well \n");
                 }
                 break;
            case 0:
                break;
            default:
                printf ("ERROR: invalid choice: %d\n", choice);
                break;
		}
	}
    return 0;
}
