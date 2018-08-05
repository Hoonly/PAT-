#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{

    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);

    for(int i=0;i<K;i++)
    {
        //把每一个出栈序列存储起来
        vector<int> v;
        for(int k=0;k<N;k++)
        {
            int number;
            scanf("%d",&number);
            v.push_back(number);
        }

        bool flag=true;
        //模拟入栈
        stack<int> s;
        int p=0;//出栈序列下标
        for(int j=1;j<=N;j++)
        {
            s.push(j);
            if(s.size()>M)//超出栈容量直接结束
            {
                flag=false;
                break;
            }
            else
            {

                while(p<v.size()&&!s.empty()&&s.top()==v[p])//如果栈不空且当前栈顶是当前出栈序列元素，出栈
                {
                    s.pop();
                    p++;
                }
            }
        }

        if(s.empty()&&flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

    return 0;


}
