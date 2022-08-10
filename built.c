#include "shell.h"

/**
 * built_in - Checks for builtin functions.
 * @command: An array of all the arguments passed to the shell.
 * @line: A string representing the input from the user.
 * Return: If function is found 0. Otherwise -1.
 */
int built_in(char **command, char *line)
{
        void (*build)(char *);

        build = check_built_ins(command[0]);
        if (build == NULL)
                return (-1);
        if (_strcmp("exit", command[0]) == 0)
                double_free(command);
        build(line);
        return (0);
}
