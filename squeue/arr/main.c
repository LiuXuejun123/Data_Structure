#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main() {
    queue* sq;
    datatype arr[]={1,2,3,4,5};
    sq=qu_create();
    for (int i = 0; i <sizeof(arr)/sizeof(*arr) ; ++i) {
        qu_enqueue(sq,&arr[i]);
    }
    qu_travel(sq);
    datatype tmp;
    qu_dequeue(sq,&tmp);
    printf("%d",tmp);

//    int ret=qu_enqueue(sq,&tmp);
//    if(ret)printf("queue is full");
//    else
//    qu_travel(sq);
//    qu_destory(sq);
    exit(0);
}
