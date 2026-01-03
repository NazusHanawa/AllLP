#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void list_add(Node** head, int value) {
    Node* new_node = malloc(sizeof(Node));
    
    if (new_node) {
        new_node->value = value;
        new_node->next = *head;
        *head = new_node;
    }
}

void print_list(Node* node) {
    printf("List: ");
    while (node != NULL) {
        printf("%d -> ", node->value);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    Node* list = NULL;
    
    list_add(&list, 15);
    list_add(&list, 25);
    list_add(&list, 300);

    print_list(list);

    return 0;
}