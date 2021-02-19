//
// Created by liuxu on 2021/2/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"
LLIST* llist_create(int initsize)
{
    LLIST* new;
    new=malloc(sizeof(*new));
    if (new==NULL)return NULL;
    new->size=initsize;
    new->head.prev=&new->head;
    new->head.next=&new->head;

}
int llist_insert(LLIST* ptr,const void* data,int mode){
    llist_node* newnode;

    newnode=malloc(sizeof(*newnode) + ptr->size);
    if (newnode==NULL)return -1;

    memcpy(newnode->data,data,ptr->size);
    if (mode == LLIST_FORWARD){
        newnode->prev=&ptr->head;
        newnode->next=ptr->head.next;
        newnode->prev->next=newnode;
        newnode->next->prev=newnode;
    }
    else if (mode == LLIST_BACKWARD){
        newnode->prev=ptr->head.prev;
        newnode->next=&ptr->head;
        newnode->prev->next=newnode;
        newnode->next->prev=newnode;
    }
    else
    {
        return -3;
    }
    return 0;
}
static llist_node* find_(LLIST* ptr,const void* key,llist_cmp* cmp)
{
    llist_node* cur;
    for (cur=ptr->head.next;cur != &ptr->head;cur=cur->next){
        if (cmp(key,cur->data)==0)
            break;
    }
    return cur;
}
void* llist_find(LLIST* ptr,const void* key,llist_cmp* cmp)
{
    llist_node* node;
    node=find_(ptr,key,cmp);
    if (node==&ptr->head)
        return NULL;
    return node->data;
}

int llist_delete(LLIST* ptr,const void* key,llist_cmp* cmp)
{
    llist_node* node;
    node=find_(ptr,key,cmp);
    if (node==&ptr->head)
        return -1;
    node->prev->next=node->next;
    node->next->prev=node->prev;
    free(node);
    return 0;
}
int llist_fetch(LLIST* ptr,const void* key,llist_cmp* cmp,void* data)
{
    llist_node* node;
    node=find_(ptr,key,cmp);
    if (node==&ptr->head)
        return -1;
    node->prev->next=node->next;
    node->next->prev=node->prev;
    if (data!=NULL)
        memcpy(data,node->data,ptr->size);
    free(node);
    return 0;
}
void llist_travel(LLIST* ptr,llist_op* op){
  llist_node* temp_node;
  for(temp_node=ptr->head.next;temp_node != &ptr->head;temp_node = temp_node->next)
  {
      op(temp_node->data);
  }

}
void llist_destory(LLIST* ptr){
    struct llist_node* cur;
    struct llist_node* next;
    for (cur = ptr->head.next;  cur != &ptr->head ;cur=next) {
        next = cur->next;
        free(cur);
    }
    free(ptr);
}