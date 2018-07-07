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
    map<char,int> m;
    char c1;
    int count1=0;//统计这串共有多少个
    while(true)
    {
        scanf("%c",&c1);
        if(c1=='\n')
            break;
        else
        {
            if(m.count(c1)==0)//如果里边没有这种颜色
                m.insert(pair<char,int>(c1,1));//新建一个颜色
            else//如果有这种颜色，它的计数加1
                m[c1]++;
            count1++;
        }
    }

    char c2;
    bool flag=true;//标记是否缺失
    int count2=0;//统计需要的颜色个数
    int miss_count=0;
    while(true)
    {
         scanf("%c",&c2);
         if(c2=='\n')
            break;
        else
        {
            if(m.count(c2)==0)//如果这串里面不包含某个颜色，代表不全
            {
                flag=false;
                miss_count++;
            }
            else
            {
                m[c2]--;//找到一个就将其计数减一，方便下次出现重复的
                if(m[c2]==0)
                    m.erase(c2);
            }

            count2++;
        }
    }
    if(flag)
        printf("Yes %d",count1-count2);
    else
        printf("No %d",miss_count);


    return 0;






    return 0;
}

