#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	while (true)
	{
		printf("> ");
		char *line = kash_read_line();
		char **tokens = kash_split_line(line);

		if (tokens[0] != NULL)
		{
			ksh_exec(tokens);
		}
		
		free(tokens);
		free(line);
	}
}

