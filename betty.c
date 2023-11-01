#include <stdio.h>

#define MAX_LENGTH 100

/**
 * struct Point - Represents a 2D point.
 * @x: The X coordinate.
 * @y: The Y coordinate.
 */
struct Point
{
	int x;
	int y;
};

/**
 * add - Adds two integers.
 * @a: The first integer.
 * @b: The second integer.
 *
 * Return: The sum of a and b.
 */
int add(int a, int b)
{
	return a + b;
}

/**
 * print_hello - Prints a hello message to the console.
 */
void print_hello(void)
{
	printf("Hello, world!\n");
}

/**
 * main - The main function.
 *
 * Return: 0 for success.
 */
int main(void)
{
	struct Point p;
	p.x = 5;
	p.y = 10;
	
	printf("Sum: %d\n", add(p.x, p.y));
	print_hello();
	return 0;
}
