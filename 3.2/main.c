#include <stdio.h>

int HermitePoly1(int x, int n);
int HermitePoly2(int x, int n);

int main()
{
    int x,n;
    char ch;
    ch='A';
    while((ch=='a')||(ch=='A'))
    {
        printf("\nInput x=");
        scanf("%d",&x);
        printf("\nInput n=");
        scanf("%d",&n);
        printf("\nRECURSIVE COMPUTATION: HermitePoly1(%d,%d)=%d\n",x,n,HermitePoly1(x,n));
        printf("\nNON-RECURSIVE COMPUTATION: HermitePoly1(%d,%d)=%d\n",x,n,HermitePoly2(x,n));
        printf("\nContinue? Press A or a\n");
        getchar();
        ch=getchar();
    }
    return 0;
}

/*RECURSIVE VERSION*/
int HermitePoly1(int x, int n)
{
    if(n==0)
        return 1;
    else
    if(n==1)
        return 2*x;
    else
        return 2*n*HermitePoly1(x,n-1)-2*(n-1)*HermitePoly1(x,n-2);
}

/*NON-RECURSIVE VERSION*/
int HermitePoly2(int x, int n)
{
    int i,x0,x1,x2;
    if(n==0)
        return 1;
    else {
        if (n == 1)
            return 2 * x;
        else {
            x0 = 1;
            x1 = 2 * x;
            for (i = 2; i <= n; i++) {
                x2 = 2 * i * x1 - 2 * (i - 1) * x0;
                x0 = x1;
                x1 = x2;
            }
            return x2;
        }
    }
}