/*
sum存入string,从后向前，每三个插入一个,
*/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int sum=a+b;
    string c;//代表正负
    if(sum<0) c="-";
    else c="";
    sum=abs(sum);
    if(sum<1000)//少于4位数不用格式化直接输出
        cout<<c<<sum;
    else
    {
        string s=to_string(sum);
        for(int i=s.length()-3;i>0;i-=3)
            s.insert(i,",");
        cout<<c<<s;
    }

    return 0;
}
