//Hey your code goes here..!
//Hey your code goes here..!
//Hey your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 512

void readfile(FILE *fp){
    char c[4];
    char c2[1];
    int count=0;
    while(1)
    {
        if(fread(c, 1,4, fp) <=0)
        {
            break;
        }
        else{
            count=c[0];
            //if(c[1]==1){
            count+=256*c[1];
            //}
        }
        if(fread(c2, 1,1, fp) <=0)
        {
            break;
        }
        //printf(">>%d %d %d %d \n%c\n",c[0],c[1],c[2],c[3],c2[0]);
        if(count >0)
        {
            //printf("==%d\n",c[0]);
            for(int i=0;i<count;i++)
            {
                printf("%c",c2[0]);
            }
            count=0;
        }
    }
}
int main( int argc, char **argv )
{
    FILE *fp;
    char * exename_input_path = "";
    if(argc==1)
    {
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    for(int i=1;i<argc;i++)
    {
        exename_input_path = argv[i];
        fp = fopen(exename_input_path, "r");
        if (fp == NULL )
        {
            printf("wunzip: cannot open file\n");
            return 1;
        }
        readfile(fp);
        fclose(fp);
    }
    return 0;
}
