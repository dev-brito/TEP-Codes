#include <bits/stdc++.h>

using namespace std;

bool findElementInVector(vector<int> v, int elem)
{
	for (auto x : v)
		if (x == elem)
			return true;
	return false;
}

int main()
{
	vector<int> g1{1, 3, 5, 7, 8, 10, 12}, g2{4, 6, 9, 11}, g3{2};
	int x, y;
	cin >> x >> y;

	if (findElementInVector(g1, x))
	{
		if (findElementInVector(g1, y))
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
	else if (findElementInVector(g2, x))
	{
		if (findElementInVector(g2, y))
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}
	else if (findElementInVector(g3, x))
	{
		if (findElementInVector(g3, y))
		{
			cout << "Yes";
		}
		else
		{
			cout << "No";
		}
	}

	cout << '\n';

	return 0;
}
