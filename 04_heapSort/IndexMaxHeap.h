#ifndef IndexMAXHEAP_H
#define IndexMAXHEAP_H

#include <cassert>
#include <string.h>
#include <stdio.h>

using namespace std;

template <typename T>
class IndexMaxHeap
{
  public:
    IndexMaxHeap(int capacity)
    : m_capacity(capacity), m_next(0) {
        m_data = new T[capacity];
        m_indexes = new int[capacity];
        m_reverse = new int[capacity];
        memset(m_reverse, 0, sizeof(int)*capacity);
    }

    ~IndexMaxHeap() {
        delete m_data;
        delete m_indexes;
        delete m_reverse;
    }

    void insert(int i, T node) {
        assert(m_next < m_capacity);
        assert(i < m_capacity);

        m_data[i] = node;
        m_indexes[m_next] = i;
        m_reverse[i] = m_next;

        shiftUp(m_next);
        m_next++;   //因为shiftUp是向上比较，所以m_next++，在前或在后都可以
    }

    T extractMaxItem() {
        assert(m_next > 0);

        int index = 0;
        T ret = m_data[m_indexes[index]];
        m_indexes[index] = m_indexes[m_next];
        m_reverse[m_indexes[index]] = index;
        m_reverse[m_indexes[m_next]] = 0;
        m_next--;
        shiftDown(index);   //shiftDown是向下比较，所以边界就需要正确，所以m_next--要在之前，
        return ret;
    }

    int extractMaxIndex() {
        assert(m_next > 0);

        int index = 0;
        int ret = m_indexes[index];
        m_indexes[index] = m_indexes[m_next];
        m_reverse[m_indexes[index]] = index;
        m_reverse[m_indexes[m_next]] = 0;
        m_next--;
        shiftDown(index);   //shiftDown是向下比较，所以边界就需要正确，所以m_next--要在之前，
        return ret;
    }

    bool contain(int i) {
        assert (i >= 0 && i< m_capacity);
        return m_reverse[i] == 0;
    }

    T getItem(int i) {
        assert(contain(i));
        return m_data[i];
    }

    /*
        修改一个已经存在的数组元素
    */
    void change(int i, T newItem) {
        assert(contain(i));

        m_data[i] = newItem;

        //此时我们要找到i，这个元素在m_indexes中的位置
        //之后在shiftUp shifiDown，看当前元素能否上下移动
        /*
        for(int j = 0; j < m_next; j++){
            if(indexes[j] == i){
                shiftUp(j);
                shiftDown(j);
                return ;
            }
        }
        */

        int j = m_reverse[i];
        shiftUp(j);
        shiftDown(j);
    }

    bool empty() {
        return m_next == 0;
    }

  private:
  /*
    跟父节点比较，如果大于父节点，交换，然后继续跟父节点比较
    n 的父节点 。(n-1)/2
  */
    void shiftUp(int index) {
        while(index > 0 && m_data[m_indexes[index] > m_data[m_indexes[(index-1)/2]]) {
            swap(m_indexes[index], m_indexes[(index-1)/2]);
            m_reverse[m_indexes[index]] = index;
            m_reverse[m_indexes[(index-1)/2]] = (index-1)/2;
            index = (index-1)/2;
        }
    }

    /*
        跟子节点比较，如果小于 子节点中的最大值，就交换，然后继续跟子节点比较
        n   left_node = 2*n+1
            right_node = 2*n+2
    */
    void shiftDown(int index) {
        while ((index*2 +1) < m_next) { //确保有子节点
            int lhs = index * 2 + 1;
            if((lhs+1) < m_next && m_data[m_indexes[lhs]] < m_data[m_indexes[lhs+1]]) {
                lhs = lhs+1;
            }
            if(m_data[m_indexes[index]] >= m_data[m_indexes[lhs]]) {
                break;
            }
            swap(m_indexes[index], m_indexes[lhs]);
            m_reverse[m_indexes[index]] = index;
            m_reverse[m_indexes[lhs]] = lhs;
            index = lhs;
        }
    }

  private:
    int m_capacity;
    int m_next; //指向下一个可以存储的数组下标

    T *m_data;
    int *m_indexes;
    int *m_reverse;
};

#endif //IndexMAXHEAP_H