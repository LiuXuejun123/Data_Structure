//
// Created by liuxu on 2021/2/10.
//

#ifndef LIB1_LLIST_H
#define LIB1_LLIST_H
#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2
typedef void LLIST ;
typedef void llist_op(const void*);
typedef int llist_cmp(const void*,const void*);
LLIST* llist_create(int initsize);
int llist_insert(LLIST* ,const void* data,int mode);
void* llist_find(LLIST*,const void* key,llist_cmp *);
int llist_delete(LLIST*,const void* key,llist_cmp* );
int llist_fetch(LLIST*,const void* key,llist_cmp* ,void* data);
void llist_travel(LLIST*,llist_op*);
void llist_destory(LLIST*);

#endif //LIB1_LLIST_H
