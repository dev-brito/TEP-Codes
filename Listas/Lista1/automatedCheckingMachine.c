#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

bool isCompatible(int part1[SIZE], int part2[SIZE])
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        if (part1[i] == part2[i])
            return false;
    }
    return true;
}

int main()
{

    int part1[SIZE];
    int part2[SIZE];
    int i;

    while (scanf("%d", &part1[0]) != EOF)
    {
        for (i = 1; i < SIZE; i++)
        {
            scanf("%d", &part1[i]);
        }

        for (i = 0; i < SIZE; i++)
        {
            scanf("%d", &part2[i]);
        }

        printf("%c\n", isCompatible(part1, part2) ? 'Y' : 'N');
    }

    return 0;
}