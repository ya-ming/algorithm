#pragma once

#include <iostream>
#include <vector>

using namespace std;

namespace union_find
{
    class QuickFindUF
    {
    private:
        vector<size_t> m_id;
    public:
        QuickFindUF(size_t n)
        {
            m_id.reserve(n);
            // set id of each object to itself
            // (N array accesses)
            for (size_t i = 0; i < n; i++)
            {
                m_id.push_back(i);
            }
        }

        bool connected(size_t p, size_t q)
        {
            // check whether p and q are in the same component
            // (2 array accesses)
            return m_id[p] == m_id[q];
        }

        void union_connections(size_t p, size_t q)
        {
            size_t pid = m_id[p];
            size_t qid = m_id[q];

            // change all entries with id[p] to id[q]
            // (at most 2N + 2 array accesses)
            for (size_t i = 0; i < m_id.size(); i++)
            {
                if (m_id[i] == pid)
                {
                    m_id[i] = qid;
                }
            }
        }
    };
}