#include<stdio.h>
int main()
{
    //数组下标表示指数
    double A[1001]={0};
    double B[1001]={0};

    int K1,K2;//项数
    int expo;//指数
    double coef;//系数

    scanf("%d",&K1);
    for(int i=0;i<K1;i++)
    {
        scanf("%d %lf",&expo,&coef);
        A[expo]=coef;
    }
        
    scanf("%d",&K2);
    for(int i=0;i<K2;i++)
    {
        scanf("%d %lf",&expo,&coef);
        B[expo]=coef;
    }

    int count=0;//结果项数
    for(int i=0;i<1001;i++)//多项式相加
    {
        A[i]+=B[i];
        if(A[i]!=0)
            count++;
    }
    printf("%d ",count);
    int low=0;
    //从前向后查找系数不为0的项即为最低次项(控制结尾不能有空格)
    for(int i=0;i<1001;i++)
    {
        if(A[i]!=0)
        {
            low=i;
            break;
        }    
    }
    //从后向前查找系数不为0的项即为最高次项
    for(int i=1000;i>=0;i--)
    {
        if(A[i]!=0)
        {
            printf("%d %.1f",i,A[i]);
            if(i==low)//到最低次项即可结束打印
                break;
            else
                printf(" ");
        }     
    }

    return 0;
}