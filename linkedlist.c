#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Insert at the beginning
void insertAtBeginning(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;

    free(temp);
}

// Delete from end
void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *temp = *head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Display the linked list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Search an element
void search(struct Node *head, int value) {
    int position = 1;

    while (head != NULL) {
        if (head->data == value) {
            printf("%d found at position %d\n", value, position);
            return;
        }

        head = head->next;
        position++;
    }

    printf("%d not found in the list\n", value);
}

int main() {
    struct Node *head = NULL;
    int choice, value;

    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 3:
                deleteFromBeginning(&head);
                break;

            case 4:
                deleteFromEnd(&head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;

            case 7:
                printf("Program exited.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}