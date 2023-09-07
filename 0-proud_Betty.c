#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number;

	for (number = 1; number <= 100; number++)

	{
		if (number % 2 != 0)

		{
			printf("%d\n", number);
		}
	}

	return (0);
}
