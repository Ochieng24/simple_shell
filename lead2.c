#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"
#include "shell.h"
#include "listing.h"
/**
 * get_file - Retrieve command file path
 * @params: params
 * Return: NULL If command file cannot be locate.
 * The string must be released.
 */
char *get_file(param_t *params)/*Retrieve the proper path to a command file*/
{
char *execute_path = NULL, *execute_args = NULL, *tmp = NULL;
char *current_state = NULL, *path = NULL;
/*check if command file exists and is executable*/
if (access(params->args[0], F_OK | X_OK) == 0)
{
free(path);
return (strdup(params->args[0]));
}
/*check for permissions denied error*/
if (errno == EACCES)
{
params->status = 126;
write_error(params, "Permission denied\n");
return (NULL);
}
/*Get PATH environment variable*/
path = _getenv("PATH", params);
/*check if PATH is not set*/
if (!path)
{
write_error(params, "not found\n");
return (NULL);
}
/*tokenize path variable and search for command file*/
execute_path = _strtok(path, ":", &current_state);
while (execute_path)
{
tmp = execute_args;
execute_args = str_concat(execute_path, "/");
free(tmp);
tmp = execute_args;
execute_args = str_concat(execute_args, params->args[0]);
free(tmp);
/*checks if the command file exists*/
if (access(execute_args, F_OK) == 0)
{
free(path);
free(execute_path);
return (execute_args);
}
free(execute_path);
execute_path = _strtok(NULL, ":", &current_state);
}
/*prints the error if file not found*/
params->status = 127;
write_error(params, "not found\n");
free(path);
free(execute_args);
return (NULL);
}
