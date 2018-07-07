#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
using namespace std;

struct personal
{
    int score[6];//每道题的得分情况，-1代表未通过编译，-2代表未提交（注意先全部初始化为-2）
    int total_score;//总分
    int perfectly_solved;//拿满分的题目数
    bool flag;//标记是否有通过编译的题，没有的话不记录在最终排名
};


struct handle
{
    int rank;
    int user_id;
    int score[6];//每道题的得分情况，-1代表未通过编译，-2代表未提交（注意先全部初始化为-2）
    int total_score;//总分
    int perfectly_solved;//拿满分的题目数
};

bool cmp(handle a,handle b)
{
    if(a.total_score!=b.total_score)
        return a.total_score>b.total_score;
    else if(a.perfectly_solved!=b.perfectly_solved)
        return a.perfectly_solved>b.perfectly_solved;
    else
        return a.user_id<b.user_id;
}

int main()
{
    int N;//总的用户数
    int K;//总的题数
    int M;//总的提交数
    scanf("%d%d%d",&N,&K,&M);

    int full_mark[6]={0};//存放每道题的分值，总共不超过5道题

    for(int i=1;i<=K;i++)
    {
        scanf("%d",&full_mark[i]);
    }

    map<int,personal> m;//学号-提交情况映射

    //输入M条提交记录
    for(int i=0;i<M;i++)
    {
        int user_id,problem_id,part_score;
        scanf("%d %d %d",&user_id,&problem_id,&part_score);
        if(m.count(user_id)==0)//如果这个用户还没有提交记录
        {
            personal p;
            //memset(p.score,-2,sizeof(p.score));
            fill(p.score,p.score+6,-2);
            p.score[problem_id]=part_score;
            p.flag=false;//每个用户首次提交题目的时候先把flag设为false
            if(part_score!=-1)//只要有通过编译的，就把flag置true
                p.flag=true;
            pair<int,personal> pa;
            pa.first=user_id;
            pa.second=p;
            m.insert(pa);
        }
        else
        {
            if(part_score!=-1)
                m[user_id].flag=true;
            //同一个题目多次提交取最高分
            int prev=m[user_id].score[problem_id];
            if(part_score>prev)
                m[user_id].score[problem_id]=part_score;
        }
    }

    //把所有提交没有一个过编译的删掉
    for(int i=1;i<N;i++)
    {
        if(m.count(i))
        {
            if(!m[i].flag)
            {
                map<int,personal>::iterator it=m.find(i);
                m.erase(it);
            }
        }
    }


    vector<handle> v;
    for(map<int,personal>::iterator i=m.begin();i!=m.end();++i)
    {
        handle h;
        h.perfectly_solved=0;
        h.total_score=0;
        h.user_id=i->first;
        for(int j=0;j<6;j++)
        {
            h.score[j]=i->second.score[j];
            if(h.score[j]==full_mark[j])
                h.perfectly_solved++;
        }
        for(int j=1;j<=K;j++)
        {
            if(h.score[j]>=0)
                h.total_score+=h.score[j];
        }
        v.push_back(h);
    }
    sort(v.begin(),v.end(),cmp);



    v[0].rank=1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].total_score==v[i-1].total_score)
            v[i].rank=v[i-1].rank;
        else
            v[i].rank=i+1;
    }
    for(int i=0;i<v.size();i++)
    {
        printf("%d %05d %d ",v[i].rank,v[i].user_id,v[i].total_score);
        for(int j=1;j<=K;j++)
        {
            if(v[i].score[j]==-1)
                printf("0");
            else if(v[i].score[j]==-2)
                printf("-");
            else
                printf("%d",v[i].score[j]);
            if(j!=K)
                printf(" ");
        }
        if(i!=v.size())
            printf("\n");
    }






    return 0;





}

