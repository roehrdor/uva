#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int numbers[0x80];

int ggt(int, int);

int main(int argc, char const *argv[])
{
    char line[0xFF];
    int num_numbers, i, j, num_pairs, num_diff;
    double pi;

    while(fgets(line, 0xFF, stdin))
    {
        num_diff = 0;
        num_pairs = 0;
        i = num_numbers = atoi(line);
        if(num_numbers == 0)
            continue;
        while(i--)
        {
            if(!fgets(line, 0xFF, stdin))
                return 1;
            numbers[num_numbers - 1 - i] = atoi(line);
        }

        num_pairs = (num_numbers - 1) * num_numbers >> 0x1;

        for(i = 0; i < num_numbers; ++i)
        {
            for(j = i + 1; j < num_numbers; ++j)
            {
                if(ggt(numbers[i], numbers[j]) == 1)
                    ++num_diff;
            }
        }

        if(num_diff == 0)
        {
            printf("%s\n", "No estimate for this data set.");
        }
        else
        {
            pi = sqrt(6.0 / (num_diff / (double)num_pairs));
            printf("%.6f\n", pi);
        }
    }
    return 0;
}

int ggt(int a, int b)
{
    if (a == 0)    	return b;
    while(b != 0)
    	if (a > b)  a = a - b;
        else        b = b - a;
    return a;
}
