 #include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main() {

    list* l;
    l=List_create();
    datatype arr[]={12,3,123,24,2,34,54};
    int i=0;

    if (l==NULL)
        exit(1);

    for (i = 0; i < sizeof(arr)/sizeof(*arr); ++i) {
        List_order_insert(l,&arr[i]);
    }

    List_travel(l);
    datatype value;
    List_delete_at(l,1,&value);
    List_travel(l);
    printf("%d",value);
    List_destory(l);
}
