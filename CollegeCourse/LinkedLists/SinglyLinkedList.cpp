#include <iostream>
#include "helper_funcs.h"

using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef node *NodePtr;
NodePtr start = NULL;

int menu()
{
    int ch;

    clear_screen();
    
    cout << "\n\n 1.Create a list ";
    cout << "\n--------------------------";
    cout << "\n 2.Insert a node at beginning ";
    cout << "\n 3.Insert a node at end";
    cout << "\n 4.Insert a node at middle";
    cout << "\n--------------------------";
    cout << "\n 5.Delete a node from beginning";
    cout << "\n 6.Delete a node from Last";
    cout << "\n 7.Delete a node from Middle";
    cout << "\n--------------------------";
    cout << "\n 8.Traverse the list (Left to Right)";
    cout << "\n 9.Traverse the list (Right to Left)";
    cout << "\n--------------------------";
    cout << "\n 10. Count nodes ";
    cout << "\n 11. Exit ";
    cout << "\n\n Enter your choice: ";
    
    cin >> ch;
    
    return ch;
}

NodePtr getnode()
{
    NodePtr newnode = new node;
    // newnode = (NodePtr) malloc(sizeof(node)); used for C language
    
    cout << "\n Enter data: ";
    
    cin >> newnode->data;
    
    newnode->next = NULL;
    
    return newnode;
}

// This function will return the count of number of nodes in the linked list
int countnode(NodePtr ptr)
{
    int count = 0;
    
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return (count);
}

void createlist(int n)
{
    int i;
    
    NodePtr newnode;
    NodePtr temp;
    
    for (i = 0; i < n; i++)
    {
        newnode = getnode();
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}

void traverse()
{
    NodePtr temp;
    temp = start;
    cout << "\n The contents of List (Left to Right): \n";
    if (start == NULL)
    {
        cout << "\n Empty List";
        return;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
    }
    cout << " X ";
}

void rev_traverse(NodePtr start)
{
    if (start == NULL)
    {
        return;
    }
    else
    {
        rev_traverse(start->next);
        cout << start->data << "-->";
    }
}

void insert_at_beg()
{
    NodePtr newnode;
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->next = start;
        start = newnode;
    }
}

void insert_at_end()
{
    NodePtr newnode, temp;
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
}

void insert_at_mid()
{
    NodePtr newnode, temp, prev;
    int pos, nodectr, ctr = 1;
    newnode = getnode();
    cout << "\n Enter the position: ";
    cin >> pos;
    nodectr = countnode(start);
    if (pos > 1 && pos < nodectr)
    {
        temp = prev = start;
        while (ctr < pos)
        {
            prev = temp;
            temp = temp->next;
            ctr++;
        }
        prev->next = newnode;
        newnode->next = temp;
    }
    else
        cout << "position " << pos << " is not a middle position";
}

void delete_at_beg()
{
    NodePtr temp;
    if (start == NULL)
    {
        cout << "\n No nodes are exist..";
        return;
    }
    else
    {
        temp = start;
        start = temp->next;
        delete temp;
        cout << "\n Node deleted ";
    }
}

void delete_at_last()
{
    NodePtr temp, prev;
    if (start == NULL)
    {
        cout << "\n Empty List..";
        return;
    }
    else
    {
        temp = start;
        prev = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
        cout << "\n Node deleted ";
    }
}

void delete_at_mid()
{
    int ctr = 1, pos, nodectr;
    NodePtr temp, prev;
    if (start == NULL)
    {
        cout << "\n Empty List..";
        return;
    }
    else
    {
        cout << "\n Enter position of node to delete: ";
        cin >> pos;
        nodectr = countnode(start);
        if (pos > nodectr)
        {
            cout << "\nThis node does not exist";
        }
        if (pos > 1 && pos < nodectr)
        {
            temp = prev = start;
            while (ctr < pos)
            {
                prev = temp;
                temp = temp->next;
                ctr++;
            }
            prev->next = temp->next;
            delete temp; // free(temp); in C language
            cout << "\n Node deleted..";
        }
        else
        {
            cout << "\n Invalid position..";
        }
    }
}

int main()
{
    int ch, n;
    while (1)
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            if (start == NULL)
            {
                cout << "\n Number of nodes you want to create: ";
                cin >> n;
                createlist(n);
                cout << "\n List created..";
            }
            else
                cout << "\n List is already created..";
            break;
        case 2:
            insert_at_beg();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            insert_at_mid();
            break;
        case 5:
            delete_at_beg();
            break;
        case 6:
            delete_at_last();
            break;
        case 7:
            delete_at_mid();
            break;
        case 8:
            traverse();
            break;
        case 9:
            cout << "\n The contents of List (Right to Left): \n";
            rev_traverse(start);
            cout << " X ";
            break;
        case 10:
            cout << "\n No of nodes : " << countnode(start);
            break;
        case 11:
            exit(0);
        }
    }
    return 0;
}
