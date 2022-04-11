#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int icount(int n)
{
    int result = 1;
    while (n > 0) 
    {
        result = result * n;
        n--;
    }
    return result;
}

int main()
{
    int n;
    int count = 0;
    int count1;
    int count2 = 1;

    printf( "나눌 피자의 조각 수를 입력해주세요 : " );

    scanf("%d", &n);

    count++;
    while (count2 * 2 <= n) 
    {
        count1 = n - count2 * 2;
        count += icount(n - count2) / ((icount(count1)) * icount(count2));
        count2++;
    }
    printf("피자를 나눌 수 있는 방법의 수는 %d가지 입니다.", count);
}
