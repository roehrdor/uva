#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char line[0xFF];
    int x, y, nx, ny;

    if(!fgets(line, 0xFF, stdin))
        return 1;
    while(fgets(line, 0xFF, stdin))
    {
        sscanf(line, "%d %d", &x, &y);
        x -= 2;
        y -= 2;
        nx = x / 3;
        ny = y / 3;
        nx += nx * 3 < x ? 1 : 0;
        ny += ny * 3 < y ? 1 : 0;
        printf("%d\n", nx * ny);
    }

    return 0;
}
