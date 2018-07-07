#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

string to_base13(int N);
int main()
{
    int R,G,B;
    cin>>R>>G>>B;
    cout<<"#";
    cout<<setfill('0')<<setw(2)<<to_base13(R);
    cout<<setfill('0')<<setw(2)<<to_base13(G);
    cout<<setfill('0')<<setw(2)<<to_base13(B);

    return 0;

}

string to_base13(int N)
{
    string rt;
    int tmp;
    while(N!=0)
    {
        tmp=N%13;
        if(tmp<=9)
            rt.push_back(tmp+'0');
        else
        {
            rt.push_back(tmp-10+'A');
        }
        N=N/13;
    }
    reverse(rt.begin(),rt.end());
    return rt;
}
