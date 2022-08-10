#include "shell.h"

/**
 * main - Entry point.
 * @argc: The number of arguments passed throug
 * command propt. 
 * @argv: input commands.
 * Return: Always 0.
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *line;
	size_t size;
	int command_counter;

	command_counter = 0;
	signal(SIGINT, SIG_IGN);
	do {
		command_counter++;
		line = NULL;
		size = 0;
		parse_line(line, size, command_counter, argv);

	} while (1);

	return (0);
}
