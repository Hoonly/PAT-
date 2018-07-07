/*
tips:不要用find,要找出所有字符并替换
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    struct info
    {
        string user_name;
        string password;
    };

    int N;
    cin>>N;

    vector<info> users;
    info tmp;
    bool flag=false;
    for(int i=0;i<N;i++)
    {
        cin>>tmp.user_name>>tmp.password;
        for(int i=0;i<tmp.password.length();i++)//替换字符
        {
            if(tmp.password[i]=='1')
            {
                tmp.password[i]='@';
                flag=true;
            }
            if(tmp.password[i]=='0')
            {
                tmp.password[i]='%';
                flag=true;
            }
            if(tmp.password[i]=='l')
            {
                tmp.password[i]='L';
                flag=true;
            }
            if(tmp.password[i]=='O')
            {
                tmp.password[i]='o';
                flag=true;
            }
        }

        if(flag)
            users.push_back(tmp);
        flag=false;

    }

    int M=users.size();
    if(M==0)
    {
        if(N==1)
            cout<<"There is 1 account and no account is modified";
        else
            cout<<"There are "<<N<<" accounts and no account is modified";
    }
    else
    {
        cout<<M<<endl   ;
        for(int i=0;i<M;i++)
            cout<<users[i].user_name<<" "<<users[i].password<<endl;
    }

    return 0;

}
