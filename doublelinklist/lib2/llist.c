//
// Created by liuxu on 2021/2/10.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"
typedef  struct llist_node{
    struct llist_node *prev;
    struct llist_node *next;
    char data[1];
}llist_node;
struct LLIST_head_st{
    int size;
    struct llist_node head;
};







LLIST* llist_create(int initsize)
{
    struct LLIST_head_st* new;
    new=malloc(sizeof(*new));
    if (new==NULL)return NULL;
    new->size=initsize;
    new->head.prev=&new->head;
    new->head.next=&new->head;

}
int llist_insert(LLIST* p,const void* data,int mode){
    llist_node* newnode;
    struct LLIST_head_st* ptr=p;
    newnode=malloc(sizeof(*newnode)+ptr->size);
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
static llist_node* find_( struct LLIST_head_st*  ptr,const void* key,llist_cmp* cmp)
{
    llist_node* cur;
    for (cur=ptr->head.next;cur != &ptr->head;cur=cur->next){
        if (cmp(key,cur->data)==0)
            break;
    }
    return cur;
}
void* llist_find(LLIST* p,const void* key,llist_cmp* cmp)
{
    struct LLIST_head_st* ptr=p;
    llist_node* node;
    node=find_(ptr,key,cmp);
    if (node==&ptr->head)
        return NULL;
    return node->data;
}

int llist_delete(LLIST* p,const void* key,llist_cmp* cmp)
{
    struct LLIST_head_st* ptr=p;
    llist_node* node;
    node=find_(ptr,key,cmp);
    if (node==&ptr->head)
        return -1;
    node->prev->next=node->next;
    node->next->prev=node->prev;
    free(node);
    return 0;
}
int llist_fetch(LLIST* p,const void* key,llist_cmp* cmp,void* data)
{
    llist_node* node;
    struct LLIST_head_st* ptr=p;
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
void llist_travel(LLIST* p,llist_op* op){
    llist_node* temp_node;
    struct LLIST_head_st* ptr=p;
    for(temp_node=ptr->head.next;temp_node != &ptr->head;temp_node = temp_node->next){
        op(temp_node->data);
    }

}
void llist_destory(LLIST* p){
    struct llist_node* cur;
    struct LLIST_head_st* ptr=p;
    for (cur = ptr->head.next;  cur != &ptr->head ;cur=cur->next) {
        free(cur);
    }
    free(ptr);
}