#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i;
	int add = 0;

	printf("argc or ac = %d\n", ac);
	printf("argv content is argv[]\n");

	for (i = 1; i < ac; i++)
	{
		printf("argv[%d] = %s\n", i, av[1]);
		add += atoi(av[i]);
	}
	printf("add is %d", add);
	return (0);
}
