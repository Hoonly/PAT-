#include<iostream>
#include<string.h>
#include<string>
#include<iomanip>
#include<math.h>
#include<ctype.h>
using namespace std;
int main()
{
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    string day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int i;

    //day
    for(i=0;i<min(s1.length(),s2.length());i++)
    {
        if((s1[i]>='A'&&s1[i]<='G')&&s1[i]==s2[i])//第一对相同的大写英文字母，对应星期保证在A-G之间
        {
            int c=s1[i]-'A';
            cout<<day[c]<<" ";
            break;
        }
    }

    //hour
    for(i++;i<min(s1.length(),s2.length());i++)//在DAY的基础上找下一对相同的字符，保证在0-9或者A-N之间
    {
        if(s1[i]==s2[i])//如果相同
        {
            if(isdigit(s1[i]))//是0-9数字
            {
                cout<<setw(2)<<setfill('0')<<int(s1[i]-'0')<<":";
                break;
            }
            
            else if(s1[i]>='A'&&s1[i]<='N')
            {
                cout<<setw(2)<<int(s1[i]-'A'+10)<<":";
                break;
            }
        }
    }

    //minute
    for(i=0;i<min(s3.length(),s4.length());i++)
    {
        if(isalpha(s3[i])&&s3[i]==s4[i])//第一对相同的英文字母
        {
            cout<<setw(2)<<setfill('0')<<i;
            break;
        }
    }

    return 0;

}
