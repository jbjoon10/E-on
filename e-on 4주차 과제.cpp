#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int i, j, temp;
	int array[6] = { 0 };
	printf("6개의 수를 입력하시오. : ");
	scanf_s("%d, %d, %d, %d, %d, %d", &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);

	for (i = 0; i < 6; ++i)
	{
		for (j = 0; j < 5; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	printf("%d, %d, %d, %d, %d, %d", array[0], array[1], array[2], array[3], array[4], array[5]);
}
