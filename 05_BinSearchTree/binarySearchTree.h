#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename Key, typename Value>
class BTS
{
public:
    BST()
    :root(NULL), count(0){}

    ~BST(){
        //TODO: ~BST()
    }

    int size() {return count;}
    bool isEmpty( return count == 0;)

    void insert(Key key, Value value)
    {
        insert(root, key, value);
    }

private:
    void insertWhile(Node* root, Key key, Value value)
    {
        if (root == null)
            root = new Node(key, value);
    }

    Node *insert(Node *root, Key key, Value value)
    {
        if (root == NULL) {
            count++;
            return new Node(key, value);
        }
            
        if(root->key == key)
            root->value = value;
        else if (root->key > key)
            root->left = insert(root->left, key, value);
        else
            root->right = insert(root->right, key, value);

        return node;
    }

private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;
        Node(Key key, Value value)
        :key(key),value(value),left(NULL),right(NULL)
        {}
    }

    Node *root;
    int count;

};


#endif //BINARYSEARCHTREE_H