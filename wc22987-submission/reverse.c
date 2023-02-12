//Your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 128
void reverse_print(FILE* fp, FILE* fw) {
    size_t len = MAX_SIZE;
    char *line = malloc(sizeof(char) * MAX_SIZE);
    if( fgets(line, len, fp) == NULL )
        return;
    else {
        reverse_print(fp,fw);
        //printf("%s",line);
        fprintf(fw,"%s",line);
        if (line)
        {
            free(line);
        }
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
        return 1;
    }
    if(argc <=1)
    {
        reverse_print(stdin,stdout);
    }
    else{
        char * exename_input_path = argv[1];
        char * exename_output_path = argv[2];
        fp = fopen(exename_input_path, "r");
        if (fp == NULL )
        {
            fprintf(stderr,"reverse: cannot open file '%s'\n",exename_input_path);
            return 1;
        }
        int result = strcmp(exename_input_path, exename_output_path);
        //printf("%d\n",result);
        if(result == 0)
        {
            fprintf(stderr,"reverse: input and output file must differ\n");
            return 1;
        }
        if(argc == 2)
        {
            reverse_print(fp,stdout);
            fclose(fp);
        }
        else{
            char * exename_input = strrchr(exename_input_path, '/');
            char * exename_output = strrchr(exename_output_path, '/');
            result = strcmp(exename_input, exename_output);
            if(result == 0)
            {
                fprintf(stderr,"reverse: input and output file must differ\n");
                return 1;
            }
            fw = fopen(exename_output_path,"w");
            //if (ferror(fp) && ferror(fw)) {
            reverse_print(fp,fw);
            fclose(fp);
            fclose(fw);
        }
    }
    
    return 0;
}
