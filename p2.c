#include <stdio.h>

int main()
{
	int b;
	b = getchar();
	while(b != EOF)
	{
		putchar(b+1);
		b = getchar();
	}
}
