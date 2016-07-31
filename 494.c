#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isLetter(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

#define NO_WORD 0x0
#define IN_WORD 0x1


int main(int argc, char const *argv[])
{
    char line[0xFF];
    char *p;
    int state;
    int count;

    while(fgets(line, 0xFF, stdin))
    {
        count = 0;
        state = NO_WORD;
        p = &line[0];
        for(; *p; ++p)
        {
            if(isLetter(*p))
            {
                if(state == NO_WORD)
                {
                    ++count;
                    state = IN_WORD;
                }
            }
            else
            {
                if(state == IN_WORD)
                    state = NO_WORD;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
