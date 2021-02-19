//
// Created by liuxu on 2021/2/19.
//
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
queue* qu_create()
{
    queue* sq;
    sq = malloc(sizeof(*sq));
    if (sq==NULL)
        return NULL;

    sq->head=0;
    sq->tail=0;

    return sq;
}

int qu_isempty(queue* sq)
{
    return sq->head==sq->tail;
}

int qu_enqueue(queue* sq,datatype* data)
{
   if ((sq->tail+1)%maxsize==sq->head)
       return -1;

      sq->tail = (sq->tail+1)%maxsize;
      sq->data[sq->tail]=*data;

    return 0;
}

int qu_dequeue(queue* sq,datatype* data)
{
    if(qu_isempty(sq))
        return -1;
    sq->head =(sq->head+1)%maxsize;
    *data=sq->data[sq->head];


    return 0;
}

void qu_travel(queue* sq)
{
    if (sq->head == sq->tail)
        return;
    int i=(sq->head+1)%maxsize;
    while (i != sq->tail)
    {
        printf("%d ",sq->data[i]);
        i=(i+1)%maxsize;
    }
    printf("%d \n",sq->data[i]);

}

void qu_clear(queue* sq)
{
    sq->head=sq->tail;
}

void qu_destory(queue* sq)
{
    free(sq);
}