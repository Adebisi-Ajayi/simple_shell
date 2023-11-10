#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	size_t n = 0;
	char *buf = NULL;
	
	printf("$ ");
	getline(&buf, &n, stdin);
	printf("%s",buf);

	free(buf);

	return (0);
}
