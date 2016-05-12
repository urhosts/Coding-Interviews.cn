#include <stdio.h>
#include <assert.h>
#include <windows.h>

#define MAX 50

void ReplaceBlack(char string[], int length)
{
	if (string == NULL || length <= 0)
	{
		return;
	}
	int originalLength = 0;
	int numberOfBlack = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		++originalLength;
		if (string[i] == ' ')
		{
			++numberOfBlack;
		}
		++i;
	}
	int newlength = originalLength + numberOfBlack * 2;
	if (newlength > length)
	{
		return;
	}
	int indexOfOriginal = originalLength;
	int indexOfNew = newlength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
		{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}
int main()
{
	char arr[MAX] = "We are happy.";
	int length = sizeof(arr) / sizeof(arr[0]);
	ReplaceBlack(arr, length);
	printf("%s\n", arr);
	system("pause");
	return 0;
}