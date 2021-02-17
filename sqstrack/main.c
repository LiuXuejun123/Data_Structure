#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
int main() {
    sqstack* st;
    int i;
    datatype arr[]={19,29,0,39,49};
    st=st_create();
    if (st==NULL)exit(1);
    for (i = 0; i <sizeof(arr)/sizeof(*arr) ; ++i) {
        st_push(st,&arr[i]);
    }
    st_travel(st);
    datatype temp;
    while (st_pop(st,&temp)==0)
    {
        printf("POP:%d ",temp);
    }

    st_destory(st);
    exit(0);
}
