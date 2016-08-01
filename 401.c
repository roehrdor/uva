#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PALINDROM   0x1
#define MIRROR      0x2

const char * const mirror = "1SE\000Z\000\0008\000\000\000\000\000\000\000\000A"
                            "\000\000\0003\000\000HIL\000JM\000O\000\000\0002TU"
                            "VWXY5";

int main(int argc, char const *argv[])
{
    char line[0xFF];
    int state;
    char *p1, *p2;

    while(fgets(line, 0xFF, stdin))
    {
        if(line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = '\0';
        state = PALINDROM | MIRROR;
        p1 = &line[0];
        p2 = &line[strlen(line) - 1];
        for(; p2 >= p1; ++p1, --p2)
        {
            if(state == 0)
                break;
            if(*p1 != *p2)
                state &= ~PALINDROM;
            if(*p1 != mirror[*p2 - '1'])
                state &= ~MIRROR;
        }

        printf("%s", line);
        switch (state) {
            case 0:
                printf("%s\n\n", " -- is not a palindrome.");
                break;
            case PALINDROM:
                printf("%s\n\n", " -- is a regular palindrome.");
                break;
            case MIRROR:
                printf("%s\n\n", " -- is a mirrored string.");
                break;
            case PALINDROM | MIRROR:
                printf("%s\n\n", " -- is a mirrored palindrome.");
                break;
        }
    }
    return 0;
}
