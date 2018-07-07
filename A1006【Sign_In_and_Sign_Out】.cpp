/*
结构体存放每个人信息
先读入所有数据
按时间排序
优化：在读数据的同时比较大小，减少时间爱你复杂度（类似max更新值）
读数据可以用scanf("%d:%d:%d,&a,&b,&c)
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct info
{
    string Id;
    int sign_in_hour,sign_in_minute,sign_in_second;
    int sign_out_hour,sign_out_minute,sign_out_second;
};
bool cmp_sign_in(info a,info b)//来的时间由早到晚排序
{
    if(a.sign_in_hour!=b.sign_in_hour)
        return a.sign_in_hour<b.sign_in_hour;
    else if(a.sign_in_minute!=b.sign_in_minute)
        return a.sign_in_minute<b.sign_in_minute;
    else
        return a.sign_in_second<b.sign_in_second;
}
bool cmp_sign_out(info a,info b)//走的时间由晚到早排序
{
    if(a.sign_out_hour!=b.sign_out_hour)
        return a.sign_out_hour>b.sign_out_hour;
    else if(a.sign_out_minute!=b.sign_out_minute)
        return a.sign_out_minute>b.sign_out_minute;
    else
        return a.sign_out_second>b.sign_out_second;
}
int main()
{

    vector<info> students;
    int M;
    scanf("%d",&M);
    info tmp;
    for(int i=0;i<M;i++)
    {
        cin>>tmp.Id;

        cin>>tmp.sign_in_hour;
        getchar();//读':'
        cin>>tmp.sign_in_minute;
        getchar();//读':'
        cin>>tmp.sign_in_second;
        getchar();//读空格

        cin>>tmp.sign_out_hour;
        getchar();//读':'
        cin>>tmp.sign_out_minute;
        getchar();//读':'
        cin>>tmp.sign_out_second;

        students.push_back(tmp);
    }

    sort(students.begin(),students.end(),cmp_sign_in);
    cout<<students[0].Id<<" ";
    sort(students.begin(),students.end(),cmp_sign_out);
    cout<<students[0].Id;

    return 0;
}
