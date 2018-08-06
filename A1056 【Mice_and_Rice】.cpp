#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct info
{
    int weight;//体重
    int m_rank;//排名
};
int main()
{
    int NP,NG;
    scanf("%d %d",&NP,&NG);



    vector<info> v;
    for(int i=0;i<NP;i++)
    {
        info tmp;
        scanf("%d",&tmp.weight);
        v.push_back(tmp);

    }

    queue<int> oder;//存放比赛顺序
    for(int i=0;i<NP;i++)
    {
        int number;
        scanf("%d",&number);
        oder.push(number);
    }



    while(oder.size()!=1)
    {
        int group=(NP%NG==0)?(NP/NG):(NP/NG+1);//每一轮的分组数

        for(int i=0;i<group;i++)
        {
            int max=oder.front();//记录质量最大的老鼠编号
            for(int j=0;j<NG;j++)//每一组有NG个老鼠，选出质量最大的重新入队，其他的直接排名为group+1并出队
            {
                if(i*NG+j>=NP) break;
                int id=oder.front();
                if(v[id].weight>v[max].weight)
                {
                    max=id;
                }
                v[id].m_rank=group+1;
                oder.pop();
            }
            oder.push(max);

        }
        NP=group;//下一轮的选手总数
    }
    //最后队列只剩下以只老鼠，其他的均已排好名，它的排名为1
    v[oder.front()].m_rank=1;


    for(int i=0;i<v.size();i++)
    {
        printf("%d",v[i].m_rank);
        if(i!=v.size()-1)
            printf(" ");
    }



    return 0;


}



