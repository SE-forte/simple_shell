#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void)

{
	char buffer[BUFFER_SIZE];
	char *args[100];
	int status;

	while (1)

	{
		printf("$ ");

		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			printf("\n");
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		char *token = strtok(buffer, " ");
		int i = 0;

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");

		}

		args[i] = NULL;

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("Fork failed");
			return (1);
		}

		else if (pid == 0)
		{

			if (execvp(args[0], args) == -1)
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
