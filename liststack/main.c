#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#define maxsize 32
typedef struct score_st
{
    int id;
    char name[maxsize];
    int math;
    int chinese;
}score_std;
static void S_print(void* record)
{
    score_std* r=record;
    printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);
}

int main()
{
    STACK* st;
    score_std tmp;
    int i;
    st=stack_create(sizeof(struct score_st));
    if (st==NULL)
    exit(1);
    for(i=0;i<7;i++)
    {
        tmp.id=i;
        snprintf(tmp.name,maxsize,"std%d",i);
        tmp.math=rand()%100;
        tmp.chinese=rand()%100;
        S_print(&tmp);
        int ret=stack_push(st,&tmp);
        if (ret)
            exit(1);
    }
    printf("\n\n");


   // S_print(p);
    while (1) {
        int ret=stack_pop(st,&tmp);
        if (ret==-1)
            break;
        S_print(&tmp);
    }
    stack_destory(st);
    exit(0);
}
