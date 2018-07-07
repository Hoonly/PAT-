#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int A[3],B[3],C[3];
    scanf("%d.%d.%d",&A[0],&A[1],&A[2]);
    scanf("%d.%d.%d",&B[0],&B[1],&B[2]);
    //进位
    int k_to_s=0;
    int s_to_g=0;

    C[2]=A[2]+B[2];
    if(C[2]>=29)
    {
        int r=C[2]%29;
        k_to_s=C[2]/29;
        C[2]=r;
    }
    C[1]=A[1]+B[1]+k_to_s;
    if(C[1]>=17)
    {
        int r=C[1]%17;
        s_to_g=C[1]/17;
        C[1]=r;
    }
    C[0]=A[0]+B[0]+s_to_g;

    printf("%d.%d.%d",C[0],C[1],C[2]);

    return 0;


}
