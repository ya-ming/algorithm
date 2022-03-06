#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>

using namespace std;

namespace deque
{
    template <class Item>
    class RandomizedQueue
    {
    private:
        struct Node
        {
            Item item;
            Node *next;
            Node *pre;
        };

        Node *m_first = nullptr;
        Node *m_last = nullptr;
        int m_size = 0;

    public:
        // construct an empty randomized queue
        RandomizedQueue()
        {
        }

        ~RandomizedQueue()
        {
            while (m_first)
            {
                Node *old_first = m_first;
                m_first = old_first->next;
                delete old_first;
            }
        }

        // is the randomized queue empty?
        bool isEmpty()
        {
            return m_first == nullptr;
        }

        // return the number of items on the randomized queue
        int size()
        {
            return m_size;
        }

        // add the item to the back
        void enqueue(Item item)
        {
            Node *old_last = m_last;
            m_last = new Node();
            m_last->item = item;
            m_last->next = nullptr;
            m_last->pre = old_last;
            if (old_last)
                old_last->next = m_last;
            else
                // the 1st item add to the deque, first = last
                m_first = m_last;
            m_size++;
        }

        // remove and return a random item
        Item dequeue()
        {
            if (m_first == nullptr)
            {
                throw std::invalid_argument( "NoSuchElementException" );
            }

            random_device rd;  // Will be used to obtain a seed for the random number engine
            mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
            uniform_int_distribution<> distrib(1, m_size);
            unsigned int targetIndex = distrib(gen);

            unsigned int index = 1;
            Node *p = m_first;
            while (index < targetIndex)
            {
                p = p->next;
                index++;
            }

            Item ret = p->item;
            Node *node_to_remove = p;
            if (p->pre && p->next)
            {
                p->pre->next = p->next;
                p->next->pre = p->pre;
            }
            else if (p->pre)
            {
                p->pre->next = nullptr;
                m_last = p->pre;
            }
            else if (p->next)
            {
                p->next->pre = nullptr;
                m_first = p->next;
            }
            
            delete node_to_remove;

            m_size--;
            // last item removed from the head
            if (m_size == 0)
            {
                m_first = m_last = nullptr;
            }

            return ret;
        }

        // return a random item (but do not remove it)
        Item sample()
        {
            if (m_last == nullptr)
            {
                throw std::invalid_argument( "NoSuchElementException" );
            }

            random_device rd;  // Will be used to obtain a seed for the random number engine
            mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
            uniform_int_distribution<> distrib(1, m_size);
            unsigned int targetIndex = distrib(gen);

            unsigned int index = 1;
            Node *p = m_first;
            while (index < targetIndex)
            {
                p = p->next;
                index++;
            }

            return p->item;
        }
    };
}