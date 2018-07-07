#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

struct student
{
    int ID;
    char name[8];
    int grade;
};
bool cmp_ID(student a,student b)
{
    return a.ID<b.ID;
}
bool cmp_name(student a,student b)
{
    if(strcmp(a.name,b.name)!=0)
        return strcmp(a.name,b.name)<0;
    else
        return a.ID<b.ID;
}
bool cmp_grade(student a,student b)
{
    if(a.grade!=b.grade)
        return a.grade<b.grade;
    else
        return a.ID<b.ID;
}

int main()
{
    int N,C;
    scanf("%d %d",&N,&C);

    vector<student> record;
    for(int i=0;i<N;i++)
    {
        student tmp;
        scanf("%d %s %d",&tmp.ID,tmp.name,&tmp.grade);
        record.push_back(tmp);
    }

    switch (C)
    {
    case 1:
        sort(record.begin(),record.end(),cmp_ID);
        break;
    case 2:
        sort(record.begin(),record.end(),cmp_name);
        break;
    case 3:
        sort(record.begin(),record.end(),cmp_grade);
        break;
    default:
        break;
    }

    for(int i=0;i<N;i++)
    {
        student tmp=record[i];
        printf("%06d %s %d\n",tmp.ID,tmp.name,tmp.grade);
    }

    return 0;





}
