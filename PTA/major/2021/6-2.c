#include <stdio.h>
#define N 50

//输出数组中的最大值，最小值，平均值
void  dispMaxMinAvg(double dDistance[],int n);
//对已经升序排列后的数组，返回中位数
double getMedian(double dDistance[],int n);
 
int main()
{
    int n,i,j; //n表示输入多少个数据 
    double dDis[N]={0},temp;//数组最多50个元素，先初始化为0 
    
    //输入数据 
    scanf("%d",&n);  
    for(i=0;i<n;i++)
        scanf("%lf",&dDis[i]);
    
    //调用函数，打印距离的最大值，最小值，平均值 
    dispMaxMinAvg(dDis,n);
    
    //在求中位数之前，对数组进行排序 
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(dDis[i]>dDis[j])
            {
                temp=dDis[i];
                dDis[i]=dDis[j];
                dDis[j]=temp;
            }
    
    //对已经升序排列的数组，调用函数得到中位数 
    printf("Median=%.2f"  ,getMedian(dDis,n) );
    return 0;
}

//输出数组中的最大值，最小值，平均值
void  dispMaxMinAvg(double dDistance[],int n)
{
    float max = 0,min=dDistance[0],aver=0;
    for(int i=0;i<n;i++)
    {
        if(max<dDistance[i])
            max=dDistance[i];
        if(min>dDistance[i])
            min=dDistance[i];
        aver+=dDistance[i];
    }
    printf("Max=%.2f,Min=%.2f,Avg=%.2f\n",max,min,aver/n);
}
//对已经升序排列后的数组，返回中位数
double getMedian(double dDistance[],int n)
{
    if(n%2!=0)
        return dDistance[n/2];
    else
        return (dDistance[n/2]+dDistance[n/2-1])/2;
}
