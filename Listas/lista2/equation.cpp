#include <bits/stdc++.h>

using namespace std;

int pri(char a, char b)
{
    int pa, pb;
    if (a == '*' || a == '/')
        pa = 2;
    else if (a == '+' || a == '-')
        pa = 1;
    else if (a == '(')
        pa = 4;

    if (b == '*' || b == '/')
        pb = 2;
    else if (b == '+' || b == '-')
        pb = 1;
    else if (b == '(')
        pb = 0;

    return (pa > pb);
}

void solve(vector<char> exp)
{
    stack<char> p;
    p.push('(');
    char t;
    for (auto elem : exp)
    {
        if (elem >= '0' && elem <= '9')
            cout << elem;
        else if (elem == '(')
            p.push(elem);
        else if (elem == ')')
        {
            do
            {
                t = p.top();
                if (t != '(')
                    cout << t;
                p.pop();
            } while (t != '(');
        }
        else if (elem == '+' || elem == '-' ||
                 elem == '*' || elem == '/')
        {
            while (1)
            {
                t = p.top();
                p.pop();
                if (pri(elem, t))
                {
                    p.push(t);
                    p.push(elem);
                    break;
                }
                else
                {
                    cout << t;
                }
            }
        }
    }
    do
    {
        t = p.top();
        if (t != '(')
            cout << t;
        p.pop();
    } while (t != '(');
    cout << '\n';
    while (!p.empty())
        p.pop();
}

int main()
{
    int tests;
    cin >> tests;
    vector<char> exp;
    getchar();
    getchar();

    string l;
    char ch;
    int ln = 0;
    while (tests--)
    {
        while (getline(cin, l))
        {
            istringstream is;
            is.str(l);
            if (is >> ch) // now read individual chars from that line
                exp.push_back(ch);
            else
            {
                break;
            }
            ln++;
        }
        solve(exp);
        if (tests > 0)
        {
            cout << '\n';
        }
        exp.clear();
    }
    return 0;
}