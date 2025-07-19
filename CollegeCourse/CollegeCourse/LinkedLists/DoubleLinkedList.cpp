#include <stdio.h>
#include <stdlib.h>
#include "helper_funcs.h"

// creating structure for double linked list
struct dlinklist
{
  struct dlinklist *left;
  int data;
  struct dlinklist *right;
};

// renaming dlinklist as node
typedef struct dlinklist node;
node *start = NULL;

// function to ask choice for an operation on double linked list
int menu()
{
  int ch;

  clear_screen();

  printf("\n 1.Create");
  printf("\n------------------------------");
  printf("\n 2. Insert a node at beginning ");
  printf("\n 3. Insert a node at end");
  printf("\n 4. Insert a node at middle");
  printf("\n------------------------------");
  printf("\n 5. Delete a node from beginning");
  printf("\n 6. Delete a node from Last");
  printf("\n 7. Delete a node from Middle");
  printf("\n------------------------------");
  printf("\n 8. Traverse the list from Left to Right");
  printf("\n 9. Traverse the list from Right to Left ");
  printf("\n------------------------------");
  printf("\n 10.Count the Number of nodes in the list");
  printf("\n 11.Exit ");
  printf("\n\n Enter your choice: ");

  scanf("%d", &ch);

  return ch;
}

// function to create a node dynamically
node *getnode()
{
  node *newnode;
  newnode = (node *)malloc(sizeof(node));
  printf("\n Enter data: ");
  scanf("%d", &newnode->data);
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

// funciton to create a double linked list with n nodes
void createlist(int n)
{
  int i;
  node *newnode;
  node *temp;
  for (i = 1; i <= n; i++)
  {
    newnode = getnode();
    if (start == NULL)
      start = newnode;
    else
    {
      temp = start;
      while (temp->right != NULL)
        temp = temp->right;
      temp->right = newnode;
      newnode->left = temp;
    }
  }
}

// function to count the number of nodes in the linked list
int countnode(node *start)
{
  if (start == NULL)
    return 0;
  else
    return 1 + countnode(start->right);
}

// function to insert a node at the beginning of the double linked list
void dll_insert_beg()
{
  node *newnode;
  newnode = getnode();
  if (start == NULL)
    start = newnode;
  else
  {
    newnode->right = start;
    start->left = newnode;
    start = newnode;
  }
  printf("\n New Node has been inserted at the beginning ..\n");
}

// function to insert a node at the end of the double linked list
void dll_insert_end()
{
  node *newnode, *temp;
  newnode = getnode();
  if (start == NULL)
    start = newnode;
  else
  {
    temp = start;
    while (temp->right != NULL)
      temp = temp->right;
    temp->right = newnode;
    newnode->left = temp;
  }
  printf("\n New Node has been inserted at the end ..\n");
}

// function to insert a node at specified position in the double linked list
void dll_insert_mid()
{
  node *newnode, *temp;
  int pos, nodectr, ctr = 1;
  newnode = getnode();
  printf("\n Enter the position: ");
  scanf("%d", &pos);
  nodectr = countnode(start);
  if (pos - nodectr >= 2)
  {
    printf("\n Position is out of range..");
    return;
  }
  if (pos > 1 && pos < nodectr)
  {
    temp = start;
    while (ctr < pos - 1)
    {
      temp = temp->right;
      ctr++;
    }
    newnode->left = temp;
    newnode->right = temp->right;
    temp->right->left = newnode;
    temp->right = newnode;
    printf("\n New Node has been inserted at the given position ..\n");
  }
  else
    printf("position %d of list is not a intermediate position ", pos);
}

// function to delete a node from the beginning of the double linked list
void dll_delete_beg()
{
  node *temp;
  if (start == NULL)
  {
    printf("\n Empty list");
    getchar();
    return;
  }
  else
  {
    temp = start;
    start = start->right;
    start->left = NULL;
    free(temp);
    printf("\n Node deleted ");
  }
}

// function to delete a node from the end of the double linked list
void dll_delete_last()
{
  node *temp;
  if (start == NULL)
  {
    printf("\n Empty list");
    getchar();
    return;
  }
  else
  {
    temp = start;
    while (temp->right != NULL)
      temp = temp->right;
    temp->left->right = NULL;
    free(temp);
    temp = NULL;
    printf("\n Node deleted ");
  }
}

// funciton to delete a node from a specified position in the double linked list
void dll_delete_mid()
{
  int i = 0, pos, nodectr;
  node *temp;
  if (start == NULL)
  {
    printf("\n Empty List");
    getchar();
    return;
  }
  else
  {
    printf("\n Enter the position of the node to delete: ");
    scanf("%d", &pos);
    nodectr = countnode(start);
    if (pos > nodectr)
    {
      printf("\nthis node does not exist");
      getchar();
      return;
    }
    if (pos > 1 && pos < nodectr)
    {
      temp = start;
      i = 1;
      while (i < pos)
      {
        temp = temp->right;
        i++;
      }
      temp->right->left = temp->left;
      temp->left->right = temp->right;
      free(temp);
      printf("\n node deleted..");
    }
    else
    {
      printf("\n Invalid position..");
      getchar();
    }
  }
}

// function to traverse a double linked list from Left to Right
void traverse_left_to_right()
{
  node *temp;
  temp = start;
  printf("\n The contents of List (Left to Right):");
  if (start == NULL)
    printf("\n Empty List");
  else
  {
    while (temp != NULL)
    {
      printf("%d-->", temp->data);
      temp = temp->right;
    }
  }
  printf(" X ");
}

// function to traverse a double linked list from Right to Left
void traverse_right_to_left()
{
  node *temp;
  temp = start;
  printf("\n The contents of List (Right to Left):");
  if (start == NULL)
    printf("\n Empty List");
  else
  {
    while (temp->right != NULL)
      temp = temp->right;
  }
  while (temp != NULL)
  {
    printf("%d-->", temp->data);
    temp = temp->left;
  }
}

// main function
int main()
{
  int ch, n;
  printf("C Program to illustate the operations on Double Linked List \n");
  printf("Author : Dr. Paras Jain \n");
  printf("Experiment Date :  \n"); // self details
  printf("Submission Date : \n");
  printf("---------------------------------------------------------------------------------------------------------------");
  while (1)
  {
    ch = menu();
    switch (ch)
    {
    case 1:
      printf("\n Enter Number of nodes to create: ");
      scanf("%d", &n);
      createlist(n);
      printf("\n List created..");
      break;
    case 2:
      dll_insert_beg();
      break;
    case 3:
      dll_insert_end();
      break;
    case 4:
      dll_insert_mid();
      break;
    case 5:
      dll_delete_beg();
      break;
    case 6:
      dll_delete_last();
      break;
    case 7:
      dll_delete_mid();
      break;
    case 8:
      traverse_left_to_right();
      break;
    case 9:
      traverse_right_to_left();
      printf(" X ");
      break;
    case 10:
      printf("\n Number of nodes: %d", countnode(start));
      break;
    case 11:
      exit(0);
    }
    getchar();
  }
}
