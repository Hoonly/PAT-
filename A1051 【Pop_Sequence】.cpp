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
        //��ÿһ����ջ���д洢����
        vector<int> v;
        for(int k=0;k<N;k++)
        {
            int number;
            scanf("%d",&number);
            v.push_back(number);
        }

        bool flag=true;
        //ģ����ջ
        stack<int> s;
        int p=0;//��ջ�����±�
        for(int j=1;j<=N;j++)
        {
            s.push(j);
            if(s.size()>M)//����ջ����ֱ�ӽ���
            {
                flag=false;
                break;
            }
            else
            {

                while(p<v.size()&&!s.empty()&&s.top()==v[p])//���ջ�����ҵ�ǰջ���ǵ�ǰ��ջ����Ԫ�أ���ջ
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
