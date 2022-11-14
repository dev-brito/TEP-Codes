#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<vector<string>> names(500, vector<string>(500));
    vector<string> inputs;
    int n;
    int longestFilename;
    string input;
    while (cin >> n)
    {
        longestFilename = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            inputs.push_back(input);
            if (input.length() > longestFilename)
                longestFilename = input.length();
        }

        int columns = (double)(60 - longestFilename) / (double)(longestFilename + 2) + 0.9;
        int rows = (double)n / (double)columns + 0.9;

        sort(inputs.begin(), inputs.end());
        int a = 0;
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                names[j][i] = inputs[a++];
            }
        }

        for (int i = 0; i < 60; i++)
        {
            cout << '-';
        }
        cout << endl;
        a = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (a < n)
                {
                    a++;
                    cout << names[i][j];
                    int acrescimo = (j == columns - 1) ? 0 : 2;
                    for (int spaces = names[i][j].length(); spaces < longestFilename + acrescimo; spaces++)
                    {
                        cout << ' ';
                    }
                }
            }
            cout << endl;
        }

        inputs.clear();
    }

    return 0;
}