#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <cassert>
#include <string.h>
#include <stdio.h>

using namespace std;

template <typename T>
class MaxHeap
{
  public:
    MaxHeap(int capacity)
    {
        m_capacity = capacity;
        m_data = new T[capacity + 1];
        m_next = 1;
    }
    MaxHeap(T arr[], int n)
    {
        m_capacity = n;
        m_data = new T[n + 1];
        for (int i = 0; i < n; i++)
            m_data[i + 1] = arr[i];
        m_next = n + 1;
        for (int i = (m_next - 1) / 2; i >= 1; i--)
            shiftDown(i);
    }
    ~MaxHeap() { delete m_data; }

    void insert(T node)
    {
        assert(m_next <= m_capacity);

        int index = m_next;
        m_data[index] = node;

        shiftUp(index);
        m_next++;
    }

    T pop()
    {
        assert(m_next > 1);
        int index = 1;
        T ret = m_data[index];
        m_data[index] = m_data[--m_next];
        shiftDown(index);
        return ret;
    }

    bool empty()
    {
        return m_next == 1;
    }

  private:
    void shiftUp(int index)
    {
        while (index > 1 && m_data[index] > m_data[index / 2])
        {
            swap(m_data[index], m_data[index / 2]);
            index = index / 2;
        }
    }

    void shiftDown(int index)
    {
        while (index * 2 < m_next)
        {
            int maxIndex = index * 2;
            int rightNode = index * 2 + 1;
            if (rightNode < m_next && m_data[maxIndex] < m_data[rightNode])
            {
                maxIndex = rightNode;
            }
            if (m_data[index] >= m_data[maxIndex])
                break;
            swap(m_data[index], m_data[maxIndex]);

            index = maxIndex;
        }
    }

  private:
    int m_capacity;
    int m_next; //只想下一个可以存储的数组下标

    T *m_data;
};

#endif //MAXHEAP_H