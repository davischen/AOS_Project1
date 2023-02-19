//Your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 128
void reverse_print(FILE* fp, FILE* fw) {
    size_t line_size = MAX_SIZE;
    char *line = malloc(sizeof(char) * MAX_SIZE);
    if( fgets(line, line_size, fp) == NULL )
    {
        if (line)
        {
            free(line);
        }
        //free(line);
        return;
    }
    else {
        reverse_print(fp,fw);
        //printf("%s",line);
        fprintf(fw,"%s",line);
        
    }
    if (line)
    {
        free(line);
    }
    return;
}
int main( int argc, char **argv )
{
    FILE *fp;
    FILE *fw;
    if(argc>3)
    {
        fprintf(stderr,"usage: reverse <input> <output>\n");
        exit(1);
    }
    if(argc <=1)
    {
        reverse_print(stdin,stdout);
    }
    else{
        fp = fopen(argv[1], "r");
        if (fp == NULL )
        {
            fprintf(stderr,"reverse: cannot open file '%s'\n",argv[1]);
            exit(1);
        }
        if(strcmp(argv[1],argv[2])==0)
        {
            fprintf(stderr,"reverse: input and output file must differ\n");
            exit(1);
        }
        //char * exename_input_path = argv[1];
        //char * exename_output_path = argv[2];
        if(argc == 1)
        {
            //if (ferror(fp) && ferror(fw)) {
            reverse_print(fp,stdout);
        }
        else if(argc == 2)
        {
            reverse_print(fp,stdout);
        }
        else{
            if(strcmp(strrchr(argv[1], '/') ,strrchr(argv[2], '/'))==0)
            {
                fprintf(stderr,"reverse: input and output file must differ\n");
                exit(1);
            }
            fw = fopen(argv[2],"w");
            //if (ferror(fp) && ferror(fw)) {
            reverse_print(fp,fw);
            
            fclose(fw);
        }
        fclose(fp);
    }
    exit(0);
}
