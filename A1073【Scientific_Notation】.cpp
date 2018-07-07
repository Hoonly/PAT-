/*
1.设定一个char接受起始符号位
2.逐个输入字符直到E为止，传入一个string中
4.设定一个char接受指数符号位
5.指数部分直接输入到一个string中，之后转整数
6.移动2中的小数点的位置
tips:STRING erase函数是删除字符，要指定删除的字符个数，否则就会删掉参数一之后所有的
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
using namespace std;
int main()
{

    char c1=getchar();//起始符号位

    string s1;//E之前的数字
    char tmp;
    while(cin>>tmp)
    {
        if(tmp!='E')
            s1.push_back(tmp);
        else
            break;
    }

    char c2=getchar();//指数符号位

    string s2;//指数部分
    cin>>s2;
    int sum=0;//转整数
    for(int i=s2.length()-1;i>=0;i--)
        sum+=(s2[i]-'0')*pow(10,s2.length()-1-i);


    if(sum==0);
    else
    {


    if(c2=='+')//如果指数为正
    {
        //看原来小数点后有几位
        int behind_point=s1.length()-1-s1.find('.');
        //cout<<"point is at"<<s1.find('.')<<endl;;
        //cout<<"behind point is"<<behind_point<<"integers"<<endl;

        if(behind_point<=sum)//如果小数点后位数小于等于指数，末尾补差0,删去小数点
        {
            for(int i=0;i<sum-behind_point;i++)
                s1.push_back('0');
            //cout<<"after insert 0:"<<s1<<endl;
            s1.erase(s1.find('.'),1);
        }
        else//如果小数点后位数大于指数，移动小数点位置
        {
            s1.insert(s1.find('.')+sum+1,".");//先在合适位置插入小数点
            s1.erase(s1.find('.'),1);//然后找到并删除第一个小数点
        }
    }
    else//如果指数为负
    {
        for(int i=0;i<sum;i++)//在前端补0
            s1.insert(0,"0");
        s1.erase(s1.find('.'),1);//删除原来的小数点
        s1.insert(1,".");//在第2位插入小数点
    }

    }

    if(c1=='+')
        cout<<s1;
    else
        cout<<"-"<<s1;

    return 0;



}
