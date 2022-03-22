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

void print(vector<int> &v, int lt, int i, int gt, bool header = false)
{
    if (header)
    {
        cout << std::right << std::setw(2) << " lt " << std::setw(2) << "i " << std::setw(2) << "gt | ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << std::right << std::setw(2) << i << " ";
        }
        cout << endl;
        cout << " ";
        for (int i = 0; i < v.size() + 3; i++)
        {
            cout << "---";
        }
    }
    else
    {
        cout << std::right << std::setw(2) << lt << " " << std::setw(2) << i << " " << std::setw(2) << gt << " | ";
        for (int i = 0; i < v.size(); i++)
        {
            cout << std::right << std::setw(2) << v[i] << " ";
        }
    }

    cout << endl;
}