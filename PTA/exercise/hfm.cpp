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
void CreateHuffman_tree(HuffmanTree& Ht, int n)/*建立哈夫曼树*/
{
    int i, m, s1, s2;
    if (n <= 1) return;
    m = 2 * n - 1;
    Ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));

    for (i = 1;i <= m;i++) {
        Ht[i].parent = 0;
        Ht[i].lchild = 0;
        Ht[i].rchild = 0;
    }
    //printf("输入n个叶子结点权值:\n");
    for (i = 1;i <= n;i++)
        scanf("%d", &Ht[i].weight);
    for (i = n + 1;i <= m;i++) {
        Select(Ht, i - 1, s1, s2);
        Ht[s1].parent = i;  Ht[s2].parent = i;
        Ht[i].lchild = s1;  Ht[i].rchild = s2;
        Ht[i].weight = Ht[s1].weight + Ht[s2].weight;
    }
}/*Huffman_tree*/
void Huffman_code(HuffmanTree HT, HuffmanCode& HC, int n)/*哈夫曼树编码*/
{
    if (n <= 1) return;
    HC = new char* [n + 1];
    int i, start, c, f;
    char cd[n];
    cd[n - 1] = '\0';
    for (i = 1;i <= n;i++) {
        start = n - 1;
        c = i;
        f = HT[i].parent;
        while (f != 0) {
            if (HT[f].lchild == c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n - start];
        strcpy(HC[i], &cd[start]);
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
        printf("编码是： %s\n",HC[i]);
    return 0;
}

