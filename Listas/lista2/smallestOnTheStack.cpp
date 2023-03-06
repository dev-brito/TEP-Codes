#include <bits/stdc++.h>
using namespace std;

using ll = pair<long int, long int>;
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<ll> pilha;
    long int queries;

    cin >> queries;

    while (queries--)
    {
        string operation;
        cin >> operation;
        if (operation == "PUSH")
        {
            long int n;
            cin >> n;
            if (pilha.empty())
            {
                pilha.push(ll(n, n));
            }
            else
            {
                if (n < pilha.top().second)
                {
                    pilha.push(ll(n, n));
                }
                else
                {
                    pilha.push(ll(n, pilha.top().second));
                }
            }
        }
        else if (operation == "MIN")
        {
            if (pilha.empty())
            {
                cout << "EMPTY" << '\n';
            }
            else
            {
                cout << pilha.top().second << '\n';
            }
        }
        else if (operation == "POP")
        {
            if (pilha.empty())
            {
                cout << "EMPTY" << '\n';
            }
            else
            {
                pilha.pop();
            }
        }
    }

    return 0;
}