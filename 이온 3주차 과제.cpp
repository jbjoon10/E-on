#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int count1, count2, count3, count4, count5, count6;
	int result;

	{
		printf("6개의 수를 입력하세요 : ");
		scanf("%d, %d, %d, %d, %d, %d", &count1, &count2, &count3, &count4, &count5, &count6);
			result = count1+ count2+ count3+ count4+ count5+ count6;
	}
	printf("%d", result);
}
