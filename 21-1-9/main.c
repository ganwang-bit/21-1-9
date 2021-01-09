//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    printf("Hello world!\n");
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n=0,i,a=0,j;
//    for(j=10000;j<100000;j++)
//    {
//        i=j;
//        while(i!=0)
//        {
//
//            if(i%10==4)
//            {
//                n++;
//                break;
//            }
//            i/=10;
//        }
//
//    }
//    a=90000-n;
//    printf("10000~99999中不包含4的个数为:%d",a);
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n,m,i,j,sum=0;
//    scanf("%d%d",&n,&m);
//    for(i=n,j=0;i<=m;i++,j++)
//    {
//        sum+=i;
//        printf("%5d",i);
//        if((j+1)%5==0&&j!=0)
//            printf("\n");
//    }
//    if((j)%5!=0)
//        printf("\n");
//    printf("Sum = %d",sum);
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int n,i,a,j,b,tmp,sum1=0,sum2=1;
//    scanf("%d",&n);
//    int arr[n][2];
//    for(i=0;i<n;i++)
//    {
//        scanf("%d/%d",&arr[i][0],&arr[i][1]);
//    }
//    for(i=0;i<n;i++)
//    {
//        sum2=arr[i][0];
//        for(j=0;j<n;j++)
//        {
//            if(j!=i)
//            {
//                sum2*=arr[j][1];
//            }
//        }
//        sum1+=sum2;
//    }
//    sum2=1;
//    for(i=0;i<n;i++)
//    {
//        sum2*=arr[i][1];
//    }
//    a=sum1;
//    b=sum2;
//    for(;1;)
//    {
//        if(a<b)
//        {
//            tmp=a;
//            a=b;
//            b=tmp;
//        }
//        if(a%b==0)
//            break;
//        a/=b;
//    }
//    sum1/=b;
//    sum2/=b;
//    if(sum1/sum2==0)
//        printf("%d/%d",sum1,sum2);
//    else
//    {
//        if(sum1%sum2==0)
//            printf("%d",sum1/sum2);
//        else
//            printf("%d %d/%d",sum1/sum2,sum1-(sum1/sum2)*sum2,sum2);
//    }
//    return 0;
//}
#include<stdio.h>
long gongyinshu(long a,long b)
{
    long tmp;
    do
    {
        if(a<b)
        {
            tmp=a;
            a=b;
            b=tmp;
        }
        a%=b;
    }while(a);
    return b;
}
void qiu(long *arr1,long *arr2)
{
    long g=gongyinshu(arr1[0]*arr2[1]+arr2[0]*arr1[1],arr1[1]*arr2[1]);
    arr2[0]=(arr1[0]*arr2[1]+arr2[0]*arr1[1])/g;
    arr2[1]=(arr1[1]*arr2[1])/g;
}
int main()
{
    long n;
    scanf("%ld",&n);
    long arr[n][2];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%ld/%ld",&arr[i][0],&arr[i][1]);
    }
    for(i=0;i<n-1;i++)
    {
        qiu(arr[i],arr[i+1]);
    }
    if(arr[n-1][0]/arr[n-1][0]==0)
    {
        printf("%ld/%ld",arr[n-1][0],arr[n-1][0]);
    }
    else
    {
        if(arr[n-1][0]%arr[n-1][1]==0)
            printf("%ld",arr[n-1][0]/arr[n-1][0]);
        else
        {
            long a,b;
            printf("%ld ",arr[n-1][0]/arr[n-1][1]);
            b=gongyinshu(arr[n-1][0]-arr[n-1][0]/arr[n-1][1],arr[n-1][1]);
            a=(arr[n-1][0]-arr[n-1][0]/arr[n-1][1])/b;
            b=arr[n-1][1]/b;
            printf("%ld/%ld",a,b);
        }
    }
    return 0;
}
