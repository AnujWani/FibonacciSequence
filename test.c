#include<stdio.h>
int main()
{
    int n,x,a,b,c;
    printf("Enter a number: ");
    scanf("%d",&n);
    x=1;
    a=1;
    b=1;
    while(x<=n)
    {
        printf("%d ",a);
        c = a + b;
        a = b;
        b = c;
        x++;
    }
    return 0; 
}
