#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int count = 0;
	int result = 0;
	int i;

	for (i = 0; i < 6; i++)
	{
		count = int(printf("6개의 수를 입력하세요 : "));
		scanf("%d", &count);
			result += count;
	}
	printf("%d", result);
}
