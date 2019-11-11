#include <bits/stdc++.h>
using namespace std;
 
template <typename T>
class Node
{
public:
    T data;
    bool leftside;
    Node *left, *right, *parent;
    Node(T x)
    {
        data = x;
        left = NULL;
        right = NULL;
        parent = this;
        leftside = true;
    }
    ~Node()
    {

    }
};
template <typename T>
void insertnoderight(Node<T> *parent, Node<T> *node)
{
    node->right = parent->right;
    parent->right = node;
    node->parent = parent;
    node->leftside = false;
    return;
}

template <typename T>
void insertnodeleft(Node<T> *parent, Node<T> *node)
{
    node->left = parent->left;
    parent->left = node;
    node->leftside = true;
    node->parent = parent;
    return;
}

template <typename T>
void inorder(Node<T> *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
    return;
}

template <typename T>
Node<T> *depp(Node<T> *temp)
{
    if (temp == NULL)
        return NULL;
    if ((temp->left == NULL) && (temp->right == NULL))
    {
        // cout<<temp->data;
        return temp;
    }
    Node<T> *t1 = depp(temp->left);
    Node<T> *t2 = depp(temp->right);
    if (t1 != NULL)
        return t1;
    if (t2 != NULL)
        return t2;
    return NULL;
}

template <typename T>
void deletenode(Node<T> *temp)
{

    Node<T> *t = depp(temp);
    if (t->parent == t)
    {
        free(t);
        return;
    }
    temp->data = t->data;
    if ((t->leftside) == true)
        (t->parent)->left = NULL;
    else
        (t->parent)->right = NULL;
    free(t);
}

int main()
{
    Node<int> *n=new Node<int>(5);
    Node<int> *n1=new Node<int>(6);
    // n.parent=&n;
    insertnoderight(n, n1);
    // cout<<(n1.right==NULL);
    // cout<<depp(&n)->data;
    // delete n1;
    deletenode(n1);
    inorder(n);
    return 0;
}