//
// Created by liuxu on 2021/2/5.
//

  #ifndef SINGLELIST_LIST_H
#define SINGLELIST_LIST_H
typedef int datatype ;
typedef struct node_st
{
    datatype data;
    struct node_st* next;
}list;
list* List_create();
int List_insert_at(list*,int i,datatype*);
int List_order_insert(list*,datatype*);
int List_delete_at(list*,int i,datatype*);
int List_delete(list*,datatype*);
int is_empty(list*);
void List_travel(list*);
void List_destory(list*);


#endif //SINGLELIST_LIST_H
