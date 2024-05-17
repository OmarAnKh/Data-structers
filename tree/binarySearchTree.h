#include <iostream>
using namespace std;

template <typename nodeType>
class TNode
{
public:
    nodeType data;
    TNode<nodeType> *left, *right, *parent;
    TNode()
    {

        left = NULL;
        right = NULL;
        parent = NULL;
    }
};
template <typename nodeType>
class binarySearchTree
{
private:
    TNode<nodeType> *root;
    int size;
    void display(TNode<nodeType> *node, const string &printingMethod)
    {
        if (node == NULL)
            return;
        if (printingMethod == "NRL")
        {
            cout << node->data << "\t";
            display(node->right, "NRL");
            display(node->left, "NRL");
        }
        else if (printingMethod == "LNR")
        {
            display(node->left, "LNR");
            cout << node->data << "\t";
            display(node->right, "LNR");
        }
        else if (printingMethod == "RNL")
        {
            display(node->right, "RNL");
            cout << node->data << "\t";
            display(node->left, "RNL");
        }
        else if (printingMethod == "LRN")
        {
            display(node->left, "LRN");
            display(node->right, "LRN");
            cout << node->data << "\t";
        }
        else if (printingMethod == "RLN")
        {
            display(node->right, "RLN");
            display(node->left, "RLN");
            cout << node->data << "\t";
        }
        else if (printingMethod == "NLR")
        {
            cout << node->data << "\t";
            display(node->left, "NLR");
            display(node->right, "NLR");
        }
    }

public:
    binarySearchTree()
    {
        root = NULL;
        size = 0;
    }
    bool empty()
    {
        return root == NULL;
    }
    bool IsLeaf(const nodeType &item)
    {
        TNode<nodeType> *temp = find(item);
        return temp->right == temp->left;
    }
    TNode<nodeType> *find(const nodeType &item)
    {
        TNode<nodeType> *temp = root;
        while (temp)
        {
            if (item == temp->data)
            {
                return temp;
            }
            else if (item > temp->data)
            {
                temp = temp->right;
            }
            else if (item < temp->data)
            {
                temp = temp->left;
            }
        }
        return NULL;
    }
    void insert(const nodeType &item)
    {
        TNode<nodeType> *newData = new TNode<nodeType>;
        newData->left = NULL;
        newData->right = NULL;
        newData->data = item;
        newData->parent = root;
        if (root == NULL)
        {
            root = newData;
            size++;
            return;
        }
        TNode<nodeType> *temp = root;

        while (temp)
        {
            if (item == temp->data)
            {
                return;
            }
            else if (item > temp->data)
            {
                newData->parent = temp;
                temp = temp->right;
            }
            else if (item < temp->data)
            {
                newData->parent = temp;
                temp = temp->left;
            }
        }

        if (item > newData->parent->data)
        {
            newData->parent->right = newData;
        }
        else if (item < newData->parent->data)
        {
            newData->parent->left = newData;
        }

        size++;
    }
    void print(const nodeType &item, const string &printingMethod)
    {
        display(find(item), printingMethod);
        cout << endl;
    }
    
};
