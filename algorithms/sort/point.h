#pragma once

#include <climits>
#include <stdexcept>
#include <vector>

namespace sort
{

    class Point
    {
    public:
        int m_x, m_y;
        double m_slopeWithP = 0.0;

    public:
        Point(int x, int y)
            : m_x(x), m_y(y)
        {
            if (x < 0 || x > 32767 || y < 0 || y > 32767)
            {
                throw std::invalid_argument("Arguments x and y need to be between 0 and 32,767");
            }
        }

        // compare two points by y-coordinates, breaking ties by x-coordinates
        struct lessThan
        {
            bool operator()(Point const &l, Point const &r)
            {
                if (l.m_x < r.m_x)
                {
                    return true;
                }
                else if (l.m_x > r.m_x)
                {
                    return false;
                }
                else
                {
                    if (l.m_y < r.m_y)
                    {
                        return true;
                    }
                    else if (l.m_y > r.m_y)
                    {
                        return false;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        };

        // the slope between this point and that point
        // The slopeTo() method should return the slope between the invoking point (x0, y0)
        // and the argument point (x1, y1), which is given by the formula (y1 − y0) / (x1 − x0).
        // Treat the slope of a horizontal line segment as positive zero;
        // treat the slope of a vertical line segment as positive infinity;
        // treat the slope of a degenerate line segment (between a point and itself) as negative infinity.

        double slopeTo(Point &that)
        {
            if (m_x == that.m_x && m_y == that.m_y)
            {
                return INT_MIN;
            }
            else if (m_x == that.m_x)
            {
                return INT_MAX;
            }
            else if (m_y == that.m_y)
            {
                return 0;
            }

            return double(that.m_y - m_y) / double(that.m_x - m_x);
        }

        void slopeWithP(Point &that)
        {
            if (m_x == that.m_x && m_y == that.m_y)
            {
                m_slopeWithP = INT_MIN;
            }
            else if (m_x == that.m_x)
            {
                m_slopeWithP = INT_MAX;
            }
            else if (m_y == that.m_y)
            {
                m_slopeWithP = 0;
            }

            m_slopeWithP = double(m_y - that.m_y) / double(m_x - that.m_x);
        }

        bool operator<(const Point &p) const
        {
            return m_slopeWithP < p.m_slopeWithP;
        }

        // compare two points by slopes they make with this point
        int slopeOrder(Point &p1, Point &p2)
        {
            double slopeP1 = slopeTo(p1);
            double slopeP2 = slopeTo(p2);

            if (slopeP1 < slopeP2)
                return -1;
            else if (slopeP1 > slopeP2)
                return 1;
            else
                return 0;
        }

        void print()
        {
            cout << "(" << m_x << "," << m_y << ")";
        }
    };

    class LineSegment
    {
    public:
        Point m_p, m_q;

    public:
        // constructs the line segment between points p and q
        LineSegment(Point p, Point q)
            : m_p(p), m_q(q)
        {
        }

        void print()
        {
            m_p.print();
            cout << " -> ";
            m_q.print();
            cout << endl;
        }
    };

    class CollinearPoints
    {
    private:
        vector<Point> m_points;
        vector<LineSegment> m_lineSegements;

    public:
        // finds all line segments containing 4 points
        CollinearPoints(vector<Point> &points)
        {
            m_points = points;
        }
        // the number of line segments
        int numberOfSegments()
        {
            return m_lineSegements.size();
        }
        // the line segments
        vector<LineSegment> &bruteForceSegments()
        {
            // sort the points based on x and y coordination
            std::sort(m_points.begin(), m_points.end(), Point::lessThan());

            int N = m_points.size();
            for (int p = 0; p < N - 3; p++)
            {
                for (int q = p + 1; q < N - 2; q++)
                {
                    // To check whether the 4 points p, q, r, and s are collinear,
                    // check whether the three slopes between p and q, between p and r, and between p and s are all equal.
                    double p_slope_q = m_points[p].slopeTo(m_points[q]);
                    for (int r = q + 1; r < N - 1; r++)
                    {
                        double p_slope_r = m_points[p].slopeTo(m_points[r]);
                        for (int s = r + 1; s < N; s++)
                        {
                            double p_slope_s = m_points[p].slopeTo(m_points[s]);
                            if (p_slope_q == p_slope_r && p_slope_q == p_slope_s)
                            {
                                m_lineSegements.push_back(LineSegment(m_points[p], m_points[s]));
                            }
                        }
                    }
                }
            }
            return m_lineSegements;
        }

        vector<LineSegment> &sortingBasedSegments()
        {
            int N = m_points.size();
            auto begin = m_points.begin();

            // sort the points based on x and y coordination
            std::sort(begin, m_points.end(), Point::lessThan());

            // make a copy of the points, will be copied back to m_points after each round of sort based on slope
            vector<Point> copy(m_points);

            for (int i = 0; i < N - 3; i++)
            {
                m_points = copy;
                // Think of p as the origin
                // calculate slope with respect to "P"
                for (int j = i + 1; j < N; j++)
                {
                    // For each other point q, determine the slope it makes with p
                    m_points[j].slopeWithP(m_points[i]);
                }
                begin++;
                // Sort the points according to the slopes they makes with p
                std::stable_sort(begin, m_points.end());

                // Check if any 3 (or more) adjacent points in the sorted order have equal slopes with respect to p. If so, these points, together with p, are collinear.
                for (int j = i + 1; j < N - 2; j++)
                {
                    if (m_points[j].m_slopeWithP == m_points[j + 1].m_slopeWithP && m_points[j].m_slopeWithP == m_points[j + 2].m_slopeWithP)
                    {
                        m_lineSegements.push_back(LineSegment(m_points[i], m_points[j + 2]));
                    }
                }
            }

            return m_lineSegements;
        }
    };
}