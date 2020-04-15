#include "shell.h"

/**
 * prompt - print a prompt
 *
 * Description: prompt
 * Return: nothing
 */

void prompt(void)
{
if (isatty(STDIN_FILENO))
write(STDERR_FILENO, "$ ", 2);
}
