//Hey your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 128

void printfile(FILE* fp) {
    char* input = malloc(sizeof(char) * MAX_SIZE);
    while(1)
    {
        if( fgets(input, MAX_SIZE, fp) == NULL )
        {
          break;
        }
        else{
          printf("%s",input);
        }
          
    }
    if(input)
    {
        free(input);
    }
}
int main( int argc, char **argv )
{
    FILE *fp;
    char * exename_input_path = "";
    for(int i=1;i<argc;i++)
    {
        exename_input_path = argv[i];
        fp = fopen(exename_input_path, "r");
        if (fp == NULL )
        {
            printf("wcat: cannot open file\n");
            return 1;
        }
        printfile(fp);
        fclose(fp);
    }
    
    return 0;
}