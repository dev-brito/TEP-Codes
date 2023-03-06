#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int main()
{
    queue<ii> fila;
    int tests;
    cin >> tests;
    while (tests--)
    {
        int qtd, myJob;
        cin >> qtd >> myJob;
        for (int i = 0; i < qtd; i++)
        {
            int priority;
            cin >> priority;
            fila.push(ii(i, priority));
        }

        int min = 0;
        bool jobPrinted = false;
        while (!jobPrinted)
        {
            int priority = fila.front().second;
            bool temMaior = false;
            queue<ii> ver(fila);

            while (!ver.empty())
            {
                if (priority < ver.front().second)
                {
                    temMaior = true;
                    break;
                }
                ver.pop();
            }
            if (temMaior)
            {
                fila.push(fila.front());
            }
            else
            {
                jobPrinted = fila.front().first == myJob;
                min++;
            }
            fila.pop();
        }
        cout << min << '\n';
        while (!fila.empty())
        {
            fila.pop();
        }
    }

    return 0;
}