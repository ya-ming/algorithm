#include <gtest/gtest.h>
#include <fstream>
#include "point.h"
#include "../utility/stopWatch.h"
#include "../utility/utility.h"

namespace sort
{

TEST(sort, point_test)
{
    Point p0(2, 1);

    Point p1(1, 7);
    Point p2(3, 5);
    Point p3(5, 3);
    Point p4(7, 1);

    cout << p0.slopeTo(p1) << endl;
    cout << p0.slopeTo(p2) << endl;
    cout << p0.slopeTo(p3) << endl;
    cout << p0.slopeTo(p4) << endl;

}

TEST(sort, brute_force)
{
    Point pA(2, 1);
    Point pB(1, 7);
    Point pC(3, 5);
    Point pD(5, 3);
    Point pE(7, 1);
    Point pF(4, 6);
    Point pG(7, 5);
    Point pH(8, 4);
    Point pI(10, 4);

    vector<Point> points;
    points.push_back(pA);
    points.push_back(pB);
    points.push_back(pC);
    points.push_back(pD);
    points.push_back(pE);
    points.push_back(pF);
    points.push_back(pG);
    points.push_back(pH);
    points.push_back(pI);

    CollinearPoints collinearPoints(points);
    vector<LineSegment> lineSegements = collinearPoints.bruteForceSegments();

    EXPECT_EQ(2, collinearPoints.numberOfSegments());

    lineSegements[0].print();
    EXPECT_EQ(1, lineSegements[0].m_p.m_x);
    EXPECT_EQ(7, lineSegements[0].m_p.m_y);
    EXPECT_EQ(7, lineSegements[0].m_q.m_x);
    EXPECT_EQ(1, lineSegements[0].m_q.m_y);

    lineSegements[1].print();
    EXPECT_EQ(1, lineSegements[1].m_p.m_x);
    EXPECT_EQ(7, lineSegements[1].m_p.m_y);
    EXPECT_EQ(10, lineSegements[1].m_q.m_x);
    EXPECT_EQ(4, lineSegements[1].m_q.m_y);
}

TEST(sort, brute_force_input6)
{
    Point pA(19000, 10000);
    Point pB(18000, 10000);
    // Point pC(32000, 10000); // For simplicity, we will not supply any input to BruteCollinearPoints that has 5 or more collinear points.
    Point pD(21000, 10000);
    Point pE(1234, 5678);
    Point pF(14000, 10000);

    vector<Point> points;
    points.push_back(pA);
    points.push_back(pB);
    points.push_back(pD);
    points.push_back(pE);
    points.push_back(pF);

    CollinearPoints collinearPoints(points);
    vector<LineSegment> lineSegements = collinearPoints.bruteForceSegments();

    EXPECT_EQ(1, collinearPoints.numberOfSegments());

    lineSegements[0].print();
    EXPECT_EQ(14000, lineSegements[0].m_p.m_x);
    EXPECT_EQ(10000, lineSegements[0].m_p.m_y);
    EXPECT_EQ(21000, lineSegements[0].m_q.m_x);
    EXPECT_EQ(10000, lineSegements[0].m_q.m_y);
}

TEST(sort, sorting_based)
{
    Point pA(2, 1);
    Point pB(1, 7);
    Point pC(3, 5);
    Point pD(5, 3);
    Point pE(7, 1);
    Point pF(4, 6);
    Point pG(7, 5);
    Point pH(8, 4);
    Point pI(10, 4);

    Point pJ(5, 5);
    Point pK(9, 5);

    vector<Point> points;
    points.push_back(pA);
    points.push_back(pB);
    points.push_back(pC);
    points.push_back(pD);
    points.push_back(pE);
    points.push_back(pF);
    points.push_back(pG);
    points.push_back(pH);
    points.push_back(pI);

    points.push_back(pJ);
    points.push_back(pK);

    CollinearPoints collinearPoints(points);
    vector<LineSegment> lineSegements = collinearPoints.sortingBasedSegments();

    EXPECT_EQ(3, collinearPoints.numberOfSegments());

    lineSegements[0].print();
    EXPECT_EQ(1, lineSegements[0].m_p.m_x);
    EXPECT_EQ(7, lineSegements[0].m_p.m_y);
    EXPECT_EQ(7, lineSegements[0].m_q.m_x);
    EXPECT_EQ(1, lineSegements[0].m_q.m_y);

    lineSegements[1].print();
    EXPECT_EQ(1, lineSegements[1].m_p.m_x);
    EXPECT_EQ(7, lineSegements[1].m_p.m_y);
    EXPECT_EQ(10, lineSegements[1].m_q.m_x);
    EXPECT_EQ(4, lineSegements[1].m_q.m_y);

    lineSegements[2].print();
    EXPECT_EQ(3, lineSegements[2].m_p.m_x);
    EXPECT_EQ(5, lineSegements[2].m_p.m_y);
    EXPECT_EQ(9, lineSegements[2].m_q.m_x);
    EXPECT_EQ(5, lineSegements[2].m_q.m_y);
}

TEST(sort, sorting_based_input8)
{
    Point pA(10000, 0);
    Point pB(0, 10000);
    Point pC(3000, 7000);
    Point pD(7000, 3000);
    Point pE(20000, 21000);
    Point pF(3000, 4000);
    Point pG(14000, 15000);
    Point pH(6000, 7000);

    vector<Point> points;
    points.push_back(pA);
    points.push_back(pB);
    points.push_back(pC);
    points.push_back(pD);
    points.push_back(pE);
    points.push_back(pF);
    points.push_back(pG);
    points.push_back(pH);

    CollinearPoints collinearPoints(points);
    vector<LineSegment> lineSegements = collinearPoints.sortingBasedSegments();

    EXPECT_EQ(2, collinearPoints.numberOfSegments());

    lineSegements[0].print();
    EXPECT_EQ(0, lineSegements[0].m_p.m_x);
    EXPECT_EQ(10000, lineSegements[0].m_p.m_y);
    EXPECT_EQ(10000, lineSegements[0].m_q.m_x);
    EXPECT_EQ(0, lineSegements[0].m_q.m_y);    

    lineSegements[1].print();
    EXPECT_EQ(3000, lineSegements[1].m_p.m_x);
    EXPECT_EQ(4000, lineSegements[1].m_p.m_y);
    EXPECT_EQ(20000, lineSegements[1].m_q.m_x);
    EXPECT_EQ(21000, lineSegements[1].m_q.m_y);
}

}