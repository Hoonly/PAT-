/*
1.输入时筛选出参加排名的人
2.声明4个vector放不同等级的人
3.特别要注意判断条件里的等号
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;

struct info
{
    char id[9];
    int virtue;
    int talent;
    int total_grade;
};
bool cmp(info a,info b)
{
    if(a.total_grade!=b.total_grade)//总分不同按总分递减排序
    {
        return a.total_grade>b.total_grade;
    }
    else if(a.virtue!=b.virtue)//分数相同按virtue分数递减排序
        return a.virtue>b.virtue;
    else
        return strcmp(a.id,b.id)<0;

}
int main()
{
    int N,L,H;//总人数,及格线，分级线
    scanf("%d%d%d",&N,&L,&H);

    info item;
    vector<info> sage;//圣人
    vector<info> nobleman;//君子
    vector<info> foolman;//愚人
    vector<info> other;//剩余的及格人
    for(int i=0;i<N;i++)
    {
        scanf("%s %d %d",item.id,&item.virtue,&item.talent);
        //cin>>item.id>>item.virtue>>item.talent;
        item.total_grade=item.virtue+item.talent;
        if(item.virtue>=L&&item.talent>=L)
        {
            if(item.virtue>=H&&item.talent>=H)
                sage.push_back(item);
            else if(item.virtue>=H&&item.talent<H)
                nobleman.push_back(item);
            else if(item.virtue<H&&item.talent<H&&item.virtue>=item.talent)
                foolman.push_back(item);
            else
                other.push_back(item);
        }
    }
    sort(sage.begin(),sage.end(),cmp);
    sort(nobleman.begin(),nobleman.end(),cmp);
    sort(foolman.begin(),foolman.end(),cmp);
    sort(other.begin(),other.end(),cmp);

    printf("%d\n",sage.size()+nobleman.size()+foolman.size()+other.size());
    for(int i=0;i<sage.size();i++)
        printf("%s %d %d\n",sage[i].id,sage[i].virtue,sage[i].talent);

    for(int i=0;i<nobleman.size();i++)
        printf("%s %d %d\n",nobleman[i].id,nobleman[i].virtue,nobleman[i].talent);

    for(int i=0;i<foolman.size();i++)
        printf("%s %d %d\n",foolman[i].id,foolman[i].virtue,foolman[i].talent);

    for(int i=0;i<other.size();i++)
        printf("%s %d %d\n",other[i].id,other[i].virtue,other[i].talent);


    return 0;
}
