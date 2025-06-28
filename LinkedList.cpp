#include <cstdlib>
#include <stdexcept>
#include <exception>
#include <iostream>

#include "LinkedList.h"

using namespace std;

template<class T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right; 
    Node(T value) : data(value), left(NULL), right(NULL){};
};

template class LinkedList<int>;
template class LinkedList<float>;
template class LinkedList<Node<int>*>;
template class LinkedList<Node<float>*>;

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = head;
    Length = 0;
}

template <class T>
void LinkedList<T>::Append(T item)
{
    Node *node = new Node(item);
    Node *ptr;
    if (head == NULL)
    {
        head = node;
        tail = head;
    }
    else
    {
        tail->next = node;
        tail = tail->next;
    }
    Length++;
}

template <class T>
void LinkedList<T>::Prepend(T item)
{
    Node *node = new Node(item);
    node->next = head;
    head = node;
    Length++;
}

template <class T>
void LinkedList<T>::InsertAt(T item, int index)
{
    if (index < 0 || index > Length - 1)
        throw logic_error("Index out of range");
    Node *node = new Node(item);
    Node *ptr = head;
    if (index == 0)
        this->Prepend(item);
    else
    {
        while (index > 1)
        {
            ptr = ptr->next;
            index--;
        }
        node->next = ptr->next;
        ptr->next = node;
        Length++;
    }
}

template <class T>
LinkedList<T>::LinkedList(T *items, int count)
{
    Length = 0;
    head = NULL;
    for (int i = 0; i < count; i++)
        this->Append(items[i]);
}

template <class T>
T LinkedList<T>::GetFirst()
{
    return head->data;
}

template <class T>
T LinkedList<T>::GetLast()
{
    return tail->data;
}

template <class T>
T LinkedList<T>::Get(int index)
{
    if (index < 0 || index > Length)
        throw logic_error("Index out of range");
    Node *node = head;
    while (index--)
        node = node->next;
    return node->data;
}

template <class T>
int LinkedList<T>::GetLength()
{
    return Length;
}

template <class T>
LinkedList<T> *LinkedList<T>::GetSubList(int startIndex, int endIndex)
{
    int newLength = endIndex - startIndex + 1;
    if (startIndex > endIndex || startIndex < 0 || endIndex >= Length)
        throw logic_error("Index out of range");
    LinkedList<T> *linkedList = new LinkedList();
    Node *ptr = head;
    while (startIndex--)
        ptr = ptr->next;
    while (newLength--)
    {
        linkedList->Append(ptr->data);
        ptr = ptr->next;
    }
    return linkedList;
}

template <class T>
LinkedList<T> *LinkedList<T>::Concat(LinkedList<T> *list)
{
    LinkedList<T> *linkedList = this;
    linkedList->tail->next = list->head;
    return linkedList;
}

template <class T>
void LinkedList<T>::print()
{
    Node *node = head;
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
