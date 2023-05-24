
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
	char *executeFile = NULL;/*Stores the path of the executable file*/
	pid_t pid;
	void (*buildin)(param_t *);/*Function pointer for built-in commands*/

	buildin = get_builtin(params);
	if (buildin)/*check if built in func*/
	{
		buildin(params);/*Call the built-in function*/
		return;
	}
	executeFile = get_file(params);/*Get the path of the executable file*/
	/*check if file is present*/
	if (!executeFile)
	{
		return;
	}
	pid = fork();
	/*check for forking errors*/
	if (pid < 0)/*if forking failed*/
	{
		free_params(params);/*Free allocated memory for params*/
		exit(98);
	}
	else if (pid == 0)
	{
		execve(executeFile, params->args, NULL);/*Execute executable file with args*/
	}
	else
	{
		wait(&params->status);
		params->status = WEXITSTATUS(params->status);
		free(executeFile);/*Exit the child process with failure status*/
	}
}
