#include<iostream>
#include<string>
using namespace std;
int main()
{
    string eng[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    string input;
    cin>>input;
    int sum=0;
    for(int i=0;i<input.length();i++)
        sum+=input[i]-'0';

    string result=to_string(sum);
    for(int i=0;i<result.length();i++)
    {
        cout<<eng[result[i]-'0'];
        if(i!=result.length()-1)
            cout<<" ";
    }
    return 0;
}
