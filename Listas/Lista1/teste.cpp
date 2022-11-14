#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> vetor(100, vector<int>(100));
    int col, rows;
    cin >> col >> rows;
    int a = 0;
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            vetor[j][i] = a++;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << vetor[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}