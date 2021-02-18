#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include <string.h>
#define maxsize 32
typedef struct score_st
{
    int id;
    char name[maxsize];
    int math;
    int chinese;
}score_st;
static void print_s(const void* record)
{
    const score_st* r=record;
    printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);
}
static int id_cmp(const void* key,const void* record)
{
    const int* k=key;
    const struct score_st* r=record;
    return *k-r->id;
}
static int name_cmp(const void* key,const void* record)
{
    const char* k=key;
    const struct score_st* r=record;
   return strcmp(k,r->name);
}


int main() {
    LLIST* handler;
    score_st tmp;
    int i;
    handler=llist_create(sizeof(score_st));
    if (handler==NULL)exit(1);
    for(i=0;i<7;i++)
    {
        tmp.id=i;
        snprintf(tmp.name,maxsize,"std%d",i);
        tmp.math=rand()%100;
        tmp.chinese=rand()%100;
        int ret=llist_insert(handler,&tmp,LLIST_BACKWARD);
        if (ret)
            exit(1);
    }
    llist_travel(handler,print_s);
    printf("\n\n");





    int id=3;
    int ret;
    char *del_name ="std4";

    ret=llist_delete(handler,del_name,name_cmp);
if (ret)
    printf("list delete failed\n");

    llist_travel(handler,print_s);
    llist_destory(handler);
    exit(0);
}
