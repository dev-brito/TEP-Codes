#include <stdio.h>
#define SIZE 501

void cleanScore(int players[SIZE])
{
    int i;
    for (i = 0; i < SIZE; i++)
        players[i] = 0;
}

int main()
{
    int j, r, i, score;
    int jogadores[SIZE];
    int i_maior;

    cleanScore(jogadores);

    while (scanf("%d%d", &j, &r) == 2)
    {
        i_maior = 0;
        for (i = 0; i < j * r; i++)
        {
            scanf("%d", &score);
            jogadores[i % j] += score;
        }

        for (i = 0; i < j; i++)
        {
            if (jogadores[i] >= jogadores[i_maior])
                i_maior = i;
        }
        printf("%d\n", i_maior + 1);
        cleanScore(jogadores);
    }

    return 0;
}