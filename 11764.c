#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int height[0x80];

int main(int argc, char const *argv[])
{
    char line[0xFF];
    int num_test_cases, line_len, i, j, up , down;
    char *p;

    if(!fgets(line, 0xFF, stdin))
        return 1;
    num_test_cases = atoi(line);
    for(j = 0; j < num_test_cases; ++j)
    {
        if(!fgets(line, 0xFF, stdin))
            return 1;
        line_len = atoi(line);
        if(!fgets(line, 0xFF, stdin))
            return 1;
        p = strtok(line, " ");
        i = 0;
        height[i++] = atoi(line);
        while((p = strtok(NULL, " ")))
            height[i++] = atoi(p);

        up = down = 0;
        for(i = 0; i < line_len - 1; ++i)
            if(height[i] < height[i + 1])   ++up;
            else if(height[i] > height[i + 1]) ++down;
        printf("Case %d: %d %d\n", j+1, up, down);
    }

    return 0;
}
