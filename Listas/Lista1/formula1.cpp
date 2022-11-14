#include <bits/stdc++.h>


using ii = std::pair<int, int>;

int main()
{
    int rounds, players, pointsSystem, winners, points, point;
    std::vector<std::vector<ii>> placePoints(100, std::vector<ii>(100, ii(0, 0)));
    std::vector<ii> pointsSum(100, ii(0, 0));
    do
    {
        std::cin >> rounds >> players;

        if (rounds != 0 and players != 0)
        {
            for (int i = 0; i < rounds; i++)
                for (int j = 0; j < players; j++)
                    std::cin >> placePoints[i][j].first;

            std::cin >> pointsSystem;

            while (pointsSystem--)
            {
                std::cin >> winners;
                for (int position = 1; position <= winners; position++)
                {
                    std::cin >> points;

                    for (int i = 0; i < rounds; i++)
                        for (int j = 0; j < players; j++)
                            if (placePoints[i][j].first == position)
                                placePoints[i][j].second += points;
                }

                int sum = 0;
                for (int j = 0; j < players; j++)
                {
                    for (int i = 0; i < rounds; i++)
                    {
                        sum += placePoints[i][j].second;
                    }
                    pointsSum[j].first = j + 1;
                    pointsSum[j].second = sum;
                    sum = 0;
                }

                std::stable_sort(
                    &pointsSum[0],
                    &pointsSum[players],
                    [](const ii a, const ii b) -> bool
                    { return a.second > b.second; });

                for (int i = 0; i < players; i++)
                {
                    printf("%d", pointsSum[i].first);
                    if (pointsSum[i].second != pointsSum[i + 1].second)
                        break;
                    else
                        std::cout << ' ';
                }

                for (int i = 0; i < rounds; i++)
                    for (int j = 0; j < players; j++)
                        placePoints[i][j].second = 0;

                std::cout << std::endl;
            }
        }

    } while (rounds != 0 and players != 0);

    return 0;
}