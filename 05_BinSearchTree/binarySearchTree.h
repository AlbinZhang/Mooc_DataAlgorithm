#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

using namespace std;

template <typename Key, typename Value>
class BST
{
  private:
    struct Node
    {
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node(Key key, Value value)
            : key(key), value(value), left(NULL), right(NULL)
        {
        }
    };

  public:

    BST()
        : m_root(NULL), m_count(0)
    {
    }

    ~BST()
    {
        //TODO: ~BST()
    }

    int size() { return m_count; }
    bool isEmpty() { return m_count == 0; }

    void insert(Key key, Value value)
    {
        insert(m_root, key, value);
    }

  private:
    void insertWhile(Node *node, Key key, Value value)
    {
        if (node == NULL)
            node = new Node(key, value);
    }

    Node *insert(Node *node, Key key, Value value)
    {
        if (node == NULL)
        {
            m_count++;
            return new Node(key, value);
        }

        if (node->key == key)
            node->value = value;
        else if (node->key > key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);

        return node;
    }

  private:
    Node *m_root;
    int m_count;
};

#endif //BINARYSEARCHTREE_H