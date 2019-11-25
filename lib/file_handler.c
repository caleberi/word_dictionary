#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "word_tree.h"

#define MAX_LENGTH 10000

#define MAX_WORD 42
#define LINE_LENGTH_MAX 5000

char *word_printer(char *, ...);
void fileCopy(FILE *, FILE *);
bool fileCheck(const char *filename, const char *mode);

char *word_printer(char *fmt, ...)
{
        va_list ap;
        char *p, *sval;
        int ival;
        double dval;

        va_start(ap, fmt);
        for (p = fmt; *p; p++)
        {
                if (*p == '%')
                {
                        putchar(*p);
                        continue;
                }
                switch (*++p)
                {
                case 'i':
                        ival = va_arg(ap, int);
                        printf("%d", ival);
                        break;
                case 's':
                        for (sval = va_arg(ap, char *); *sval; sval++)
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

void fileCopy(FILE *input, FILE *output)
{
        int c;
        while ((c = getc(input)) != EOF)
        {
                putc(c, output);
        }
}

bool fileCheck(const char *filename, const char *mode)
{
        FILE *fp = fopen(filename, mode);
        if (fp)
        {
                free(fp);
                return true;
        }
        free(fp);
        return false;
}

char *file_Reader_Writer(const char *filename, const char *mode)
{
        if (!fileCheck(filename, mode))
        {
                exit(1); // exist this function if true
        }

        FILE *fp;

        fp = fopen(filename, mode);

        char *wordBuffer[MAX_LENGTH];
        int i;
        char strbuf[LINE_LENGTH_MAX];
        char *line;
        int lineSize = (sizeof(strbuf) / sizeof(char));
        while ((line = fgets(strbuf, lineSize, fp)))
        {
        }

        return NULL;
}

// char *split(const char *string)
// {
//         char *words[MAX_LENGTH / 2];

//         char *word = (char *)calloc(MAX_WORD, sizeof(char));
//         memset(word, ' ', sizeof(char));
//         static int index = 0;
//         int line_index = 0;
//         int word_index =0;

//         while (string[line_index] != '\n')
//         {
//                 const char c = string[line_index];
//                 if (c == ' ')
//                 {
//                         word[word_index+ 1] = '\0';
//                         memcpy(words+index,&word,sizeof(word));
//                         index+=1;
//                         if(word!=NULL)
//                         {
//                                 free(word);
//                                 char *word = (char *)calloc(MAX_WORD,sizeof(char));
//                                 memset(word, ' ', sizeof(char));
//                         }
//                         ++line_index;
//                         word_index =0;
//                         continue;
//                 }
//                 if (c == '\t')
//                         continue;
//                 if (c == '.')
//                         continue;
//                 if (c == ',')
//                         continue;

//                 word[word_index] = c;
//                 ++word_index;
//                 ++line_index;
//         }

//         index =0;
//         if(word!=NULL)
//         {
//                 free(word);
//         }
//         return *words;
// }

char **split(char *string)
{
        static char *words[MAX_LENGTH / 2];
        static int index = 0;
        // resetting words 
        for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++)
        {
                words[i] = NULL;
        }
        const char *delimiter = " ";
        char *ptr = strtok(string, delimiter);
        while (ptr != NULL)
        {
                words[index] = ptr;
                ptr = strtok(NULL, delimiter);
                ++index;
        }
        index = 0;
        return words;
}

int main()
{
        char   line[]   = "The nature of the beast of static storage in functions. You could do something like trigger alternate behavior based on a known input value (i.e. the caller sending a NULL as string resets index and wipes the array). But that's a hideous hack that covers the real problem; this is a terrible place to use a static array in the first place. ";
        char **splitted = split(line);
        int i =0;
        while(splitted[i]!=NULL){
                printf("%s\n", splitted[i]);
                ++i;
        }
}