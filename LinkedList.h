#pragma once

template <class T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T value) : data(value), next(NULL){};
    };
    Node *head;
    Node *tail;
    int Length;

public:
    LinkedList(T *items, int count);
    LinkedList();
    LinkedList(const LinkedList<T> &list);

    T GetFirst();
    T GetLast();
    T Get(int index);
    LinkedList<T> *GetSubList(int startIndex, int endIndex);
    int GetLength();

    void Append(T item);
    void Prepend(T item);
    void InsertAt(T item, int index);
    LinkedList<T> *Concat(LinkedList<T> *list);

    void print();
};