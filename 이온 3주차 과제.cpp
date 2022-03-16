#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void total(int *count);

int main()
{
	int count[6];

	total(count);
}

void total(int *count)
	{
	int result = 0;

		printf("6개의 수를 ,를 포함하여 입력하세요 : ");
		scanf("%d, %d, %d, %d, %d, %d", &count[0],&count[1], &count[2], &count[3], &count[4], &count[5]);

			result = count[0] + count[1] + count[2] + count[3] + count[4] + count[5];

	printf("%d", result);
}
