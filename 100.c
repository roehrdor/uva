/* 17742498	100	The 3n + 1 problem	Accepted	ANSI C	0.000	2016-07-27 15:20:31 */

#include <stdio.h>

#define _CACHE 1

#ifdef _CACHE
#define CACHE_SIZE 0xFFFFF
int CACHE[CACHE_SIZE] = {0};
#endif

int n(int n)
{
    int counter, orig_n;
    counter = 0;
    orig_n = n;
    while(n != 1)
    {
#ifdef _CACHE
        if(n < CACHE_SIZE && CACHE[n] != 0)
        {
            counter += CACHE[n];
            break;
        }

#endif
        ++counter;
        if((n & 0x1) == 0x0)
        {
            n >>= 0x1;
        }
        else
        {
            n = n * 3 + 1;
        }
    }
#ifdef _CACHE
    if(orig_n < CACHE_SIZE)
        CACHE[orig_n] = counter;
#endif
    return counter + 1;
}

int m(int l, int h)
{
    int max, result;
    max = 0;
    for(; l <= h; ++l)
    {
        result = n(l);
        max = result > max ? result : max;
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int number1, number2, result;
    while(scanf("%d %d", &number1, &number2) != EOF)
    {
        result = number1 > number2 ? m(number2, number1) : m(number1, number2);
        printf("%d %d %d\n", number1, number2, result);
    }

    return 0;
}
