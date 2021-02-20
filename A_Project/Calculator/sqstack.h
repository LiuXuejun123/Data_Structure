//
// Created by liuxu on 2021/2/4.
//

#ifndef SQSTRACK_SQSTACK_H
#define SQSTRACK_SQSTACK_H
#define MaxSize 5
typedef int datatype ;
typedef struct node_st
{
    datatype data[MaxSize];
    int top;
}sqstack;
sqstack* st_create(void);
int st_push(sqstack*,datatype*);
int st_pop(sqstack*,datatype*);
int st_top(sqstack*,datatype*);
void st_travel(sqstack*);
void st_destory(sqstack*);
int is_empty(sqstack*);



#endif //SQSTRACK_SQSTACK_H
