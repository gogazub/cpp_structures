#include <iostream>
#include <vector>
#include <map>
#include "menu.h"
#include "LinkedList.h"
#include "BinaryTree.h"

using namespace std;

int mainChoice()
{
    int choice = 0;
    cout << "1. Lab 3" << endl
         << "2. Test" << endl;
    cin >> choice;
    while (choice > 2 or choice < 1)
    {
        cout << "Please choose again" << endl;
        cout << "1. Lab 3" << endl
             << "2. Test" << endl;
        cin >> choice;
    }
    return choice;
}

int dataType()
{
    int choice = 0;

    cout << "Please choose your data type:" << endl;
    cout << "1. Integer" << endl
         << "2. Float" << endl;
    cin >> choice;
    while (choice > 2 or choice < 1)
    {
        cout << "Please again" << endl;
        cout << "1. Integer" << endl
             << "2. Float" << endl;
        cin >> choice;
    }

    return choice;
}

string traversals()
{
    int choice = 0;
    cout << "Choose traversal" << endl;
    cout << "1. LNR" << endl;
    cout << "2. RLNR" << endl;
    cout << "3. NLR" << endl;
    cout << "4. RNLR" << endl;
    cout << "5. LRN" << endl;
    cout << "6. RLRN" << endl;
    cin >> choice;
    while (choice < 1 or choice > 6)
    {
        cout << "Please choose again" << endl;
        cout << "1. LNR" << endl;
        cout << "2. RLNR" << endl;
        cout << "3. NLR" << endl;
        cout << "4. RNLR" << endl;
        cout << "5. LRN" << endl;
        cout << "6. RLRN" << endl;
        cin >> choice;
    }
    map<int, string> traversal = {
        {1, "LNR"},
        {2, "RLNR"},
        {3, "NLR"},
        {4, "RNLR"},
        {5, "LRN"},
        {6, "RLRN"}
    };
    return traversal[choice];
}

void operations()
{
    cout << "1. insert" << endl;
    cout << "2. delete" << endl;
    cout << "3. search" << endl;
    cout << "4. Inorder print" << endl;
    cout << "5. Postorder print" << endl;
    cout << "6. Preorder print" << endl;
    cout << "7. Reverse inorder print" << endl;
    cout << "8. Reverse postorder print" << endl;
    cout << "9. Reverse preorder print" << endl;
    cout << "10. Print 2d" << endl;
    cout << "11. Get a subtree" << endl;
    cout << "12. To string" << endl;
    cout << "13. Balance" << endl;
    cout << "14. Contains subtree" << endl;
    cout << "15. Add a tree" << endl;
    cout << "16. Print all 2D" << endl;
    cout << "17. Flatten" << endl;
    cout << "18. Exit" << endl;
}

void lab3Int()
{
    int choice = 0;
    vector<BinaryTree<int>> test;
    do
    {
        operations();
        cin >> choice;
        switch (choice)
        {
        case 1:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].print2D();
                int value = 0;
                cout << "Enter a value:" << endl;
                cin >> value;
                test[index].insert(value);
                cout << "---------------------------------------------" << endl;
                test[index].print2D();
            }
            break;
        }
        case 2:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].print2D();
                int value = 0;
                cout << "Enter a value:" << endl;
                cin >> value;
                if(test[index].search(value) == NULL){
                    cout << "Tree " << index << " doesn't contain " << value << endl; 
                }
                else{
                    test[index].deleteNode(value);
                    cout << "---------------------------------------------" << endl;
                    test[index].print2D();
                }
            }
            break;
        }
        case 3:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].print2D();
                int value = 0;
                cout << "Choose a value:" << endl;
                cin >> value;
                if(test[index].search(value) == NULL){
                    cout << "Tree " << index << " doesn't contain " << value << endl; 
                }
                else{
                    cout << "Tree " << index << " contains " << value << endl; 
                }
            }
            break;
        }
        case 4:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].inorderPrint();
            }
            break;
        }
        case 5:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].postorderPrint();
            }
            break;
        }
        case 6:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].preorderPrint();
            }
            break;
        }
        case 7:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].reverseInorderPrint();
            }
            break;
        }
        case 8:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].reversePostorderPrint();
            }
            break;
        }
        case 9:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].reversePreorderPrint();
            }
            break;
        }
        case 10:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].print2D();
            }
            break;
        }
        case 11:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].print2D();
                int value = 0;
                cout << "Choose a value:" << endl;
                cin >> value;
                if(test[index].search(value) == NULL){
                    cout << "Tree " << index << " doesn't contain " << value << endl; 
                }
                else{
                    BinaryTree<int> sub = test[index].subtree(value);
                    sub.print2D();
                }
            }
            break;
        }
        case 12:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                string traversal = traversals();
                string tmp = test[index].toString(traversal);
                cout << tmp << endl;
            }
            break;
        }
        case 13:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index] = test[index].balance();
            }
            break;
        }
        case 14:
        {
            int first = 0, second = 0;
            cout << "Choose two trees:" << endl;
            cin >> first >> second;
            if (first < 0 or first > test.size() or second < 0 or second > test.size())
            {
                cout << "Wrong indexes" << endl;
            }
            else
            {
                if (test[first].containsSubtree(test[second]))
                {
                    cout << "Tree " << first << " contains tree " << second << endl;
                }
                else
                {
                    cout << "Tree " << first << " doesn't contain tree " << second << endl;
                }
            }
            break;
        }
        case 15:
        {
            int length = 0;
            cout << "Enter length:" << endl;
            cin >> length;
            int *values = (int *)calloc(length, sizeof(int));
            cout << "Enter values:" << endl;
            for (int i = 0; i < length; i++)
            {
                cin >> values[i];
            }
            test.push_back(BinaryTree<int>(values, length));
            break;
        }
        case 16:{
            for(auto tree: test){
                tree.print2D();
                cout << "---------------------------------------------" << endl;
            }
            break;
        }
        case 17:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].printFlattaned();
                test[index].inorderPrint();
            }
            break;
        }
        }
        
    } while (choice != 18);
}

void lab3Float()
{
    int choice = 0;
    vector<BinaryTree<float>> test;
    do
    {
        operations();
        cin >> choice;
        switch (choice)
        {
        case 1:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].print2D();
                float value = 0;
                cout << "Enter a value:" << endl;
                cin >> value;
                test[index].insert(value);
                cout << "---------------------------------------------" << endl;
                test[index].print2D();
            }
            break;
        }
        case 2:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].print2D();
                float value = 0;
                cout << "Enter a value:" << endl;
                cin >> value;
                if(test[index].search(value) == NULL){
                    cout << "Tree " << index << " doesn't contain " << value << endl; 
                }
                else{
                    test[index].deleteNode(value);
                    cout << "---------------------------------------------" << endl;
                    test[index].print2D();
                }
            }
            break;
        }
        case 3:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].print2D();
                float value = 0;
                cout << "Choose a value:" << endl;
                cin >> value;
                if(test[index].search(value) == NULL){
                    cout << "Tree " << index << " doesn't contain " << value << endl; 
                }
                else{
                    cout << "Tree " << index << " contains " << value << endl; 
                }
            }
            break;
        }
        case 4:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].inorderPrint();
            }
            break;
        }
        case 5:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].postorderPrint();
            }
            break;
        }
        case 6:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].preorderPrint();
            }
            break;
        }
        case 7:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].reverseInorderPrint();
            }
            break;
        }
        case 8:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].reversePostorderPrint();
            }
            break;
        }
        case 9:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].reversePreorderPrint();
            }
            break;
        }
        case 10:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].print2D();
            }
            break;
        }
        case 11:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].print2D();
                float value = 0;
                cout << "Choose a value:" << endl;
                cin >> value;
                if(test[index].search(value) == NULL){
                    cout << "Tree " << index << " doesn't contain " << value << endl; 
                }
                else{
                    BinaryTree<float> sub = test[index].subtree(value);
                    sub.print2D();
                }
            }
            break;
        }
        case 12:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                string traversal = traversals();
                string tmp = test[index].toString(traversal);
                cout << tmp << endl;
            }
            break;
        }
        case 13:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index] = test[index].balance();
            }
            break;
        }
        case 14:
        {
            int first = 0, second = 0;
            cout << "Choose two trees:" << endl;
            cin >> first >> second;
            if (first < 0 or first > test.size() or second < 0 or second > test.size())
            {
                cout << "Wrong indexes" << endl;
            }
            else
            {
                if (test[first].containsSubtree(test[second]))
                {
                    cout << "Tree " << first << " contains tree " << second << endl;
                }
                else
                {
                    cout << "Tree " << first << " doesn't contain tree " << second << endl;
                }
            }
            break;
        }
        case 15:
        {
            int length = 0;
            cout << "Enter length:" << endl;
            cin >> length;
            float *values = (float *)calloc(length, sizeof(float));
            cout << "Enter values:" << endl;
            for (int i = 0; i < length; i++)
            {
                cin >> values[i];
            }
            test.push_back(BinaryTree<float>(values, length));
            break;
        }
        case 16:{
            for(auto tree: test){
                tree.print2D();
                cout << "---------------------------------------------" << endl;
            }
            break;
        }
        case 17:{
            int index = 0;
            cout << "Choose a tree:" << endl; 
            cin >> index;
            if(index < 0 or index > test.size()){
                cout << "Wrong index" << endl;
            }
            else{
                test[index].printFlattaned();
                test[index].inorderPrint();
            }
            break;
        }
        }
    } while (choice != 18);
}

void lab3(int data)
{
    switch (data)
    {
    case 1:
        lab3Int();
        break;
    case 2:
        lab3Float();
        break;
    }
}

float multByTwo(float data){
    return data * 2;
}

bool condition(float data){
    return (int)data%2 == 0;
}

int red(int a, int b){
    return 2 * a + 3 * b;
}

void test()
{
    float a[] = {4.06, 5.84, 2.08, 1.19, 9.95, 1.43, 6.17, 8.74, 2.30, 2.75};
    BinaryTree<float> test(a, 9);
    test.print2D();
    cout << "------------------------------------------------" << endl << "Add a 10" << endl;
    test.insert(10);
    test.print2D();
    cout << "------------------------------------------------" << endl << "Delete a 1.19" << endl;
    test.deleteNode(1.19);
    test.print2D();
    cout << "------------------------------------------------" << endl << "Map function that multiply by 2" << endl;
    test.map(multByTwo);
    test.print2D();
    cout << "------------------------------------------------" << endl << "Get a subtree with value 11.68" << endl;
    BinaryTree<float> sub = test.subtree(11.68);
    sub.print2D();
    cout << "------------------------------------------------" << endl << "Contain subtree function check" << endl;
    if(test.containsSubtree(sub)){
        cout << "Contains" << endl;
    }
    cout << "------------------------------------------------" << endl << "Lets delete 12.34 from our subtree" << endl;
    sub.deleteNode(12.34);
    sub.print2D();
    if(test.containsSubtree(sub) == false){
        cout << "Doens't contain anymore" << endl;
    }
    cout << "------------------------------------------------" << endl << "Where function that leaves only elements whose integer part is even" << endl;
    test.where(condition);
    test.print2D();

    cout << "------------------------------------------------" << endl << "Reduce function test" << endl;
    cout << "Reduce takes in a function red(a, b) = 2 * a + 3 * b and initial value equal to 4" << endl;
    cout << "Reduce(red, 4) = red(3, red(2, red(1, 4))) = 2 * 3 + 3 * (2 * 2 + 3 * (2 * 1 + 3 * 4)) = " << endl;
    cout << "= 6 + 3 * (4 + 3 * (2 + 12)) = 6 + 3 * (4 + 3 * 14) = 6 + 3 * (4 + 42) = 6 + 3 * 46 = 6 + 138 = 144" << endl;
    int b[]  = {1, 2, 3};
    BinaryTree<int> reduceTest(b, 3);
    cout << "Reduce is equal to " << reduceTest.reduce(red, 4) << endl;
}
