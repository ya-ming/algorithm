#include <gtest/gtest.h>

#include "listSearch.h"

namespace ListSearch
{

    // Function to add new node to linked lists
    Node *newNode(int key)
    {
        Node *temp = new Node;
        temp->data = key;
        temp->next = NULL;
        return temp;
    }

    TEST(listSearch, basic)
    {
        Solution ob;

        Node *a = newNode(1);
        a->next = newNode(2);
        a->next->next = newNode(3);
        a->next->next->next = newNode(4);

        Node *b = newNode(1);
        b->next = newNode(2);
        b->next->next = newNode(1);
        b->next->next->next = newNode(2);
        b->next->next->next->next = newNode(3);
        b->next->next->next->next->next = newNode(4);
        auto ans = ob.listSearch(a, b);
        EXPECT_EQ(true, ans);
    }

    TEST(listSearch, basic1)
    {
        Solution ob;

        Node *a = newNode(1);
        a->next = newNode(2);
        a->next->next = newNode(3);
        a->next->next->next = newNode(4);

        Node *b = newNode(1);
        b->next = newNode(2);
        b->next->next = newNode(1);
        b->next->next->next = newNode(2);
        b->next->next->next->next = newNode(3);
        auto ans = ob.listSearch(a, b);
        EXPECT_EQ(false, ans);
    }

    TEST(listSearch, boundaryTest)
    {
        Solution ob;

        Node *a = newNode(1);
        a->next = newNode(2);
        a->next->next = newNode(3);
        a->next->next->next = newNode(4);

        auto ans = ob.listSearch(a, 0);
        EXPECT_EQ(false, ans);

        ans = ob.listSearch(0, a);
        EXPECT_EQ(false, ans);

    }

} // namespace ListSearch