#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int seq[100001];
    int count[100001];
    int num;
    int i=0;
    while(scanf("%d",&num)!=EOF)
    {
        seq[i]=num;
        count[num]++;
        i++;
    }
    bool flag=false;
    int j;
    for(j=0;j<N;j++)
    {
        if(count[seq[j]]==1)
        {
            flag=true;
            break;
        }
    }
    if(flag)
        printf("%d",seq[j]);
    else
        printf("None");

    return 0;

}

