//二叉搜索树的操作集
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT )
{    
    BinTree p = BT;
    if(!p) return;
    printf(" %d",p->Data);
    PreorderTraversal(p->Left);
    PreorderTraversal(p->Right);
}
void InorderTraversal(BinTree BT)
{
    BinTree p = BT;
    if (!p)
        return;
    InorderTraversal(p->Left);
    printf("%d ", p->Data);
    InorderTraversal(p->Right);
}

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); 
    PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
BinTree Insert( BinTree BST, ElementType X )
{
    if(!BST)
    {
        BST = (BinTree)malloc(sizeof(struct TNode));//既然为空所以要生成一个
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else{//一般情况
        if(X < BST->Data){//插入值小于节点，应该往左子树中找位置
            BST->Left = Insert(BST->Left,X);//递归插入左子树
        }
        else if(X > BST->Data){//插入值大于节点，应该往右子树中找
            BST->Right = Insert(BST->Right,X);//递归插入右子树
        }
        //如果相等说明X已经存在，什么也不做
    }
    return BST;

}

BinTree Delete( BinTree BST, ElementType X ){
    Position temp;
    if(!BST){
        printf("Not Found\n");//如果最终树为空，说明没有
    }
    else{//这里类似于插入重点在于找到后怎么办
        if(X < BST->Data){
            BST->Left = Delete(BST->Left,X);//从左子树递归删除
        }
        else if(X > BST->Data){
            BST->Right = Delete(BST->Right,X);//从右子树递归删除
        }
        else{//当前BST就是要删除的节点
              if(BST->Left && BST->Right){//要被删除的节点有左右两个孩子，就从右子树中找最小的数填充删除的节点
                temp = FindMin(BST->Right);//找最小
                BST->Data = temp->Data;//填充删除的节点
                BST->Right = Delete(BST->Right,temp->Data);//删除拿来填充的那个节点
              }
              else{//只有一个子节点
                temp = BST;
                if(!BST->Left){//只有右节点
                    BST = BST->Right;//直接赋值就可以
                }
                else if(!BST->Right){//只有左节点
                    BST = BST->Left;//直接赋值就可以
                }
                free(temp);//如果啥也没有直接删除就可以，当然上面两种情况赋值后也要删除
              }
        }
    }
    return BST;
}
Position Find( BinTree BST, ElementType X )
{
    while(BST)
    {
        if(BST->Data==X)
            return BST;
        else if(BST->Data>X)
            BST=BST->Left;
        else if(BST->Data<X)
            BST=BST->Right;
    }
    return NULL;
}
Position FindMin( BinTree BST )
{
    if(!BST)
        return NULL;
    if(BST->Left==NULL)
        return BST;
    FindMin(BST->Left);
}
Position FindMax( BinTree BST )
{
    if(!BST)
        return NULL;
    if(BST->Right==NULL)
        return BST;
    FindMax(BST->Right);
}