#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

node* getnode(int item)
{
    node* new_node = new node;
    new_node->data = item;
    new_node->next = NULL;
    return new_node;
}

node* insert(node* head, int item)
{
    node* temp = head;
    head = getnode(item);
    head->next = temp;
    return head;
}

node* display(node* head) {
    if(head != NULL){
        printf("%d ", head->data);
        head = display(head->next);
    }
}

void sortedInsert(struct node** head_ref, struct node* new_node)
{
    if((*head_ref) == NULL || (*head_ref)->data >= new_node->data){
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else{
        node* current = *head_ref;
        while(current->next != NULL && current->next->data < new_node->data){
            current = current->next;
        }
        new_node->next = current->next;
        current->next=new_node;
    }
}

node* insertion_sort(node* head)
{
    node* sorted = NULL;
    node* current = head;
    while(current != NULL){
        node* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    return sorted;
}

int main()
{
    node* head;
    head=insert(head, 10);head=insert(head, 50);head=insert(head, 20);
    head=insert(head, 80);head=insert(head, 70);head=insert(head, 15);
    head = insertion_sort(head);
    display(head);

    return 0;
}
