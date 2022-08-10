#include "shell.h"

/**
 * chd - Changes the current working directory to the parameter passed to cd.
 * if no parameter is passed it will change directory to HOME.
 * @line: A string representing the input from the user.
 */
void chd(char *line)
{
	int index;
	int token_num;
	char **array;
	const char *delim = "\n\t ";

	token_num = 0;
	array = token_interface(line, delim, token_num);
	if (array[0] == NULL)
	{
		single_free(2, array, line);
		return;
	}
	if (array[1] == NULL)
	{
		index = find_path("HOME");
		chdir((environ[index]) + 5);
	}
	else if (_strcmp(array[1], "-") == 0)
		print_str(array[1], 0);

	else
		chdir(array[1]);
	double_free(array);
}

/**
 * enviro - Prints all the environmental variables in the current shell.
 * @line: A string representing the input from the user.
 */
void enviro(__attribute__((unused))char *line)
{
	int i;
	int j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * exit_shell - Exits the shell. After freeing allocated resources.
 * @line: A string representing the input from the user.
 */
void exit_shell(char *line)
{
	free(line);
	print_str("\n", 1);
	exit(1);
}

/**
 * check_built_ins - Finds the right function needed for execution.
 * @str: The name of the function that is needed.
 * Return: Upon sucess a pointer to a void function. Otherwise NULL.
 */
void (*check_built_ins(char *str))(char *str)
{
	int i;

	builtin_t buildin[] = {
		{"exit", exit_shell},
		{"env", enviro},
		{"cd", chd},
		{NULL, NULL}
	};

	for (i = 0; buildin[i].built != NULL; i++)
	{
		if (_strcmp(str, buildin[i].built) == 0)
		{
			return (buildin[i].f);
		}
	}
	return (NULL);
}
