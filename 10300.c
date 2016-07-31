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
    int nums, i, num_tc;
    int output, a, b, c;

    if(!fgets(line, 0xFF, stdin))
        return 1;

    nums = atoi(line);
    while(nums--)
    {
        if(!fgets(line, 0xFF, stdin))
            return 1;
        num_tc = atoi(line);
        output = 0;
        while(num_tc--)
        {
            if(!fgets(line, 0xFF, stdin))
                return 1;
            sscanf(line, "%d %d %d", &a, &b, &c);
            output += a * c;
        }
        printf("%d\n", output);
    }
    return 0;
}
