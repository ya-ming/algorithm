#include <gtest/gtest.h>

#include "quick_union_uf_initial.h"

namespace union_find_initial
{

TEST(union_find_initial, quick_union_uf_initial)
{
    QuickUnionUF ob(10);

    ob.union_connections(4, 3);
    ob.union_connections(3, 8);
    ob.union_connections(6, 5);
    ob.union_connections(9, 4);
    
    ob.union_connections(2, 1);
    EXPECT_TRUE(ob.connected(8, 9));
    EXPECT_FALSE(ob.connected(5, 0));

    ob.union_connections(5, 0);
    ob.union_connections(7, 2);
    ob.union_connections(6, 1);

    EXPECT_TRUE(ob.connected(0, 2));
    EXPECT_FALSE(ob.connected(1, 9));

    ob.union_connections(7, 3);
    EXPECT_TRUE(ob.connected(1, 9));
}

}