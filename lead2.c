#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"
#include "shell.h"
/**
 * get_file - Retrieve the proper path to a command file
 * @params: parameters
 * Return: If the command file cannot be located, return NULL.
 * The string must be released.
 */
char *get_file(param_t *params)/*Retrieve the proper path to a command file*/
{
char *exePath = NULL, *exeArg = NULL, *tmp = NULL, *state = NULL, *path = NULL;
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
exePath = _strtok(path, ":", &state);
while (exePath)
{
tmp = exeArg;
exeArg = str_concat(exePath, "/");
free(tmp);
tmp = exeArg;
exeArg = str_concat(exeArg, params->args[0]);
free(tmp);
if (access(exeArg, F_OK) == 0)
{
free(path);
free(exePath);
return (exeArg);
}
free(exePath);
exePath = _strtok(NULL, ":", &state);
}
params->status = 127;
write_error(params, "not found\n");
free(path);
free(exeArg);
return (NULL);
}
