#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<set>
using namespace std;

int main()
{
    string s1;
    string s2;
    getline(cin,s1);
    getline(cin,s2);

    set<char> s;
    for(int i=0;i<s2.length();i++)
    {
        s.insert(s2[i]);
    }

    for(int i=0;i<s1.length();i++)
    {
        if(s.count(s1[i])==0)
            printf("%c",s1[i]);
    }
    return 0;
}

