#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
int main()
{
    int T;
    cin>>T;
    
    vector<string> result;//存放输出结果
    long A,B,C;
    long res;
    for(int i=1;i<=T;i++)
    {
        
        cin>>A>>B>>C;
        res=A+B;
        if(A>0&&B>0&&res<0)
            result.push_back(string("Case #")+to_string(i)+string(": true\n"));
        else if(A<0&&B<0&&res>=0)
            result.push_back(string("Case #")+to_string(i)+string(": false\n"));
        else
        {
            if(A+B>C)
                result.push_back(string("Case #")+to_string(i)+string(": true\n"));
            else
                result.push_back(string("Case #")+to_string(i)+string(": false\n"));
        }
        
    }

    for(int i=0;i<result.size();i++)
        cout<<result[i];


    return 0;
}
