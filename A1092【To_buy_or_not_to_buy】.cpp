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
    int count1=0;//ͳ���⴮���ж��ٸ�
    while(true)
    {
        scanf("%c",&c1);
        if(c1=='\n')
            break;
        else
        {
            if(m.count(c1)==0)//������û��������ɫ
                m.insert(pair<char,int>(c1,1));//�½�һ����ɫ
            else//�����������ɫ�����ļ�����1
                m[c1]++;
            count1++;
        }
    }

    char c2;
    bool flag=true;//����Ƿ�ȱʧ
    int count2=0;//ͳ����Ҫ����ɫ����
    int miss_count=0;
    while(true)
    {
         scanf("%c",&c2);
         if(c2=='\n')
            break;
        else
        {
            if(m.count(c2)==0)//����⴮���治����ĳ����ɫ������ȫ
            {
                flag=false;
                miss_count++;
            }
            else
            {
                m[c2]--;//�ҵ�һ���ͽ��������һ�������´γ����ظ���
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

