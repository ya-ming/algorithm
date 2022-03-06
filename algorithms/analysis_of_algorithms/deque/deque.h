#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

namespace deque
{
    template <class Item>
    class Deque
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
        // construct an empty deque
        Deque()
        {
        }

        ~Deque()
        {
            while (m_first)
            {
                Node *old_first = m_first;
                m_first = old_first->next;
                delete old_first;
            }
        }

        // is the deque empty?
        bool isEmpty()
        {
            return m_first == nullptr;
        }

        // return the number of items on the deque
        int size()
        {
            return m_size;
        }

        // add the item to the front
        void addFirst(Item item)
        {
            Node *old_first = m_first;
            m_first = new Node();
            m_first->item = item;
            m_first->next = old_first;
            m_first->pre = nullptr;
            if (old_first)
                old_first->pre = m_first;
            else
                // the 1st item add to the deque, last = first
                m_last = m_first;
            m_size++;
        }

        // add the item to the back
        void addLast(Item item)
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

        // remove and return the item from the front
        Item removeFirst()
        {
            if (m_first == nullptr)
            {
                throw std::invalid_argument( "NoSuchElementException" );
            }

            Item ret = m_first->item;
            Node *old_first = m_first;
            if (m_first->next)
                m_first->next->pre = nullptr;
            m_first = m_first->next;
            delete old_first;

            m_size--;
            // last item removed from the head
            if (m_size == 0)
                m_last = nullptr;

            return ret;
        }

        // remove and return the item from the back
        Item removeLast()
        {
            if (m_last == nullptr)
            {
                throw std::invalid_argument( "NoSuchElementException" );
            }

            Item ret = m_last->item;
            Node *old_last = m_last;
            if (m_last->pre)
                m_last->pre->next = nullptr;
            m_last = m_last->pre;
            delete old_last;

            m_size--;
            // last item removed from the tail
            if (m_size == 0)
                m_first = nullptr;
            return ret;
        }

        // return an iterator over items in order from front to back
        class iterator
        {
        private:
            Node *m_pos;

        public:
            iterator(Node *p) : m_pos(p)
            {
            }

            iterator &operator++(int)
            {
                if (m_pos == nullptr)
                {
                    throw std::invalid_argument( "NoSuchElementException" );
                }
                m_pos = m_pos->next;
                return *this;
            }

            iterator &operator--(int)
            {
                if (m_pos == nullptr)
                {
                    throw std::invalid_argument( "NoSuchElementException" );
                }
                m_pos = m_pos->pre;
                return *this;
            }

            bool operator!=(const iterator &other) const
            {
                return m_pos != other.m_pos;
            }

            bool operator==(const iterator &other) const
            {
                return m_pos == other.m_pos;
            }

            Item &operator*() const
            {
                return m_pos->item;
            }
        };

        iterator begin()
        {
            return iterator(m_first);
        }

        iterator end()
        {
            return iterator(nullptr);
        }
    };
}