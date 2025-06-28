#include<iostream>
#include "BinaryTree.h"
#include "menu.h"

using namespace std;

int main()
{
    int choice = mainChoice();
    switch (choice)
    {
        case 1:
        {
            int data = dataType();
            lab3(data);
            break;
        }
        case 2:
        {
            test();
            break;
        }
    }
}
