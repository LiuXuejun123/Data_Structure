#include <stdio.h>
#include <stdlib.h>
typedef struct node_st
{
    int data;
    struct node_st* next;
}node;
node* jose_create(int num)
{
    node* head;
    node* newnode;
    node* temp;
    int i=1;
    head=malloc(sizeof(*head));
    head->data=i;
    head->next=head;
    i++;
    temp=head;
    for (;  i<=num ; i++) {
       newnode=malloc(sizeof(*newnode));
       newnode->data=i;
       newnode->next=head;
       temp->next=newnode;
       temp=newnode;
    }
    return head;
}
void jose_show(node* l)
{
   node* list;
    for (list=l; list->next != l  ;list=list->next ) {
        printf("%d" ,list->data);
    }
    printf("%d ",list->data);
}
void jose_kill(node* l,int n){
    node* temp;
    node* node1;
    temp=l;
    int i=1;
    while(temp!=temp->next) {
        while (i < n) {
            node1 = temp;
            temp = temp->next;
            i++;
        }
        printf("%d", temp->data);
        node1->next = temp->next;
        free(temp);
        temp = node1->next;
        i = 1;
    }
    printf("\n");
}

int main() {
    int num=8;
    int n=3;
    node* p1;
    p1=jose_create(num);
    jose_show(p1);
    jose_kill(p1,n);
    exit(0);
}
