#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<string>
using namespace std;




int main()
{

    string s1[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    string s2[9]={"","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi"};

    string input;
    cin>>input;
    string c;//读取符号
    if(input[0]=='-')
    {
      c="Fu";
      input.erase(0,1);//把负号删掉
      cout<<"Fu"<<" ";
    }
    else
        c="";



    vector<string> result;
    int len=input.length();
    int index=input.length()-1;
    while(index>=0)
    {
        int cur_num=input[index]-'0';
        if(cur_num!=0)
        {
            result.insert(result.begin(),s2[len-index-1]);
            result.insert(result.begin(),s1[cur_num]);
        }
        else
        {
            if(result.size()!=0&&result[0]!="ling"&&result[0]!="Wan"&&result[0]!="Yi")
                result.insert(result.begin(),s1[cur_num]);
            if(s2[len-index-1]=="Wan"||s2[len-index-1]=="Yi")
                result.insert(result.begin(),s2[len-index-1]);
        }
        index--;
    }


    if(result.end()!=find(result.begin(),result.end(),""))
      result.erase(find(result.begin(),result.end(),""));


    for(int i=0;i<result.size();i++)
    {
        cout<<result[i];
        if(i!=result.size()-1)
            cout<<" ";
    }

    cout<<"END";
    return 0;

}
