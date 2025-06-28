#include <iostream>
#include <string>
#include <vector>

#include "BinaryTree.h"
#include "LinkedList.h"

#define SPACE 10

using namespace std;

template class BinaryTree<int>;
template class BinaryTree<float>;

template <class T>
void BinaryTree<T>::insert(T data, Node<T> *leaf)
{
	if (data < leaf->data)
	{
		if (leaf->left != NULL)
			insert(data, leaf->left);
		else
			leaf->left = new Node<T>(data);
	}
	else if (data >= leaf->data)
	{
		if (leaf->right != NULL)
			insert(data, leaf->right);
		else
			leaf->right = new Node<T>(data);
	}
}

template <class T>
void BinaryTree<T>::insert(T data)
{
	if (root != NULL)
		insert(data, root);
	else
		root = new Node<T>(data);
}

template <class T>
BinaryTree<T>::BinaryTree(T *data, int length)
{
	root = NULL;
	for (int i = 0; i < length; i++)
		this->insert(data[i]);
}

template <class T>
Node<T> *BinaryTree<T>::search(T data, Node<T> *leaf)
{
	if (leaf != NULL)
	{
		if (data == leaf->data)
			return leaf;
		if (data < leaf->data)
			return search(data, leaf->left);
		else
			return search(data, leaf->right);
	}
	return NULL;
}

template <class T>
Node<T> *BinaryTree<T>::search(T data)
{
	return search(data, root);
}

template <class T>
void BinaryTree<T>::map(T (*function)(T data))
{
	map(function, root);
}

template <class T>
void BinaryTree<T>::map(T (*function)(T data), Node<T> *leaf)
{
	if (leaf)
	{
		leaf->data = function(leaf->data);
		map(function, leaf->left);
		map(function, leaf->right);
	}
}

template <class T>
string BinaryTree<T>::toString(string traversal, Node<T> *leaf, bool isFirst)
{
	/*
	LNR - ЛКП
	RLNR - ПКЛ
	NLR - КЛП
	RNLR -ПЛК
	LRN - ЛПК
	RLRN - КПЛ
	*/
	static string ans = "";
	if (isFirst)
		ans = "";
	if (leaf)
	{
		if (traversal == "LNR")
        {
			toString(traversal, leaf->left, false);
			ans += to_string(leaf->data) + " ";
			toString(traversal, leaf->right, false);
		}
		else if (traversal == "RLNR")
        {
			toString(traversal, leaf->right, false);
			ans += to_string(leaf->data) + " ";
			toString(traversal, leaf->left, false);
		}
		else if (traversal == "NLR")
        {
			ans += to_string(leaf->data) + " ";
			toString(traversal, leaf->left, false);
			toString(traversal, leaf->right, false);
		}
		else if (traversal == "RNLR")
        {
			ans += to_string(leaf->data) + " ";
			toString(traversal, leaf->right, false);
			toString(traversal, leaf->left, false);
		}
		else if (traversal == "LRN")
        {
			toString(traversal, leaf->left, false);
			toString(traversal, leaf->right, false);
			ans += to_string(leaf->data) + " ";
		}
		else if (traversal == "RLRN")
        {
			toString(traversal, leaf->right, false);
			toString(traversal, leaf->left, false);
			ans += to_string(leaf->data) + " ";
		}
	}
	return ans;
}

template <class T>
string BinaryTree<T>::toString(string traversal)
{
	return toString(traversal, root, true);
}

template <class T>
void BinaryTree<T>::inorderPrint(Node<T> *leaf)
{
	if (leaf)
	{
		inorderPrint(leaf->left);
		cout << leaf->data << " ";
		inorderPrint(leaf->right);
	}
}

template <class T>
void BinaryTree<T>::inorderPrint()
{
	inorderPrint(root);
	cout << endl;
}

template<class T>
void BinaryTree<T>::postorderPrint(Node<T> *leaf)
{
	if (leaf)
    {
		postorderPrint(leaf->left);
		postorderPrint(leaf->right);
		cout << leaf->data << " ";
	}
}

template<class T>
void BinaryTree<T>::postorderPrint()
{
	postorderPrint(root);
	cout << endl;
}

template<class T>
void BinaryTree<T>::preorderPrint(Node<T> *leaf)
{
	if (leaf)
    {
		cout << leaf->data << " ";
		preorderPrint(leaf->left);
		preorderPrint(leaf->right);
	}
}

template<class T>
void BinaryTree<T>::preorderPrint()
{
	preorderPrint(root);
	cout << endl;
}

template<class T>
void BinaryTree<T>::reverseInorderPrint(Node<T> *leaf)
{
	if (leaf)
    {
		reverseInorderPrint(leaf->right);
		cout << leaf->data << " ";
		reverseInorderPrint(leaf->left);
	}
}

template<class T>
void BinaryTree<T>::reverseInorderPrint()
{
	reverseInorderPrint(root);
	cout << endl;
}

template<class T>
void BinaryTree<T>::reversePreorderPrint(Node<T> *leaf)
{
	if (leaf)
    {
		cout << leaf->data << " ";
		reversePreorderPrint(leaf->right);
		reverseInorderPrint(leaf->left);
	}
}

template<class T>
void BinaryTree<T>::reversePreorderPrint()
{
	reversePostorderPrint(root);
	cout << endl;
}

template<class T>
void BinaryTree<T>::reversePostorderPrint(Node<T> *leaf)
{
	if (leaf)
    {
		reversePostorderPrint(leaf->right);
		reversePostorderPrint(leaf->left);
		cout << leaf->data << " ";
 	}
}

template<class T>
void BinaryTree<T>::reversePostorderPrint()
{
	reversePostorderPrint(root);
	cout << endl;
}

template<class T>
Node<T>* BinaryTree<T>::findMinNode(Node<T>* leaf)
{
	Node<T>* ptr = leaf;
	while (ptr->left)
		ptr = ptr->left;
	return ptr;
	
}

template<class T>
Node<T>* BinaryTree<T>::deleteNode(T data, Node<T> *leaf)
{
	if (leaf == NULL)
		return NULL;
	else if (data < leaf->data)
		leaf->left = deleteNode(data, leaf->left);
	else if (data > leaf->data)
		leaf->right = deleteNode(data, leaf->right);
	else
    {
		if (leaf->left == NULL)
        {
			Node<T>* tmp = leaf->right;
			if (leaf == root)
				root = tmp;
			delete leaf;
			return tmp;
		}
		else if (leaf->right == NULL)
        {
			Node<T>* tmp = leaf->left;
			if (leaf == root)
				root = tmp;
			delete leaf;
			return tmp;
		}
		else
        {
			Node<T>* tmp = findMinNode(leaf->right);
			leaf->data = tmp -> data;
			leaf->right = deleteNode(tmp->data, leaf->right);
		}
	}
	return leaf;
}

template<class T>
void BinaryTree<T>::deleteNode(T data)
{
	deleteNode(data, root);
}

template<class T>
void BinaryTree<T>::where(bool (*condition)(T data), Node<T>* leaf)
{
	if (leaf)
    {
		where(condition, leaf->left);
		where(condition, leaf->right);
		if(!condition(leaf->data))
			this->deleteNode(leaf->data);
	}
}

template<class T>
void BinaryTree<T>::where(bool (*condition)(T data))
{
	where(condition, root);
}

template<class T>
Node<T>* BinaryTree<T>::subtree(Node<T>* leaf)
{
	Node<T>* newRoot = NULL;
	if (leaf)
    {
		newRoot = new Node<T>(leaf->data);
		newRoot->left = subtree(leaf->left);
		newRoot->right = subtree(leaf->right);
	}
	else
		return NULL;
	return newRoot;
}

template<class T>
BinaryTree<T> BinaryTree<T>::subtree(T data)
{
	return subtree(search(data));
}

template<class T>
void BinaryTree<T>::toInOrder(Node<T>* leaf, vector<T>& inOrder)
{
	if (leaf)
    {
		toInOrder(leaf->left, inOrder);
		inOrder.push_back(leaf->data);
		toInOrder(leaf->right, inOrder);
	}
}

template<class T>
Node<T>* BinaryTree<T>::toBalanced(vector<T> inOrder, int start, int end)
{
	if (start > end) return NULL;

	int mid = (start + end)/2;
	Node<T>* newRoot = new Node<T>(inOrder[mid]);

	newRoot->left = toBalanced(inOrder, start, mid - 1);
	newRoot->right = toBalanced(inOrder, mid + 1, end);

	return newRoot;
}

template<class T>
BinaryTree<T> BinaryTree<T>::balance(Node<T>* leaf)
{
	vector<T> inOrder;
	toInOrder(root, inOrder);
	BinaryTree<T> balanced(toBalanced(inOrder, 0, inOrder.size() - 1));
	return balanced;
}

template<class T>
BinaryTree<T> BinaryTree<T>::balance()
{
	return balance(root);
}

template<class T>
void BinaryTree<T>::print2D(Node<T> *leaf, int space)
{
	if (leaf)
    {
		space += SPACE;
		print2D(leaf->right, space);
		cout << endl;
		for (int i = SPACE;i < space;i++) cout << " ";
		cout << leaf->data;
		print2D(leaf->left, space);
	}
}

template<class T>
void BinaryTree<T>::print2D()
{
	print2D(root, 5);
	cout << endl;
}

template<class T>
bool BinaryTree<T>::areIdentical(Node<T>* first, Node<T>* second)
{
	if (first == NULL and second == NULL)
		return true;
	else if(first == NULL or second == NULL)
		return false;
	return (first->data == second->data and areIdentical(first->left, second->left) and areIdentical(first->right, second->right));
}

template<class T>
bool BinaryTree<T>::containsSubtree(Node<T>* first, Node<T>* second)
{
	if (second == NULL)
		return true;
	if (first == NULL)
		return false;
	if (areIdentical(first, second))
		return true;
	return containsSubtree(first->left, second) or containsSubtree(first->right, second);
}

template<class T>
bool BinaryTree<T>::containsSubtree(BinaryTree<T> sub)
{
	return containsSubtree(root, sub.root);
}

template<class T>
T BinaryTree<T>::reduce(T (*function)(T first, T second), T start, vector<T> inOrder)
{
	if (inOrder.size() == 1)
		return function(inOrder[0], start);
	T last = inOrder.back();
	inOrder.pop_back();
	return function(last, reduce(function, start, inOrder));
}

template<class T>
T BinaryTree<T>::reduce(T (*function)(T first, T second), T start)
{
	vector<T> inOrder;
	toInOrder(root, inOrder);
	return reduce(function, start, inOrder);
}

template<class T>
void BinaryTree<T>::flatten(Node<T>* leaf, LinkedList<Node<T>*>& flattened)
{
	if (leaf)
    {
		flatten(leaf->left, flattened);
		flattened.Append(leaf);
		flatten(leaf->right, flattened);
	}
}

template<class T>
LinkedList<Node<T>*> BinaryTree<T>::flatten()
{
	LinkedList<Node<T>*> ans;
	flatten(root, ans);
	return ans;
}

template<class T>
void BinaryTree<T>::printFlattaned()
{
	LinkedList<Node<T>*> flattened = this->flatten();
	for (int i = 0; i < flattened.GetLength();i++)
		cout << flattened.Get(i)->data << " ";
	cout << endl;
}
