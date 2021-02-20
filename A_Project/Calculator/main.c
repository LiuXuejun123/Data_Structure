#include <stdio.h>
#include <stdlib.h>
#include "sqstack.h"
static int get_pri(datatype op)
{
    switch (op) {
        case '(':return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
}

static void compute(sqstack* snum,datatype* op)
{   datatype n1,n2,n;
    st_pop(snum,&n2);
    st_pop(snum,&n1);
    switch (*op) {
    case '+': n=n1+n2;
    break;
    case '-':n=n1-n2;
    break;
    case '*':n=n1*n2;
    break;
    case '/':n=n1/n2;
    break;
    default:
        exit(1);
    }
    st_push(snum,&n);
}

static void deal_bracket(sqstack* snum,sqstack* sop)
{
    datatype old_op;
    st_top(sop,&old_op);
   while (old_op != '('){
       st_pop(sop,&old_op);
       compute(snum,&old_op);
       st_top(sop,&old_op);
   }
}
static void deal_op(sqstack* snum,sqstack* sop,int op)
{
    datatype old_op;
    if (is_empty(sop)||op=='(')
    {
        st_push(sop,&op);
        return;
    }
    st_top(sop,&old_op);
    if (get_pri(op) > get_pri(old_op))
    {
        st_push(sop,&op);
    }
    while(get_pri(op)<=get_pri(old_op))
    {
        st_pop(sop,&old_op);
        compute(snum,&old_op);
        if (is_empty(sop))
        {
            break;
        }
        st_top(sop,&old_op);
    }
    st_push(sop,op);
}

int main() {
    int i=0;
    int value=0;
    int flag=0;
    char str[]="(11+3)*2-5";
    sqstack* snum;
    sqstack* sop;
    datatype op;
    snum=st_create();
    if (snum==NULL)exit(1);
    sop=st_create();
    if (sop==NULL)exit(1);

    while (str[i] != '\0')
    {
        if (str[i]>'0'&& str[i]<'9'){
            value=value*10+(str[i]-'0');
            flag=1;
        }
        else{
            if (flag)
            {
                st_push(snum,&value);
                flag=0;
                value=0;
            }
            if (str[i]==')'){
                deal_bracket(snum,sop);
            }
            else{
                deal_op(snum,sop);
            }
        }
        i++;
    }

    if (flag)
    {
        st_push(snum,&value);
    }
    while (!is_empty(sop))
    {
        st_pop(sop,&op);
        compute(snum,&op);
    }
    st_destory(snum);
    st_destory(sop);
    printf("Hello, World!\n");
    return 0;
}
