//
// Created by liuxu on 2021/2/19.
//

#include "queue.h"
QUEUE* qu_create(int initsize)
{
    return llist_create(initsize);
}
int qu_en(QUEUE* ptr,const void* data)
{
    return llist_insert(ptr,data,LLIST_BACKWARD);
}
static int  cmp(const void* p1,const void* p2)
{
    return 0;
}

int qu_de(QUEUE* ptr,void* data)
{
    return llist_fetch(ptr,(void*)0,cmp,data);
}


void qu_destory(QUEUE* ptr)
{
    llist_destory(ptr);
}