#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST 0x1
#define SECOND 0x2

int main(int argc, char const **argv)
{
    char line[0xFF];
    char output[0xFF];
    char *pIn;
    char *pOut;
    int line_length;
    int i;
    int state;
    int pos;

    state = FIRST;
    while(fgets(line, 0xFF, stdin))
    {
        pos = 0;
        line_length = strlen(line);
        pIn = &line[0];
        pOut = &output[0];

        for(; *pIn; ++pIn, ++pOut)
        {
            if(*pIn == '\"')
            {
                switch (state) {
                    case FIRST:
                        *pOut = '`';
                        ++pOut;
                        *pOut = '`';
                        state = SECOND;
                    break;
                    case SECOND:
                        *pOut = '\'';
                        ++pOut;
                        *pOut = '\'';
                        state = FIRST;
                    break;
                }
            }
            else
            {
                *pOut = *pIn;
            }
        }
        *pOut = '\0';
        printf("%s", output);
    }
    return 0;
}
