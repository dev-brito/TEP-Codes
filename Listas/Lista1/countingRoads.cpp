#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> cities(51, 0);
    int n, m, c1, c2;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> c1 >> c2;
        cities[c1]++;
        cities[c2]++;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << cities[i] << '\n';
    }
    

    return 0;
}