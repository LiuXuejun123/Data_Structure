/*
 *多项式合并；单向链表合并
 *
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct node_st
{
    int coef;
    int exp;
    struct node_st* next;
} node;
node* poly_create(int a[][2],int n){
    node* node1;
    node* newnode;
    node* p;
    int i;
    node1=malloc(sizeof(*node1));
    node1->next=NULL;
    p=node1;
    for ( i = 0; i < n; ++i) {
        newnode=malloc(sizeof(*newnode));
        newnode->coef=a[i][0];
        newnode->exp=a[i][1];
        newnode->next=NULL;
        p->next=newnode;
        p=newnode;
    }
    return node1;
}
void poly_show(node* l){
    node* nodetemp;
    for ( nodetemp = l->next; nodetemp !=NULL; nodetemp=nodetemp->next ) {
        printf("(%d %d) ",nodetemp->coef,nodetemp->exp);
    }
    printf("\n");
}
void ploy_union(node* l1,node* l2)
{
    node* p;
    node* q;
    node* r;
    p=l1->next;
    q=l2->next;
    r=l1;
    while (p && q){
        if (p->exp<q->exp){
            r->next=p;
            r=p;
            p=p->next;
        }
        else if(p->exp>q->exp){
            r->next=q;
            r=q;
            q=q->next;
        }
        else{
            p->coef+=q->coef;
            if (p->coef){
                r->next=p ;
                r = p;
            }
                p=p->next;
                q=q->next;

        }
}
    if (p==NULL)
        r->next=q;
    else
        r->next=p;
}
int main() {
    int arr[][2]={{5,0},{2,1},{8,8},{3,16}};
    int brr[][2]={{6,1},{16,6},{-8,8}};
    struct node_st* p1;
    struct node_st* p2;
    p1 = poly_create(arr,4);
    p2 = poly_create(brr,3);
    poly_show(p1);
    poly_show(p2);
    ploy_union(p1,p2);
    poly_show(p1);
    exit(0);
}
