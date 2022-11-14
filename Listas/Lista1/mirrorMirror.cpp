#include <bits/stdc++.h>
using namespace std;

bool compareMatrix(vector<vector<char>> m1, vector<vector<char>> m2, int dimension)
{
    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
            if (m1[i][j] != m2[i][j])
                return false;

    return true;
}

void rotateMatrix90(vector<vector<char>> &m1, int dimension)
{
    for (int i = 0; i < dimension / 2; i++)
    {
        for (int j = i; j < dimension - i - 1; j++)
        {
            int temp = m1[i][j];
            m1[i][j] = m1[dimension - 1 - j][i];
            m1[dimension - 1 - j][i] = m1[dimension - 1 - i][dimension - 1 - j];
            m1[dimension - 1 - i][dimension - 1 - j] = m1[j][dimension - 1 - i];
            m1[j][dimension - 1 - i] = temp;
        }
    }
}

void reflectMatrix(vector<vector<char>> &m1, int dimension)
{
    for (int i = 0; i < dimension / 2; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            char tmp = m1[i][j];
            m1[i][j] = m1[dimension - i - 1][j];
            m1[dimension - i - 1][j] = tmp;
        }
    }
}

string solve(vector<vector<char>> pattern1, vector<vector<char>> pattern2, int dimension)
{
    vector<vector<char>> pattern1Copy;
    if (compareMatrix(pattern1, pattern2, dimension))
        return "preserved.";

    pattern1Copy = pattern1;
    rotateMatrix90(pattern1Copy, dimension);

    if (compareMatrix(pattern1Copy, pattern2, dimension))
        return "rotated 90 degrees.";

    rotateMatrix90(pattern1Copy, dimension);
    if (compareMatrix(pattern1Copy, pattern2, dimension))
        return "rotated 180 degrees.";

    rotateMatrix90(pattern1Copy, dimension);
    if (compareMatrix(pattern1Copy, pattern2, dimension))
        return "rotated 270 degrees.";

    pattern1Copy = pattern1;
    reflectMatrix(pattern1Copy, dimension);
    if (compareMatrix(pattern1Copy, pattern2, dimension))
        return "reflected vertically.";

    rotateMatrix90(pattern1Copy, dimension);
    if (compareMatrix(pattern1Copy, pattern2, dimension))
        return "reflected vertically and rotated 90 degrees.";

    rotateMatrix90(pattern1Copy, dimension);
    if (compareMatrix(pattern1Copy, pattern2, dimension))
        return "reflected vertically and rotated 180 degrees.";

    rotateMatrix90(pattern1Copy, dimension);
    if (compareMatrix(pattern1Copy, pattern2, dimension))
        return "reflected vertically and rotated 270 degrees.";

    return "improperly transformed.";
}

int main()
{
    int test = 1;
    vector<vector<char>> pattern1(15, vector<char>(15)), pattern2(15, vector<char>(15));
    int dimension;
    while (cin >> dimension)
    {
        for (int i = 0; i < dimension; i++)
        {
            for (int j = 0; j < dimension * 2; j++)
            {
                if (j < dimension)
                {
                    cin >> pattern1[i][j];
                }
                else
                {
                    cin >> pattern2[i][j % dimension];
                }
            }
        }
        cout << "Pattern " << test << " was " << solve(pattern1, pattern2, dimension) << endl;
        test++;
    }

    return 0;
}