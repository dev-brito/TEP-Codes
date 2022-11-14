#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const int VECTOR_CAPACITY = 3;
    vector<int> v(VECTOR_CAPACITY);

    for (int i = 0; i < VECTOR_CAPACITY; i++)
        cin >> v[i];

    cout << ((v[2] >= v[0] && v[2] <= v[1]) ? "Yes" : "No") << '\n';

    return 0;
}