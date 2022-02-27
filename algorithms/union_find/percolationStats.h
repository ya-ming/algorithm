#pragma once

#include <iostream>
#include <random>
#include <iomanip>
#include "percolation.h"

using namespace std;

namespace union_find
{
    class PercolationStats
    {
    public:
        // perform independent trials on an n-by-n grid
        PercolationStats(int n, int trials)
            : m_n(n), m_trails(trials)
        {
            m_thresholds.reserve(trials);
        }

        void compute()
        {
            for (int i = 0; i < m_trails; i++)
            {
                double threshold = computeThreshold();
                m_thresholds.push_back(threshold);
            }

            m_mean = mean();
            m_std_dev = stddev();
        }

        double computeThreshold()
        {
            Percolation percolation(m_n);
            random_device rd;  // Will be used to obtain a seed for the random number engine
            mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
            uniform_int_distribution<> distrib(1, m_n);

            int threshold = 0;
            while (!percolation.percolates())
            {
                int row = distrib(gen);
                int col = distrib(gen);

                while (percolation.isOpen(row, col))
                {
                    row = distrib(gen);
                    col = distrib(gen);
                }

                // cout << "Interation " << threshold << ", row = " << row << ", col = " << col << endl;

                percolation.open(row, col);

                threshold++;
            }

            return (double)threshold / (m_n * m_n);
        }

        void print()
        {
            // cout << "Threshods = " << endl;
            // for (int i = 1; i < m_trails + 1; i++)
            // {
            //     cout << m_thresholds[i - 1] << " ";
            //     if (i % 20 == 0)
            //         cout << endl;
            // }
            // cout << endl;
            cout << std::setprecision (15);
            cout << "mean                    = " << m_mean << endl;
            cout << "stddev                  = " << m_std_dev << endl;
            cout << "95% confidence interval = " << "[" << confidenceLo() << ", " << confidenceHi() << "]" << endl;
        }

        // sample mean of percolation threshold
        double mean()
        {
            double sum = 0;
            for (int i = 0; i < m_trails; i++)
            {
                sum += m_thresholds[i];
            }

            return sum / m_trails;
        }

        // sample standard deviation of percolation threshold
        double stddev()
        {
            double sum = 0;
            for (int i = 0; i < m_trails; i++)
            {
                sum += pow(m_thresholds[i] - m_mean, 2);
            }

            return sqrt(sum / (m_trails - 1));
        }

        // low endpoint of 95% confidence interval
        double confidenceLo()
        {
            return m_mean - (1.96*m_std_dev)/sqrt(m_trails);
        }

        // high endpoint of 95% confidence interval
        double confidenceHi()
        {
            return m_mean + (1.96*m_std_dev)/sqrt(m_trails);
        }

    private:
        int m_n;      // elements per site
        int m_trails; // number of trails

        double m_mean;
        double m_std_dev;

        std::vector<double> m_thresholds;
    };
}