/*
len+2求平均值，剩余的个数给底行即可
*/
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int len=s.length();
    int n1,n2,n3;

    int average=(len+2)/3;
    n1=n2=n3=average;
    int rest=(len+2)%3;
    if(rest!=0)
        n2+=rest;


    int row=n1;
    int col=n2;
    for(int i=0;i<row-1;i++)
        cout<<s[i]<<setw(n2-1)<<s[len-1-i]<<endl;
    for(int i=0;i<col;i++)
        cout<<s[n1-1+i];


    return 0;


}
