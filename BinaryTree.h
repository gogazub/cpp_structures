#pragma once

#include <string>
#include <vector>

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

template<class T>
class BinaryTree
{
private:
    Node<T>* root;
    BinaryTree(Node<T>* leaf):root(leaf){};

	void insert(T data, Node<T> *leaf);
	Node<T> *search(T data, Node<T> *leaf);
    Node<T>* deleteNode(T data, Node<T> *leaf);

	void inorderPrint(Node<T> *leaf);
	void postorderPrint(Node<T> *leaf);
	void preorderPrint(Node<T> *leaf);
    void reverseInorderPrint(Node<T> *leaf);
    void reversePostorderPrint(Node<T> *leaf);
    void reversePreorderPrint(Node<T> *leaf);
    void print2D(Node<T> *leaf, int space);

    Node<T>* findMinNode(Node<T> *leaf);
    void map(T (*function)(T data), Node<T> *leaf);
    void where(bool (*condition)(T data), Node<T> *leaf);
    string toString(string traversal, Node<T> *leaf, bool isFirst);
    Node<T>* subtree(Node<T>* leaf);
    T reduce(T (*function)(T first, T second), T start, vector<T> inOrder);

    Node<T>* toBalanced(vector<T> inOrder, int start, int end);
    void toInOrder(Node<T>* leaf, vector<T>& inOrder);
    BinaryTree<T> balance(Node<T>* leaf);

    bool areIdentical(Node<T>* first, Node<T>* second);
    bool containsSubtree(Node<T>* first, Node<T>* second);

    void flatten(Node<T>* leaf, LinkedList<Node<T>*>& flattened);
public:
    BinaryTree(T* data, int length);
    BinaryTree():root(NULL){};
    void insert(T data);
	Node<T> *search(T data);
    void deleteNode(T data);

	void inorderPrint();
	void postorderPrint();
	void preorderPrint();
    void reverseInorderPrint();
    void reversePostorderPrint();
    void reversePreorderPrint();
    void print2D();

    BinaryTree<T> subtree(T data);
    void map(T (*function)(T data));
    string toString(string traversal);
    void where(bool (*condition)(T data));
    T reduce(T (*function)(T first, T second), T start);

    BinaryTree<T> balance();

    bool containsSubtree(BinaryTree<T> sub);

    LinkedList<Node<T>*> flatten();
    void printFlattaned();
};