#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void parseInput(char *input, char*args[])
{
	int i;

	i = 0;

	token = strtok(input, " ");

	while (token != NULL)

	{
		args[i++] = token;

		token = strtok(NULL, " ");
	}

	args[i] = NULL;
}

void executeCommand(char *args[])
{
	pid_t pid;

       	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(1);
	}

	else if (pid == 0)

	{
		if (execvp(args[0], args) == -1)

		{
			perror("Exec failed");
					exit(1);
		}
	}
	else
	{
		int status;

		wait(&status);

	}

}

int main(void)

{
	char buffer[BUFFER_SIZE];
	char *args[100];

	while (1)

	{
		printf("$ ");

		if (fgets(buffer, sizeof(buffer), stdin) == NULL)

		{
			printf("\n");
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';
		parseInput(buffer, args);
		executeCommand(args);

	}

	return (0);

}
