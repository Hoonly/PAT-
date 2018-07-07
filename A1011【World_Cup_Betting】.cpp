#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
    double game[3][3];//存放三次比赛信息
    char s[3]={'W','T','L'};

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%lf",&game[i][j]);

    double bet1=max(game[0][0],max(game[0][1],game[0][2]));
    double bet2=max(game[1][0],max(game[1][1],game[1][2]));
    double bet3=max(game[2][0],max(game[2][1],game[2][2]));


    int choice1=find(game[0],game[0]+3,bet1)-game[0];
    int choice2=find(game[1],game[1]+3,bet2)-game[1];
    int choice3=find(game[2],game[2]+3,bet3)-game[2];

    double profit=(bet1*bet2*bet3*0.65-1)*2;

    printf("%c %c %c %.2f",s[choice1],s[choice2],s[choice3],profit);

    return 0;
}
