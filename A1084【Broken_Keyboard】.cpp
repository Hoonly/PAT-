#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<iterator>
#include<map>
#include<set>

using namespace std;

int main()
{
    string s1;
    string s2;

    getline(cin,s1);
    getline(cin,s2);


    set<char> s;
    vector<char> v;
    int i=0;
    while(i<s2.length())
    {
        if(s2[i]!='_')
        {
            s2[i]=toupper(s2[i]);
            s.insert(s2[i]);
        }

        i++;
    }

    i=0;
    while(i<s1.length())
    {
        if(s1[i]!='_')
        {
            s1[i]=toupper(s1[i]);
            if(s.count(s1[i])==0&&find(v.begin(),v.end(),s1[i])==v.end())
                v.push_back(s1[i]);
        }
        i++;
    }

    for(int i=0;i<v.size();i++)
    {
        printf("%c",toupper(v[i]));
    }



    return 0;
}

