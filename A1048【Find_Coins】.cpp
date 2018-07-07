#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
    int N;//共有N个面值的硬币
    int M;//需要组合支付的钱数
    scanf("%d %d",&N,&M);
    vector<int> v;
    int coin;
    for(int i=0;i<N;i++)
    {
        scanf("%d",&coin);
        v.push_back(coin);
    }
    sort(v.begin(),v.end());

    vector<int>::iterator p;
    for(p=v.begin();p!=v.end();p++)
    {
        if(*p>=M)
        {
            v.erase(p,v.end());
            break;
        }
    }

    int hash_table[100001]={0};
    for(int i=0;i<v.size();i++)
    {
        hash_table[v[i]]++;
    }

    bool flag=false;
    for(p=v.begin();p!=v.end();++p)
    {
        if(M-(*p)==*p)
        {
            if(hash_table[*p]>1)
            {
                flag=true;
                break;
            }

        }
        else
        {
            if(hash_table[M-(*p)]>0)
            {
                flag=true;
                break;
            }
        }
    }
    if(flag)
        printf("%d %d",*p,M-(*p));
    else
        printf("No Solution");

    return 0;
}

