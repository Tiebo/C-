#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct hnode
{
    int weight;
    int lchild, rchild, parent;
}HTNode, * HuffmanTree;/*定义二叉树的存储结点*/
typedef char** HuffmanCode;
void Select(HTNode HT[], int len, int& s1, int& s2)
{
    int i, min1 = 32767, min2 = 32767;
    for (i = 1;i <= len;i++) {
        if (HT[i].weight < min1 && HT[i].parent == 0) {
            s2 = s1;
            min2 = min1;
            min1 = HT[i].weight;
            s1 = i;
        } else if (HT[i].weight < min2 && HT[i].parent == 0) {
            min2 = HT[i].weight;
            s2 = i;
        }
    }
}
void CreateHuffman_tree(HuffmanTree &HT,int n)
{
    int s1,s2,i;
    if(n<=1) return;
    int m = 2*n-1;
    HT = (HTNode*)malloc((m+1)*sizeof(HTNode));
    for(i=1;i<=m;i++)
    {
        HT[i].lchild=0;
        HT[i].rchild=0;
        HT[i].parent=0;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&HT[i].weight);
    }
    for(i=n+1;i<=m;i++)
    {
        Select(HT,i-1,s1,s2);
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}
void Huffman_code(HuffmanTree HT,HuffmanCode &HC,int n)
{
    if(n<=1)
        return ;
    HC = (char**)malloc((n+1)*sizeof(char));
    int i,begin,m,f;
    char cd[n];//s中不能直接使用cd[n]，数组大小为n
    cd[n-1] = '\0';
    for(i=1;i<=n;i++)
    {
        begin = n-1;
        m = i;
        f = HT[i].parent;
        while(f!=0)
        {
            begin--;
            if(HT[f].lchild==m)
                cd[begin] = '0';//0和1要加单引号
            else
                cd[begin]= '1';
            m = f;
            f = HT[f].parent;
        }
        HC[i] = (char*)malloc((n-begin)*sizeof(char));
        strcpy(HC[i],&cd[begin]);
    }
}

int main()
{
    HuffmanTree HT;
    HuffmanCode HC;
    int i, n;
    scanf("%d", &n);
    CreateHuffman_tree(HT, n);/*建立哈夫曼树*/
    Huffman_code(HT, HC, n);/*哈夫曼树编码*/
    for (i = 1;i <= n;i++)/*输出字符、权值及编码*/
        printf("编码是：  %s\n",HC[i]);
    return 0;
}

