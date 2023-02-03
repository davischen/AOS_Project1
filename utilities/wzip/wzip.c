//Hey your code goes here..!
//Hey your code goes here..!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5
int c_prev;
int count=0;
void printfile(FILE* fp) {
    int c;
    char data_count[4]={0,0,0,0};
    char data[1]={0};
    while (EOF != (c = fgetc(fp))) {
        //if (c == '\n') break;
        //*line++ = c;
        //printf("%c",c);
        if(c_prev != c && c_prev>0)
        {
            if(count<256)
            {
                data_count[0]=count;
            }
            else{
                data_count[0]=count-256;
                data_count[1]=1;
            }
            data[0]=c_prev;
            fwrite(data_count,1, 4,stdout);
            data_count[1]=0;
            fwrite(data,1, 1,stdout);
            count=1;
        }
        else{
            count++;
        }
        c_prev=c;
    }
    //printf("======");
}
int main( int argc, char **argv )
{
    FILE *fp;
    char * exename_input_path = "";
    if(argc==1)
    {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    for(int i=1;i<argc;i++)
    {
        exename_input_path = argv[i];
        fp = fopen(exename_input_path, "r");
        if (fp == NULL )
        {
            printf("wzip: cannot open file\n");
            return 1;
        }
        printfile(fp);
        fclose(fp);
    }
    char data_count[4]={0,0,0,0};
    char data[1]={0};
    if(count<256)
    {
        data_count[0]=count;
    }
    else{
        data_count[0]=count-256;
        data_count[1]=1;
    }
    data[0]=c_prev;
    fwrite(data_count,1, 4,stdout);
    data_count[1]=0;
    fwrite(data,1, 1,stdout);
    return 0;
}
