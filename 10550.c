#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char line[0xFF];
    int pos, t1, t2, t3, degrees;

    int doofig;

    while(fgets(line, 0xFF, stdin))
    {
        sscanf(line, "%d %d %d %d", &pos, &t1, &t2, &t3);
        if(pos == t1 && pos == t2 && pos == t3 && pos == 0)
            break;

        degrees = 1080;
        degrees += (pos + (pos < t1 ? 40 : 0) - t1) * 9;
        pos = t1;
        degrees += (t2 + (t2 < pos ? 40 : 0) - pos) * 9;
        pos = t2;
        degrees += (pos + (pos < t3 ? 40 : 0) - t3) * 9;

        printf("%d\n", degrees);
    }

    return 0;
}
