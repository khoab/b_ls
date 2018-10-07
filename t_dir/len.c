#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

int main(int ar, char **av)
{
	int i = 1;

	if (ar > 1)
	{
		while (i < ar)
		{
			printf("%d\n", strlen(av[i]));
			i++;
		}
	}
	return (0);
}
