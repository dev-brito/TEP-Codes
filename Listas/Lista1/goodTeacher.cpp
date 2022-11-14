#include <bits/stdc++.h>
using namespace std;

string findClosestStudent(vector<string> students, int position)
{
    string answer;
    bool finded = false;
    int l = position, r = position;
    while (!finded && (l >= 0 && r <= students.size() - 1))
    {

        if (students.at(l).at(0) != '?' && students.at(r).at(0) != '?'){
            answer.append("middle of ");
            answer.append(students.at(l));
            answer.append(" and ");
            answer.append(students.at(r));
            finded = true;
        }

        else if (students.at(l).at(0) != '?')
        {
            int qtdPassos = abs(position - l);
            for (int i = 0; i < qtdPassos; i++)
                answer.append("right of ");
            answer.append(students.at(l));
            finded = true;
        }
        else if (students.at(r).at(0) != '?')
        {
            int qtdPassos = abs(position - r);
            for (int i = 0; i < qtdPassos; i++)
                answer.append("left of ");
            answer.append(students.at(r));
            finded = true;
        }
        if (l > 0)
            l--;
        if (r < students.size()-1)
            r++;
    }
    return answer;
}

int main()
{
    vector<string> students;
    string name;
    int nStudents, nQueries, position;

    cin >> nStudents;
    while (nStudents--)
    {
        cin >> name;
        students.push_back(name);
    }

    cin >> nQueries;

    while (nQueries--)
    {
        cin >> position;
        position--;
        switch (students[position].at(0))
        {
        case '?':
            cout << findClosestStudent(students, position) << endl;
            break;

        default:
            cout << students[position] << endl;
        }
    }

    return 0;
}