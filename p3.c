#include <stdio.h>

int main()
{
	int i = 0;
	char tabChar[100];
	while(i < sizeof(tabChar))
	{
		putchar(tabChar[i] = i++);
	}
}
