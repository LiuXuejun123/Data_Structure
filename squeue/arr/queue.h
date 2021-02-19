//
// Created by liuxu on 2021/2/19.
//

#ifndef ARR_QUEUE_H
#define ARR_QUEUE_H
#define maxsize 5
typedef int datatype ;
typedef struct node_st{
    datatype data[maxsize];
    int head,tail;
}queue;
queue* qu_create();

int qu_isempty(queue*);

int qu_enqueue(queue*,datatype*);

int qu_dequeue(queue*,datatype*);

void qu_travel(queue*);

void qu_clear(queue*);

void qu_destory(queue*);

#endif //ARR_QUEUE_H
