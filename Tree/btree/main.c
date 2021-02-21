#include <stdio.h>
#include <stdlib.h>
#define maxsize 32
typedef struct score_st
{
    int id;
    char name[maxsize];
    int math;
    int chinese;
}score_st;
struct node_st{
    score_st data;
    struct node_st *l,*r;
};
int tree_insert(struct node_st **root,score_st* data)
{   struct node_st* node;
if (*root==NULL)
{
    node=malloc(sizeof(*node));
    if(node==NULL)return -1;
    node->data=*data;
    node->l=NULL;
    node->r=NULL;

    *root=node;
    return 0;
}
if (data->id<=(*root)->data.id)
    tree_insert(&(*root)->l,data);
else
    tree_insert(&(*root)->r,data);
}
score_st* tree_find(struct node_st *root,int id)
{
    if (root==NULL)
        return NULL;
    if (id==root->data.id)
        return &root->data;
    if (id<root->data.id)
        return tree_find(root->l,id);
    else
        return tree_find(root->r,id);

}
void print_s(score_st* r)
{
    printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);
}
void tree_draw(struct  node_st* root,int level)
{
    if (root == NULL)return;
    tree_draw(root->r,level+1);
    for (int i = 0; i < level; ++i) {
        printf("   ");
    }
    print_s(&root->data);
    tree_draw(root->l,level+1);
}
void draw(struct node_st *root)
{
    tree_draw(root,0);
}
tree_blance(struct node_st **root)
{

}
int main() {
    int arr[]={1,2,3,7,6,5,9,8,4};
    struct node_st *tree=NULL;
    score_st temp;
    score_st* datap;
    int i;
    for(i=0;i<sizeof(arr)/sizeof(*arr);i++)
    {
        temp.id=arr[i];
        snprintf(temp.name,maxsize,"std%d",arr[i]);
        temp.math=rand()%100;
        temp.chinese=rand()%100;
        tree_insert(&tree,&temp);//小数左边大数右边
    }
    draw(tree);
    tree_blance(&tree);

//    int tmpid=2;
//    datap =tree_find(tree,tmpid);
//    if (datap==NULL)
//        printf("Can not find the id %d\n",tmpid);
//    else
//        print_s(datap);

    exit(0);
}
