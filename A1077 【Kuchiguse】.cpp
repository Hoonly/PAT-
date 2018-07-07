#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    getchar();
    vector<string> input(N);
    int min=256;//最短串的长度
    for(int i=0;i<N;i++)
    {
        char c=getchar();
        while(c!='\n')
        {
            input[i].push_back(c);
            c=getchar();
        }
        reverse(input[i].begin(),input[i].end());
        if(input[i].length()<min)
            min=input[i].length();
    }


    string tmp;
    string output;
    int index=0;
    bool flag=true;
    //从前往后找所谓的最大公共子串
    while(flag&&index<min)
    {
        for(int i=0;i<N;i++)
            tmp.push_back(input[i].at(index));
        sort(tmp.begin(),tmp.end());
        if(tmp[0]!=tmp[tmp.length()-1])
        {
           flag=false;
           break;
        }
        output.push_back(tmp[0]);
        tmp="";
        index++;
    }

    reverse(output.begin(),output.end());
    if(output.length()!=0)
        cout<<output;
    else
        cout<<"nai";


    return 0;







}
