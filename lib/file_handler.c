#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "word_tree.h"


char* word_printer(char*,...);
void fileCopy(FILE *,FILE *);
bool fileCheck(FILE *,char);


char* word_printer(char* fmt,...)
{
        va_list ap;
        char *p,*sval;
        int ival;
        double dval;

        va_start(ap,fmt);
        for ( p = fmt; *p; p++)
        {
                if (*p=='%')
                {
                        putchar(*p);
                        continue;
                }
                switch (*++p)
                {
                case 'i':
                        ival = va_arg(ap,int);
                        printf("%d",ival);
                        break;
                case 's':
                        for (sval = va_arg(ap,char*);*sval; sval++)
                                putchar(*p);
                        break;
                default:
                        putchar(*p);
                        break;
                }
                
        }
        va_end(ap);
        
        return p;
}

void fileCopy(FILE *input,FILE *output)
{
        int c;
        while ((c=getc(input)) != EOF)
        {
                putc(c,output);
        }

}


bool fileCheck(FILE *ip,char mode)
{
        if(fopen(ip,mode)){
                return true;
        }
        return false;
}

FILE* file_Reader_Writer(FILE *ip,char mode)
{
        if(fileCheck(ip,mode)){
                exit(); // exist this function if true
        }

        FILE *fp;

        fp =  fopen(ip,mode);

        return ;
}