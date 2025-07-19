#include <stdio.h>
#include <stdlib.h>
#include "helper_funcs.h"

struct cdlinklist {
    struct cdlinklist *left;
    int data;
    struct cdlinklist *right;
};

typedef struct cdlinklist node;

node *start = NULL;
int nodectr = 0;

// Function to create a new node with user input
node* getnode() {
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Display menu
int menu() {
    int ch;
    clear_screen();
    printf("\n\n=== MENU ===");
    printf("\n1. Create List");
    printf("\n2. Insert at Beginning");
    printf("\n3. Insert at End");
    printf("\n4. Insert at Middle");
    printf("\n5. Delete from Beginning");
    printf("\n6. Delete from End");
    printf("\n7. Delete from Middle");
    printf("\n8. Display Left to Right");
    printf("\n9. Display Right to Left");
    printf("\n10. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

// Create initial list
void cdll_createlist(int n) {
    int i;
    node *newnode;
    if (start != NULL) {
        printf("List already exists.\n");
        return;
    }

    for (i = 0; i < n; i++) {
        newnode = getnode();
        if (start == NULL) {
            start = newnode;
            start->left = start;
            start->right = start;
        } else {
            newnode->left = start->left;
            newnode->right = start;
            start->left->right = newnode;
            start->left = newnode;
        }
        nodectr++;
    }
    printf("List created with %d nodes.\n", nodectr);
}

// Display list left to right
void cdll_display_left_right() {
    if (start == NULL) {
        printf("Empty list.\n");
        return;
    }

    node *temp = start;
    printf("List (Left to Right): ");
    do {
        printf("%d ", temp->data);
        temp = temp->right;
    } while (temp != start);
    printf("\n");
}

// Display list right to left
void cdll_display_right_left() {
    if (start == NULL) {
        printf("Empty list.\n");
        return;
    }

    node *temp = start->left;
    printf("List (Right to Left): ");
    do {
        printf("%d ", temp->data);
        temp = temp->left;
    } while (temp != start->left);
    printf("\n");
}

// Insert at beginning
void cdll_insert_beg() {
    node *newnode = getnode();
    nodectr++;

    if (start == NULL) {
        start = newnode;
        start->left = start->right = start;
    } else {
        newnode->left = start->left;
        newnode->right = start;
        start->left->right = newnode;
        start->left = newnode;
        start = newnode;
    }
    printf("Node inserted at beginning.\n");
}

// Insert at end
void cdll_insert_end() {
    node *newnode = getnode();
    nodectr++;

    if (start == NULL) {
        start = newnode;
        start->left = start->right = start;
    } else {
        newnode->left = start->left;
        newnode->right = start;
        start->left->right = newnode;
        start->left = newnode;
    }
    printf("Node inserted at end.\n");
}

// Insert at middle
void cdll_insert_mid() {
    int pos, ctr = 1;
    node *temp, *newnode;

    printf("Enter position to insert at (2 to %d): ", nodectr);
    scanf("%d", &pos);

    if (pos <= 1 || pos > nodectr) {
        printf("Invalid middle position.\n");
        return;
    }

    newnode = getnode();
    temp = start;

    while (ctr < pos - 1) {
        temp = temp->right;
        ctr++;
    }

    newnode->left = temp;
    newnode->right = temp->right;
    temp->right->left = newnode;
    temp->right = newnode;
    nodectr++;

    printf("Node inserted at position %d.\n", pos);
}

// Delete from beginning
void cdll_delete_beg() {
    node *temp;
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    nodectr--;
    if (start->right == start) {
        free(start);
        start = NULL;
    } else {
        temp = start;
        start = start->right;
        temp->left->right = start;
        start->left = temp->left;
        free(temp);
    }

    printf("Node deleted from beginning.\n");
}

// Delete from end
void cdll_delete_last() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    nodectr--;
    if (start->right == start) {
        free(start);
        start = NULL;
    } else {
        node *last = start->left;
        last->left->right = start;
        start->left = last->left;
        free(last);
    }

    printf("Node deleted from end.\n");
}

// Delete from middle
void cdll_delete_mid() {
    int pos, ctr = 1;
    node *temp;

    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position to delete (2 to %d): ", nodectr - 1);
    scanf("%d", &pos);

    if (pos <= 1 || pos >= nodectr) {
        printf("Invalid middle position.\n");
        return;
    }

    temp = start;
    while (ctr < pos) {
        temp = temp->right;
        ctr++;
    }

    temp->left->right = temp->right;
    temp->right->left = temp->left;
    free(temp);
    nodectr--;

    printf("Node at position %d deleted.\n", pos);
}

// Main function
int main() {
    int ch, n;

    while (1) {
        ch = menu();
        switch (ch) {
            case 1:
                printf("Enter number of nodes to create: ");
                scanf("%d", &n);
                cdll_createlist(n);
                break;
            case 2:
                cdll_insert_beg();
                break;
            case 3:
                cdll_insert_end();
                break;
            case 4:
                cdll_insert_mid();
                break;
            case 5:
                cdll_delete_beg();
                break;
            case 6:
                cdll_delete_last();
                break;
            case 7:
                cdll_delete_mid();
                break;
            case 8:
                cdll_display_left_right();
                break;
            case 9:
                cdll_display_right_left();
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
        printf("\nPress Enter to continue...");
        getchar(); // To consume leftover newline
        getchar(); // Wait for Enter
    }

    return 0;
}
