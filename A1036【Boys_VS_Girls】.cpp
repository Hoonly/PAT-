/*
tips:如果哪一种性别的学生没有,就在他所在输出的那一行输出Absent
Absent
Absent
NA
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct info
{
    string name;
    char gender;
    string id;
    int grade;
};
bool cmp(info a,info b)//按成绩由小到大排序
{
    return a.grade<b.grade;
}
int main()
{
    int N;
    cin>>N;

    vector<info> male,female;
    info tmp;
    for(int i=0;i<N;i++)
    {
        cin>>tmp.name>>tmp.gender>>tmp.id>>tmp.grade;
        if(tmp.gender=='M')
            male.push_back(tmp);
        else
            female.push_back(tmp);
    }
    if(male.size()==0&&female.size()!=0)
    {
        cout<<"Absent"<<endl;
        sort(female.begin(),female.end(),cmp);
        cout<<female.back().name<<" "<<female.back().id<<endl;
        cout<<"NA";
    }
    else if(female.size()==0&&male.size()!=0)
    {
        cout<<"Absent"<<endl;
        sort(male.begin(),male.end(),cmp);
        cout<<male[0].name<<" "<<male[0].id<<endl;
        cout<<"NA";

    }
    else
    {
        sort(male.begin(),male.end(),cmp);
        sort(female.begin(),female.end(),cmp);
        cout<<female.back().name<<" "<<female.back().id<<endl;
        cout<<male[0].name<<" "<<male[0].id<<endl;
        cout<<female.back().grade-male[0].grade;
    }

    return 0;
}
