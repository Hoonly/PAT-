//我一开始就用了二分查找但是倒数第二个case一直是超时，后来不知道怎么想到把vector设置成全局变量，参数去掉v试一下，结果就不超时了
//后来突然想到search参数v是按值传递的，数据量大的时候拷贝耗时，改成传引用就可以了，em....记住了
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int search(int left,int right,vector<long int> &v,long int s)
{
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(v[mid]>s)
            right=mid;
        else
            left=mid+1;
    }
    return left;
}
int main()
{
    int N;//共有多少数<=10^5
    int p;//<=10^9
    scanf("%d %d",&N,&p);
    vector<long int> v;
    for(int i=0;i<N;i++)
    {
        long int val;
        scanf("%ld",&val);
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    int max=0;
    int index=0;
    for(int i=0;i<N;i++)
    {
        long int s=v[i]*p;
        index=search(index,N,v,s);//每次二分查找的区间设置为[上一次找到的最长序列M的位置,N]
        int total=index-i;
        if(total>max)
            max=total;
        if(N-i<max)//如果剩下的数比前边找到的最长序列的长度还短，不需要遍历了
            break;
    }
    printf("%d",max);
    return 0;
}
