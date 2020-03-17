#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "byteHandle.h"
#include <time.h>

int main(int argc,char* argv[]) {

    srand(time(NULL));
    FILE *infile;
    FILE *outfile;
    BYTE inputByte;
    char letterBin[CHAR_BIT_ARRAY];
    switch (argc)
    {
        case 3:
            infile = fopen(argv[1],"r");
            if(infile == NULL)
            {
                fprintf(stderr, "\nError opening in file\n");
            }
            outfile = fopen (argv[2], "w");
            if (outfile == NULL)
            {
                fprintf(stderr, "\nError opening outfile\n");
            }
            break;
        default:
            printf("Invalid Paremeters");
            exit (1);
            break;
    }




    // read file contents till end of file
    int changesPerPos[USEDBITSAMOUNT];
    int j;
    for (j = 0; j < USEDBITSAMOUNT; ++j) {
        changesPerPos[j] = 0;
    }
    int bitCount;
    int res = fread(&inputByte, 1, 1, infile);
    while (res != 0)
    {
        int pos = rand() % USEDBITSAMOUNT;
        switch (pos)
        {
            case 0:
                inputByte.d0 = 1 - inputByte.d0;
                break;
            case 1:
                inputByte.d1 = 1 - inputByte.d1;
                break;
            case 2:
                inputByte.d2 = 1 - inputByte.d2;
                break;
            case 3:
                inputByte.d3 = 1 - inputByte.d3;
                break;
            case 4:
                inputByte.p0 = 1 - inputByte.p0;
                break;
            case 5:
                inputByte.p1 = 1 - inputByte.p1;
                break;
            case 6:
                inputByte.p2 = 1 - inputByte.p2;
                break;
        }
        changesPerPos[pos]++;
        bitCount++;
        fwrite(&inputByte, 1, 1, outfile);
        res = fread(&inputByte, 1, 1, infile);

    }
    fclose (infile);
    fclose (outfile);
    printf("Amount of bytes changed: %i\n",bitCount);
    int i;
    for (i = 0; i < USEDBITSAMOUNT; ++i) {
        printf("Position: %i Count of changed: %i Percentage: %f\n",i,changesPerPos[i],changesPerPos[i]/(float)bitCount);
    }
    return 0;
}