#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<functional>
using namespace std;
struct pepole
{
    char name[9];
    int age;
    int worth;


};

bool cmp(pepole a,pepole b)
{
    if(a.worth!=b.worth)
        return a.worth>b.worth;
    else if(a.age!=b.age)
        return a.age<b.age;
    else
        return strcmp(a.name,b.name)<0;
}
int main()
{
    int N,K;
    scanf("%d %d",&N,&K);

    vector<pepole> record;
    for(int i=0;i<N;i++)
    {
        pepole tmp;
        scanf("%s %d %d",tmp.name,&tmp.age,&tmp.worth);
        record.push_back(tmp);
    }
    sort(record.begin(),record.end(),cmp);

    vector<pepole> divide;//每个年龄前100个富人
    int ageCount[200]={0};
    for(int i=0;i<record.size();i++)
    {
        int age=record[i].age;
        if(ageCount[age]<100)
        {
            divide.push_back(record[i]);
            ageCount[age]++;
        }
    }



    int M,Amin,Amax;
    for(int i=0;i<K;i++)
    {
        scanf("%d %d %d",&M,&Amin,&Amax);
        int count=0;//统计输出的人数

        printf("Case #%d:\n",i+1);
        for(int j=0;j<divide.size();j++)
        {
            if(divide[j].age>=Amin&&divide[j].age<=Amax)
            {
                 printf("%s %d %d\n",divide[j].name,divide[j].age,divide[j].worth);
                 count++;
            }
            if(count==M)
                break;
        }
        if(count==0)
            printf("None\n");
    }

    return 0;
}
