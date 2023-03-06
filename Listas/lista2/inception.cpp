#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<string> sonhos;
    int queries;
    string query;

    cin >> queries;

    while (queries--)
    {
        cin >> query;
        if (query[0] == 'S')
        {
            string name;
            cin >> name;
            sonhos.push(name);
        }
        else if (query[0] == 'K')
        {
            if(!sonhos.empty()) sonhos.pop();
        }
        else
        {
            cout << (sonhos.empty() ? "Not in a dream" : sonhos.top()) << '\n';
        }
    }

    return 0;
}