/*
tips:进制转换不要存放到字符串，存到int数组里,因为可能出现余数是多位数的情况
*/
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<int> base_trans(int N,int base);//将N转为base进制的字符串
int main()
{

    int N,base;
    cin>>N>>base;
    if(N==0)
    {
        cout<<"Yes"<<endl;
        cout<<0;
    }
    else
    {
        bool flag=true;
        vector<int> a=base_trans(N,base);//进制转换
        vector<int> b=base_trans(N,base);
        reverse(b.begin(),b.end());
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        for(int i=0;i<a.size();i++)
        {
            cout<<a[i];
            if(i!=a.size()-1)
                cout<<" ";
        }
    }


    return 0;

}

vector<int> base_trans(int N,int base)
{
    vector<int> v;
    //这里只处理非零正整数
    while(N!=0)
    {
        v.push_back(N%base);
        N/=base;
    }

    reverse(v.begin(),v.end());


    return v;
}
