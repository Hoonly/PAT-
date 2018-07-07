/*
为了解决运行超时，不要在全部数据输入后一个节点一个节点的去相加计算距离
在输入的时候进行预处理，将每个节点到节点1的距离存储起来
a-b的距离即为|D(a-1)-D(b-1)|
*/
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int N;
    scanf("%d",&N);
    int *distance=new int[N];
    int *ans_to_1=new int[N];
    int total_distance=0;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&distance[i]);
        ans_to_1[i]=total_distance;
        total_distance+=distance[i]; 
    }

    

    int M;
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        //求最短距离
        int len1=0,len2=0;
        len1=ans_to_1[max(a,b)-1]-ans_to_1[min(a,b)-1];
        len2=total_distance-len1;
        printf("%d\n",min(len1,len2));
    }
    return 0;
}