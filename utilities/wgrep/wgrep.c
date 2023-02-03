//Hey your code goes here..!
//Hey your code goes here..!
//Hey your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024

void printfile(FILE* fp,char * keyword) {
    char line_current[MAX_SIZE];
    //size_t len_total = sizeof(line_current);
    //char* line = malloc(sizeof(char) * MAX_SIZE);
    while (fgets(line_current, MAX_SIZE, fp) != NULL )
    {
        /*size_t len_used=strlen(line);
        size_t chunk_used=strlen(line_current);
        if(len_total-len_used<chunk_used){//space large than current 
            len_total*=2;
        }
        strncpy(line+len_used,line_current,len_total-len_used-1);
        len_used+=chunk_used;

        if(line[len_used-1]=='\n')
        { */
            if(strstr(line_current, keyword) != NULL)
            {
                printf("%s",line_current);
            }
        //    line[0]='\0';
        //}
    }
    /*if (line)
    {
        free(line);
        line=NULL;
    }*/
}
int main( int argc, char **argv )
{
    FILE *fp;
    char * exename_input_path ="";
    if(argc<2)
    {
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }
    else if(argc ==2)
    {
        printfile(stdin,argv[1]);
    }
    else{
        for(int i=2;i<argc;i++)
        {
            exename_input_path = argv[i];
            fp = fopen(exename_input_path, "r");
            if (fp == NULL )
            {
                printf("wgrep: cannot open file\n");
                return 1;
            }
            printfile(fp,argv[1]);
            fclose(fp);
        }
    }
    
    return 0;
}