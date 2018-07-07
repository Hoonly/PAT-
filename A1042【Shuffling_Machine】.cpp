#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
    string card[54]={"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
                    "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
                    "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
                    "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
                    "J1","J2"};
    int K;//重复洗牌次数
    cin>>K;
    int order[54];//洗牌顺序
    for(int i=0;i<54;i++)
        cin>>order[i];
    string tmp[54];//存放每一次移动的结果
    for(int i=0;i<K;i++)
    {
        for(int j=0;j<54;j++)//放到tmp中
        {
            tmp[order[j]-1]=card[j];
        }
        for(int k=0;k<54;k++)//重写card
        {
            card[k]=tmp[k];
        }
    }
    for(int i=0;i<54;i++)
    {
        cout<<card[i]<<" ";
    }

    return 0;

}