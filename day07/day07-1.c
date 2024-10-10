#include <stdio.h>

int main (void)
{
    int num;

    printf("몇층 피라미드인지 입력하세요 :");
    scanf("%d",&num);

    for(int i=1; i<=num; i++) 
    {
        for(int j=1; j<=num-i; j++)
        {
        printf(" ");
        }
        for(int k=0; k < i*2-1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}