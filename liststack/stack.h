//
// Created by liuxu on 2021/2/17.
//

#ifndef LISTSTACK_STACK_H
#define LISTSTACK_STACK_H
#include "llist.h"
typedef LLIST STACK;
STACK* stack_create();
int stack_push(STACK* ,const void* data);
int stack_pop(STACK*,void* data);
void stack_destory(STACK* );




#endif //LISTSTACK_STACK_H
