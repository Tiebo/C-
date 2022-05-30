//四种遍历
#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree()
{
    BinTree T = (BinTree)malloc(sizeof(TNode));
    T->Data = 'A';
    T->Left = NULL;
    T->Right = NULL;
    BinTree A = T;
    BinTree B = (BinTree)malloc(sizeof(TNode));
    B->Data = 'B';
    A->Left = B;
    BinTree C = (BinTree)malloc(sizeof(TNode));
    C->Data = 'C';
    A->Right = C;
    BinTree D = (BinTree)malloc(sizeof(TNode));
    D->Data = 'D';
    B->Left = D;
    D->Left = NULL;
    D->Right = NULL;
    BinTree F = (BinTree)malloc(sizeof(TNode));
    F->Data = 'F';
    B->Right = F;
    F->Right = NULL;
    BinTree G = (BinTree)malloc(sizeof(TNode));
    G->Data = 'G';
    C->Left = G;
    G->Left = NULL;
    BinTree I = (BinTree)malloc(sizeof(TNode));
    I->Data = 'I';
    C->Right = I;
    I->Left = NULL;
    I->Right = NULL;
    BinTree E = (BinTree)malloc(sizeof(TNode));
    E->Data = 'E';
    E->Left = NULL;
    E->Right = NULL;
    F->Left = E;
    BinTree H = (BinTree)malloc(sizeof(TNode));
    H->Data = 'H';
    H->Left = NULL;
    H->Right = NULL;
    G->Right = H;

    return T;
}
/* 实现细节忽略 */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void LevelorderTraversal(BinTree BT);

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    printf("Levelorder:");
    LevelorderTraversal(BT);
    printf("\n");
    return 0;
}
void InorderTraversal(BinTree BT)
{
    BinTree p = BT;
    if (!p)
        return;
    InorderTraversal(p->Left);
    printf("%c ", p->Data);
    InorderTraversal(p->Right);
}
void PreorderTraversal(BinTree BT)
{
    BinTree p = BT;
    if (!p)
        return;
    printf("%c ", p->Data);
    PreorderTraversal(p->Left);
    PreorderTraversal(p->Right);
}
void PostorderTraversal(BinTree BT)
{
    BinTree p = BT;
    if (!p)
        return;
    PostorderTraversal(p->Left);
    PostorderTraversal(p->Right);
    printf("%c ", p->Data);
}
void LevelorderTraversal(BinTree BT)
{
    BinTree a[100];
    int base = 0, top = -1;
    BinTree p = BT;
    if (!p)
        return;
    a[++top] = p;
    while (top + 1 != base)
    {
        p=a[base];
        printf("%c ", a[base++]->Data);
        if (p->Left)
        {
            a[++top] = p->Left;
        }
        if (p->Right)
        {
            a[++top] = p->Right;
        }
    }
}
