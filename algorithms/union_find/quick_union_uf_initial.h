#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace union_find_initial
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

        int root(size_t i)
        {
            // chase parent pointers until reach root
            // (depth of i array accesses)
            while (m_id[i] != i)
            {
                i = m_id[i];
            }

            return i;
        }

        int root_with_path_compression(size_t i)
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
            m_id[root(p)] = root(q);
        }

        void weighted_union_connections(size_t p, size_t q)
        {
            // change root of p to point to root of q
            // (depth of p and q array accesses)
            int i = root_with_path_compression(p);
            int j = root_with_path_compression(q);
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