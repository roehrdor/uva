#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isLetter(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}

char counter[0x7F];

int main(int argc, char const *argv[])
{
    char line[0xFF];
    char *p;
    int i, max;

    while(fgets(line, 0xFF, stdin))
    {
        memset(counter, 0, sizeof(char) * 0x7F);
        max = 0;
        p = &line[0];
        for(; *p; ++p)
        {
            if(isLetter(*p))
            {
                ++counter[*p];
            }
        }

        for(i = 'A'; i <= 'Z'; ++i)
            if(counter[i] > max) max = counter[i];
        for(i = 'a'; i <= 'z'; ++i)
            if(counter[i] > max) max = counter[i];
        for(i = 'A'; i <= 'Z'; ++i)
            if(counter[i] == max) printf("%c", i);
        for(i = 'a'; i <= 'z'; ++i)
            if(counter[i] == max) printf("%c", i);
        printf(" %d\n", max);
    }
    return 0;
}
