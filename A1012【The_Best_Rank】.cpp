#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

struct info
{
    string id;
    int score[4];//score of A,C,M,E
    int r[4];//rank of A,C,M,E
    int best_rank;//最好的名次
    char best_item;//最好的名次属于哪一项成绩
};


void caculate_rank(vector<info> &all,int index_score,int index);//按照arr里面的index[分别代表C\M\E\A]成绩排名
void best_rank_method(vector<info> &all);//计算最佳排名及其所属项目

bool cmp_a(info a,info b)
{
    return a.score[0]>b.score[0];
}
bool cmp_c(info a,info b)
{
    return a.score[1]>b.score[1];
}
bool cmp_m(info a,info b)
{
    return a.score[2]>b.score[2];
}
bool cmp_e(info a,info b)
{
    return a.score[3]>b.score[3];
}

int main()
{
    int N,M;
    cin>>N>>M;

    vector<info> all;

    info item;
    for(int i=0;i<N;i++)
    {
        cin>>item.id>>item.score[1]>>item.score[2]>>item.score[3];
        item.score[0]=int(round((item.score[1]+item.score[2]+item.score[3])/3.0));
        all.push_back(item);
    }
    int size=all.size();

    if(size!=0)
    {
        //按A成绩排名
        sort(all.begin(),all.end(),cmp_a);
        caculate_rank(all,0,0);

        //按C成绩排名
        sort(all.begin(),all.end(),cmp_c);
        caculate_rank(all,1,1);

        //按M成绩排名
        sort(all.begin(),all.end(),cmp_m);
        caculate_rank(all,2,2);

        //按E成绩排名
        sort(all.begin(),all.end(),cmp_e);
        caculate_rank(all,3,3);


        best_rank_method(all);
    }



    //输出
    string s;
    for(int i=0;i<M;i++)
    {
        cin>>s;
        bool isExsit=false;
        for(int j=0;i<N;j++)
        {
            if(all[j].id==s)
            {
                cout<<all[j].best_rank<<" "<<all[j].best_item<<endl;
                isExsit=true;
                break;
            }
        }
        if(!isExsit)
            cout<<"N/A"<<endl;

    }

    return 0;

}

void caculate_rank(vector<info>& all,int index_score,int index_r)
{
    all[0].r[index_r]=1;
    for(int i=1;i<all.size();i++)
    {
        if(all[i].score[index_score]==all[i-1].score[index_score])
            all[i].r[index_r]=all[i-1].r[index_r];
        else
            all[i].r[index_r]=i+1;
    }
}

void best_rank_method(vector<info> &all)
{
    char s[4]={'A','C','M','E'};
    for(int m=0;m<all.size();m++)
    {
        int min=all[m].r[0];//假设最好排名属于A
        int flag=0;//记录最好成绩所在数组下标
        for(int i=1;i<4;i++)
        {
            if(all[m].r[i]<min)
            {
                min=all[m].r[i];
                flag=i;
            }
        }

        all[m].best_rank=min;
        all[m].best_item=s[flag];
    }

}
