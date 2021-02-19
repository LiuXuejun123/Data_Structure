//
// Created by liuxu on 2021/2/19.
//

#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H
#include "llist.h"
typedef LLIST QUEUE ;

QUEUE* qu_create(int initsize);

int qu_en(QUEUE*,const void* );

int qu_de(QUEUE*,void* );

void qu_destory(QUEUE* );

#endif //LIST_QUEUE_H
