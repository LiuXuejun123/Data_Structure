//
// Created by liuxu on 2021/2/5.
//

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
list* List_create()
{
    list* node;
    node=malloc(sizeof(*node));
    if (node==NULL)return NULL;
    node->next=NULL;
    return node;
}
int List_insert_at(list* node,int i,datatype* data)
{
int j=0;
list* node_temp=node;
list* newnode;
    if (i<0)return -1;
    while (j < i && node_temp != NULL)
    {
        node_temp = node_temp->next;
        j++;
    }
    if (node_temp)
    {
       newnode= malloc(sizeof(*newnode));
        if (newnode==NULL)return -2;
        newnode->data=*data;
        newnode->next=node_temp->next;
        node_temp->next=newnode;
        return 0;
    } else
        return -3;
}
int List_order_insert(list* node,datatype* data){
    list* p=node;
    list* q;
    while(p->next &&p->next->data<*data)
    {
        p=p->next;
    }
    q=malloc(sizeof(*q));
    q->data=*data;
    q->next=p->next;
    p->next=q;
}
int List_delete_at(list* node,int i,datatype* data){
    int j;
    list* p=node;
    list* q;
    *data=-1;
    if(i<0)return -1;
    while (j<i && p)
    {
        p=p->next;
        j++;
    }
    if (p)
    {
        q=p->next;
        p->next=q->next;
        *data=q->data;
        free(q);
        q=NULL;
        return 0;
    }


}
int List_delete(list* node,datatype* data){
    list* p;
    list* q;
    p=node;
    while (p->next && p->next->data!= *data)
    {
        p=p->next;
    }
    if (p->next==NULL)
        return -1;
    else
    {
        q=p->next;
        p->next=q->next;
        free(q);
        q=NULL;
    }

}
int is_empty(list* node){
    if (node->next==NULL) return 1;
    return 0;
}
void List_travel(list* node)
{
    list* node_temp=node->next;
    if (is_empty(node)==1)
        return;
    while (node_temp!=NULL)
    {
        printf("%d ",node_temp->data);
        node_temp=node_temp->next;
    }
    printf("\n");
}
void List_destory(list* node)
{
    list* node_temp;
    list* next;
    for (node_temp=node->next; node_temp != NULL; node_temp=next) {
          next=node_temp->next;
          free(node_temp);
    }
    return;
}