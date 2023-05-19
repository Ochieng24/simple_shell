#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"
#include "shell.h"
/**
 * get_file - Retrieve command file path
 * @params: params
 * Return: NULL If command file cannot be locate.
 * The string must be released.
 */
char *get_file(param_t *params)/*Retrieve the proper path to a command file*/
{
char *execute_path = NULL, *execute_args = NULL, *tmp = NULL, *current_state = NULL, *path = NULL;
if (access(params->args[0], F_OK | X_OK) == 0)
{
free(path);
return (strdup(params->args[0]));
}
if (errno == EACCES)
{
params->status = 126;
write_error(params, "Permission denied\n");
return (NULL);
}
path = _getenv("PATH", params);
if (!path)
{
write_error(params, "not found\n");
return (NULL);
}
execute_path = _strtok(path, ":", &current_state);
while (execute_path)
{
tmp = execute_args;
execute_args = str_concat(execute_path, "/");
free(tmp);
tmp = execute_args;
execute_args = str_concat(execute_args, params->args[0]);
free(tmp);
if (access(execute_args, F_OK) == 0)
{
free(path);
free(execute_path);
return (execute_args);
}
free(execute_path);
execute_path = _strtok(NULL, ":", &current_state);
}
params->status = 127;
write_error(params, "not found\n");
free(path);
free(execute_args);
return (NULL);
}
