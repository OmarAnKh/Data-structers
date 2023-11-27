#include <iostream>
#include <string>
using namespace std;
template <typename nodeType>
class DNode
{
public:
    nodeType data;
    DNode<nodeType> *next;
    DNode<nodeType> *prev;
};
template <typename nodeType>
class Doublylist
{
private:
    DNode<nodeType> *head;
    DNode<nodeType> *tail;
    int n;
    void nodeSwap(DNode<nodeType> *firstNode, DNode<nodeType> *secNode); // Swap 2 nodes
    DNode<nodeType> *findNode(const nodeType element); // find a specific node

public:
    Doublylist();
    Doublylist(const Doublylist &obj);
    ~Doublylist();
    bool empty();                                                     // return if the list is empty
    int size();                                                       // return the size of the list
    void addFront(const nodeType &item);                              // add value to the front of the list
    void removeFront();                                               // remove the front value of the list
    nodeType getFront();                                              // return the front value of the list
    void addBack(const nodeType &item);                               // add value to the back of the list
    nodeType getback();                                               // return the back value of the list
    void removeBack();                                                // remove the back value of the list
    void displayList();                                               // display the list
    void displayListInReverse();                                      // display the list in reverse order
    bool find(const nodeType element);                                // find if a value is in the list
    void insertAfter(const nodeType &element, const nodeType &item);  // insert a value after a specific element
    void insertBefor(const nodeType &element, const nodeType &item);  // insert a value befor a specific element
    void removeAfter(const nodeType &element);                        // remove a value after a specific element
    void removeBefor(const nodeType &element);                        // remove a value befor a specific element
    bool isExist(const nodeType &element);                            // return if a value is in the list
    void remove(const nodeType &element);                             // remove a specific element of the list
    void removeAll();                                                 // remove all elements in the list
    bool isPalindrome();                                              // return if the String in the list is palindrome
    void sort();                                                      // sort the list
    void swap(const nodeType &element1, const nodeType &element2);    // swap 2 elements
    void append(const Doublylist &obj);                               // append one list to another one
    Doublylist<nodeType> &operator=(const Doublylist<nodeType> &obj); // assign a list to another one
    Doublylist<nodeType> divide();                                    // return the seconed half of the list
    Doublylist<nodeType> divide(const nodeType item);                 // return the rest of the list after a specific element
    double AVG();                                                     // return the  average of the list elements
};
