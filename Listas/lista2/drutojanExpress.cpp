#include <bits/stdc++.h>
#define DEBUG 0
using namespace std;

int main()
{

    int t;
    cin >> t;
    map<string, pair<queue<string>, int>> namesListMin;
    for (int i = 0; i < t; i++)
    {
        int m, n;
        string nameSingle;

        cin >> m >> n >> nameSingle;
        for (int j = 0; j < 5; j++)
        {
            string name;
            switch (j)
            {
            case 0:
                name = "Ja";
                break;
            case 1:
                name = "Sam";
                break;
            case 2:
                name = "Sha";
                break;
            case 3:
                name = "Sid";
                break;
            case 4:
                name = "Tan";
                break;
            }
            int qtd;
            cin >> qtd;
            while (qtd--)
            {
                string nameQueue;
                cin >> nameQueue;
                namesListMin[name].first.push(nameQueue);
                namesListMin[name].second = 0;
            }
        }
#if DEBUG
        for (auto [key, value] : namesListMin)
        {
            cout << key << ": ";
            while (!value.first.empty())
            {
                cout << value.first.front() << ' ';
                value.first.pop();
            }
            cout << '\n';
        }
#endif
        while (n >= 0)
        {
            string nameSingleAnt(nameSingle);
            int nR = n;
            int min = 0;
            while (nR-- > 0 && min++ < m)
            {
                namesListMin[nameSingleAnt].second += 1;
            }
            namesListMin[nameSingleAnt].first.push(namesListMin[nameSingleAnt].first.front());
            nameSingle = namesListMin[nameSingleAnt].first.front();
            namesListMin[nameSingleAnt]
                .first.pop();
            n -= (m + 2);
        }
        cout << "Case " << i + 1 << ":\n";
        for (auto [key, value] : namesListMin)
        {
            cout << key << ' ';
            cout << value.second;
            cout << '\n';
        }
        namesListMin.clear();
    }

    return 0;
}