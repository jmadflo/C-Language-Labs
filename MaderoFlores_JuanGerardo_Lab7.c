#include <stdio.h>
#include <stdlib.h>

struct Node{
    int elem;
    struct Node * next;
};

typedef struct Node Node;

Node * create_list(int a[], int length_a){
    Node * head = (Node *)malloc(sizeof(Node));
    head->elem = a[0];
    head->next = NULL;
    Node * tail = head;
    Node * tmp;
    for (int i = 1; i < length_a; i++){
        tmp = (Node *)malloc(sizeof(Node));
        tmp->elem = a[i];
        tmp->next = NULL;
        tail->next = tmp;
        tail = tail->next;
    }
    return head;
}

int get_length(Node * head){
    int length = 0;
    Node * tmp = head;
    while (tmp != NULL){
        tmp = tmp->next;
        length++;
    }
    return length;
}

int append(Node * head, int i){
    Node * new_tail = (Node *)malloc(sizeof(Node));
    new_tail->elem = i;
    new_tail->next = NULL;
    Node * tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_tail;
    return 0;
}

Node * preappend(Node * head, int i){
    Node * new_node = (Node *)malloc(sizeof(Node));
    new_node->elem = i;
    new_node->next = head;
    return new_node;
}

int join(Node * head_1, Node * head_2){
    Node * tmp = head_1;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = head_2;
    return 0;
}

int main(void) {
    // Test 1
    int a[5] = {5, 10, 15, 20, 25};
    Node * head = create_list(a, sizeof(a) / sizeof(a[0]));
    Node * tmp = head;
    printf("This list starts off containing the first five multiples of 5 which are\n");
    while (tmp != NULL){
        printf("%d, ", tmp->elem);
        tmp = tmp->next;
    }
    printf("\n");
    tmp = head;
    
    // Test 2
    int length = get_length(tmp);
    printf("According to the get_length function, the length of this linked list is %d.\n", length);
    tmp = head;
    
    // Test 3
    int new_tail_elem = 30;
    append(head, new_tail_elem);
    printf("Now, we use the append function to add a node with element 30 to the end of the linked list. The elements of the updated list are\n");
    while (tmp != NULL){
        printf("%d, ", tmp->elem);
        tmp = tmp->next;
    }
    printf("\n");
    
    // Test 4
    int new_head_elem = 0;
    tmp = preappend(head, new_head_elem);
    printf("Now, we use the preappend function to add a node with element 0 to the beginning of the linked list. The elements of the updated list are\n");
    while (tmp != NULL){
        printf("%d, ", tmp->elem);
        tmp = tmp->next;
    }
    printf("\n");
    
    // Test 5
    int b[3] = {35, 40, 45};
    Node * head_2 = create_list(b, sizeof(b) / sizeof(b[0]));
    tmp = head_2;
    printf("Now we create a new list containing three additional multiples of 5 which are\n");
    while (tmp != NULL){
        printf("%d ", tmp->elem);
        tmp = tmp->next;
    }
    tmp = head;
    printf("\n");
    printf("Now we append the second list to the end of the first list to create a new list containing multiples of 5 up to 45 which are\n");
    join(head, head_2);
    while (tmp != NULL){
        printf("%d, ", tmp->elem);
        tmp = tmp->next;
    }
    return 0;
}