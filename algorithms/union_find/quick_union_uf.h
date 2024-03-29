#pragma once

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

namespace union_find
{
    class QuickUnionUF
    {
    private:
        vector<size_t> m_id;
        vector<size_t> m_sz;

    public:
        QuickUnionUF(size_t n)
        {
            m_id.reserve(n);
            // set id of each object to itself
            // (N array accesses)
            for (size_t i = 0; i < n; i++)
            {
                m_id.push_back(i);
                m_sz.push_back(0);
            }
        }

        void print(size_t itemsPerRow)
        {
            for (size_t i = 0; i < m_id.size(); i++)
            {
                cout << right << setw(3) << m_id[i] << " ";
                if (i % itemsPerRow == 0)
                    cout << endl;
            }
            cout << endl;
        }

        int root(size_t i)
        {
            // chase parent pointers until reach root
            // (depth of i array accesses)
            while (m_id[i] != i)
            {
                // Make every other node in path point to its
                // grandparent (thereby halving path length)
                m_id[i] = m_id[m_id[i]];
                i = m_id[i];
            }

            return i;
        }

        bool connected(size_t p, size_t q)
        {
            // check if p and q have same root
            // (depth of p and q array accesses)
            return root(p) == root(q);
        }

        void union_connections(size_t p, size_t q)
        {
            // change root of p to point to root of q
            // (depth of p and q array accesses)
            int i = root(p);
            int j = root(q);
            if (m_sz[i] < m_sz[j])
            {
                m_id[i] = j;
                m_sz[j] += m_sz[i];
            }
            else
            {
                m_id[j] = i;
                m_sz[i] += m_sz[j];
            }
        }
    };
}