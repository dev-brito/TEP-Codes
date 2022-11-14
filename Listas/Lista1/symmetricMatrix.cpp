#include <iostream>
#include <string>

#define SIZE 10000
using namespace std;

void fillMatrix(long long int matrix[SIZE], int size)
{
    for (int i = 0; i < (size * size); i++)
        cin >> matrix[i];
}

bool isSymmetric(long long int matrix[SIZE], int dimension)
{
    int s = 0, e = (dimension * dimension) - 1;
    while (s < e)
    {
        // cout << '\n' << matrix[s] << ' ' << matrix[e] << '\n';
        if ((matrix[s] != matrix[e]) || (matrix[s] < 0) || (matrix[e] < 0))
            return false;
        s++;
        e--;
    }
    if ((dimension % 2 != 0) && (matrix[s] < 0))
        return false;
    return true;
}

int main()
{
    long long int matrix[SIZE];
    string dimension;
    int tests, i;
    cin >> tests;
    cin.ignore(256, '\n');

    for (int i = 0; i < tests; i++)
    {
        getline(cin, dimension);
        fillMatrix(matrix, stoi(dimension.substr(4)));
        cout << "Test #" << i + 1 << (isSymmetric(matrix, stoi(dimension.substr(4))) ? ": Symmetric" : ": Non-symmetric")
             << ".\n";
        cin.ignore(256, '\n');
    }

    return 0;
}