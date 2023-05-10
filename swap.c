#include <stdio.h>

/**
* swap - swap two int variables without using another one.
* @x: the first variable
* @y: the second variable.
* Return: nothing.
*/

void swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

/**
* main - entry point
* Return: 0
*/
int main(void)
{
	int x, y;

	x = 10;
	y = 20;
	printf("Before swaping \nx = %d\ny = %d\n", x, y);

	swap(&x, &y);
	printf("After swaping \nx = %d\ny = %d\n", x, y);
	return (0);
}
