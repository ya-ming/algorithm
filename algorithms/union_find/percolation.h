#pragma once

#include <iostream>
#include <random>
#include "quick_union_uf.h"

using namespace std;

namespace union_find
{
    class Percolation
    {
    public:
        // creates n-by-n grid, with all sites initially blocked
        Percolation(int n)
            : m_n(n), m_numberOfSites(n * n), m_sites(n * n + 2), m_numberOfOpenSites(0)
        {
            m_openSites.assign(m_numberOfSites + 2, false);
            m_openSites[0] = true;
            m_openSites[m_numberOfSites + 1] = true;
        }

        void init()
        {
            // connect virtual site 0 to sites 1 to n
            for (int i = 1; i <= m_n; i++)
            {
                m_sites.union_connections(0, i);
            }
            // connect virtual site n*n + 1 to sites n * (n - 1) to n * n - 1
            for (int i = 1; i <= m_n; i++)
            {
                m_sites.union_connections(m_numberOfSites + 1, m_numberOfSites - m_n + i);
            }
        }

        void print()
        {
            m_sites.print(m_n);
        }

        // opens the site (row, col) if it is not open already
        void open(int row, int col)
        {
            if (row < 0 || row > m_n || col < 0 || col > m_n)
            {
                cout << "Invalid (row, col) = (" << row << ", " << col << ")" << endl;
            }

            // return if already opened
            if (m_openSites[(row - 1) * m_n + col])
                return;

            m_openSites[(row - 1) * m_n + col] = true;
            m_numberOfOpenSites++;

            bool checkAbove, checkBelow, checkLeft, checkRight;
            checkAbove = checkBelow = checkLeft = checkRight = true;
            if (row == 1)
            {
                checkAbove = false;
                // connect to the virtual top site
                m_sites.union_connections(0, col);
            }
            else if (row == m_n)
            {
                checkBelow = false;
                m_sites.union_connections(m_numberOfSites - m_n + col, m_numberOfSites + 1);
            }

            if (col == 1)
            {
                checkLeft = false;
            }
            if (col == m_n)
            {
                checkRight = false;
            }

            // cout << "To check (" << row << "," << col << "): " << checkAbove << checkBelow << checkLeft << checkRight << endl;

            if (checkAbove)
            {
                if (m_openSites[(row - 2) * m_n + col])
                {
                    m_sites.union_connections((row - 1) * m_n + col, (row - 2) * m_n + (col));
                }
            }
            if (checkBelow)
            {
                if (m_openSites[(row) * m_n + col])
                {
                    m_sites.union_connections((row - 1) * m_n + col, row * m_n + col);
                }
            }
            if (checkLeft)
            {
                if (m_openSites[(row - 1) * m_n + col - 1])
                {
                    m_sites.union_connections((row - 1) * m_n + col, (row - 1) * m_n + col - 1);
                }
            }
            if (checkRight)
            {
                if (m_openSites[(row - 1) * m_n + col + 1])
                {
                    m_sites.union_connections((row - 1) * m_n + col, (row - 1)  * m_n + col + 1);
                }
            }
        }

        // is the site (row, col) open?
        bool isOpen(int row, int col)
        {
            return m_openSites[(row - 1) * m_n + col];
        }

        // is the site (row, col) full?
        bool isFull(int row, int col)
        {

        }

        // returns the number of open sites
        int numberOfOpenSites()
        {
            return m_numberOfSites;
        }

        // does the system percolate?
        bool percolates()
        {
            return m_sites.connected(0, m_numberOfSites + 1);
        }

    private:
        QuickUnionUF m_sites;
        int m_n;             // elements per site
        int m_numberOfSites; // total number of sites not including virtual sites

        int m_numberOfOpenSites;
        std::vector<bool> m_openSites;
    };
}