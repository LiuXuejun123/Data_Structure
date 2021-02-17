//
// Created by liuxu on 2021/2/4.
//
#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
sqstack* st_create(void)
{   sqstack* st;
    st = malloc(sizeof(*st));
    if (st==NULL) return NULL;
    st->top=-1;
    return st;
}
int st_push(sqstack* st,datatype* data){
    if (st->top==(MaxSize-1))
        return -1;
    st->data[++st->top]=*data;

}
int st_pop(sqstack* st,datatype* data){
    if (is_empty(st))return -1;
    *data=st->data[st->top--];
    return 0;
}
int st_top(sqstack* st,datatype* data){
    if (is_empty(st))return -1;
    *data=st->data[st->top];
    return 0;
}
void st_travel(sqstack* st){
    int i;
    if (is_empty(st))return;
    for (int i=0;i<=st->top;i++)
    {
        printf("%d ",st->data[i]);
    }
    printf("\n");
}
void st_destory(sqstack* st){
    free(st);
}
int is_empty(sqstack* st){
    if (st->top==-1)return 1;
    return 0;
}