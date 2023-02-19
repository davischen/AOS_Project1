//Hey your code goes here..!
//Hey your code goes here..!
//Hey your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define MAX_SIZE 128

void printfile(FILE* fp,char * keyword) {
    //char line_current[MAX_SIZE];
    //size_t len_total = sizeof(line_current);
    //char* line = malloc(sizeof(char) * MAX_SIZE);
    char *line = NULL;  //the line used to store the content from file
    size_t line_size = 0;     //length of the line
    ssize_t read; 
    //while (fgets(line_current, MAX_SIZE, fp) != NULL )
    while ((read = getline(&line, &line_size, fp)) != -1)
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
            if(strstr(line, keyword) != NULL)
            {
                printf("%s",line);
            }
        //    line[0]='\0';
        //}
    }
    if (line)
    {
        free(line);
    }
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