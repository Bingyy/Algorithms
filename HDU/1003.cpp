#include<stdio.h>
#define MinInt -272100120
int  main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int k,num,sum=0,max=MinInt,start=1,end=1,_s=1;
        int MaxNum=MinInt,x=0;
        bool flag=true;

        scanf("%d",&k);

        for(int j=0;j<k;j++)
        {

            scanf("%d",&num);
            if(num>MaxNum)
            {
                MaxNum=num;
                x=j+1;
            }

            sum+=num;

            if(sum>0&&sum>max)
            {
                flag=false;
                max=sum;
                start=_s;
                end=j+1;

            }
            if(sum<0)
            {
                sum=0;
                _s=j+2;
            }

        }

        if(flag)
        {
            max=MaxNum;
            start=x;
            end=x;
        }

        printf("Case %d:\n%d %d %d\n",i+1,max,start,end);

        if((n-1)!=i)
            printf("\n");

    }

}