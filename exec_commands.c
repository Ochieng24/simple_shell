
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"
#include "lists.h"
#include "main.h"
/**
 * run_command - searches path dirs for command and execs
 * @params: parameters
 */
void run_command(param_t *params)
{
	/*variable declarations */
	char *executeFile = NULL;
	pid_t pid;
	void (*buildin)(param_t *);

	buildin = get_builtin(params);
	if (buildin)/*check if built in func*/
	{
		buildin(params);
		return;
	}
	executeFile = get_file(params);
	/*check if file is present*/
	if (!executeFile)
	{
		return;
	}
	pid = fork();
	/*check for forking errors*/
	if (pid < 0)
	{
		free_params(params);
		exit(98);
	}
	else if (pid == 0)
	{
		execve(executeFile, params->args, NULL);
	}
	else
	{
		wait(&params->status);
		params->status = WEXITSTATUS(params->status);
		free(executeFile);
	}
}
