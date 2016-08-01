#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ascii[0x7F];

int main(int argc, char const *argv[])
{
    char line[0xFF];
    int  line_len, pos;
    char min;
    char *p, *p_start;

    while(fgets(line, 0xFF, stdin))
    {
        if(line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
        if(strcmp(line, "#") == 0)
            break;

        line_len = strlen(line);
        memset(ascii, 0, sizeof(char) * 0x7F);
        p_start = &line[0];
        p = p_start + line_len - 1;
        while((--p) >= p_start && *p >= *(p+1))
            ;
        if((p + 1) == p_start)
        {
            printf("%s\n", "No Successor");
            continue;
        }

        p_start = p;
        for (; *p; ++p)
            ++ascii[*p];
        p = p_start;
        for(pos = *p + 1; pos < 0x7F; ++pos)
        {
            if(ascii[pos] != 0)
            {
                *p = pos;
                ++p;
                --ascii[pos];
                break;
            }
        }


        for(pos = 'A'; pos < 0x7F; ++pos)
        {
            while(ascii[pos] > 0)
            {
                *p = pos;
                ++p;
                --ascii[pos];
            }
        }

        printf("%s\n", line);
    }

    return 0;
}
