#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
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
int main(){
    QUEUE* sq;

    sq=qu_create(sizeof(score_st));
    if (sq==NULL)exit(1);

    score_st temp;
    for (int i = 0; i < 6; ++i) {
        temp.id=i;
        snprintf(temp.name,maxsize,"std%d",i);
        temp.math=rand()%100;
        temp.chinese=rand()%100;
        if(qu_en(sq,&temp)!=0)
            break;
    }
    while (1) {
        int ret = qu_de(sq,&temp);
        if (ret==-1)break;
        print_s(&temp);
    }

    qu_destory(sq);
    exit(0);
}
