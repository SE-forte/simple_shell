#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(void)

{
	char buffer[BUFFER_SIZE];
	char *args[100];
	int status;
	char *token;

	while (1)
	{
		printf("$ ");

		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{

			printf("\n");
			break;

		}

		buffer[strcspn(buffer, "\n")] = '\0';

		int i = 0;

		token = strtok(buffer, " ");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}

		args[i] = NULL;

		pid_t pid;

		pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			return (1);
		}
		else if (pid == 0)
		{

			if (execve(args[0], args, NULL) == -1)
			{
				perror("Exec failed");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}

	}
	return (0);
}
