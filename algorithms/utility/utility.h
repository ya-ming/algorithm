#pragma once

#include <vector>

using namespace std;

bool isSorted(vector<int> &v, int left, int right)
{
    for (int i = left; i < right - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            return false;
        }
    }

    return true;
}

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}