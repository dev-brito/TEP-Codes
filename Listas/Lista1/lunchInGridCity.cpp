#include <bits/stdc++.h>
using namespace std;

int mediana(vector<int> valores, int tam)
{
    int mediana;
    sort(valores.begin(), valores.end());
    if (tam % 2 == 0)
    {
        int medio = tam / 2;
        mediana = minmax(valores.at(medio), valores.at(medio - 1)).first;
    }
    else
    {
        mediana = valores.at(tam / 2);
    }
    return mediana;
}

int main()
{
    int tests;
    vector<int> localizationS, localizationA;
    cin >> tests;
    while (tests--)
    {
        int s, a, f;
        cin >> s >> a >> f;
        for (int i = 0; i < f; i++)
        {
            int x, y;
            cin >> x >> y;
            localizationS.push_back(x);
            localizationA.push_back(y);
        }
        sort(localizationS.begin(), localizationS.end());
        sort(localizationA.begin(), localizationA.end());
        int medianaS, medianaA = 0;

        printf("(Street: %d, Avenue: %d)\n", mediana(localizationS, localizationS.size()), mediana(localizationA, localizationA.size()));
        localizationS.clear();
        localizationA.clear();
    }
    return 0;
}