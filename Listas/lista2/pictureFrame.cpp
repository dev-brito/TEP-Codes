#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<vector<char>> matrizSaida(105, vector<char>(105));
    int rows, cols;
    cin >> rows >> cols;

    for (int i = 0; i < rows + 2; i++)
    {
        for (int j = 0; j < cols + 2; j++)
        {
            matrizSaida[i][j] = '#';
        }
    }

    for (int i = 1; i < rows + 2 - 1; i++)
    {
        for (int j = 1; j < cols + 2 - 1; j++)
        {
            cin >> matrizSaida[i][j];
        }
    }

    for (int i = 0; i < rows + 2; i++)
    {
        for (int j = 0; j < cols + 2; j++)
        {
            cout << matrizSaida[i][j];
        }
        cout << '\n';
    }

    return 0;
}