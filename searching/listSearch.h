#ifndef _LIST_SEARCH_
#define _LIST_SEARCH_

#include <iostream>

using namespace std;

namespace ListSearch
{
    // A Linked List node 
    struct Node 
    { 
        int data; 
        Node* next; 
    };

    //User function template for C++
    class Solution
    {
    public:
        // Time Complexity : O(m*n) where m is the number of nodes in second list and n in first
        // Can be optimized by using extra space i.e. stores the list into two strings and apply KMP algorithm
        bool listSearch(Node *first, Node *second)
        {
            Node *p1 = first, *p2 = second;

            if (!first || !second)
                return false;
            
            while (p1 && p2)
            {
                if (p1->data == p2->data)
                {
                    p1 = p1->next;
                    p2 = p2->next;

                    if (!p1)
                        return true;
                }
                else
                {
                    p1 = first;
                    second = second->next;
                    p2 = second;
                }
            }

            return false;
        }
    };
} // namespace ListSearch

#endif