#include <stdio.h>

void prohod1(int *px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

void prohod2(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

int main()
{
	int a = 5;
	int& b = a;

	int x = 2;
	int y = 3;
	
	printf("x = %d y = %d\n", x, y);
	prohod1(&x, &y);
	printf("x = %d y = %d\n", x, y);
	prohod2(x, y);
	printf("x = %d y = %d\n", x, y);
}