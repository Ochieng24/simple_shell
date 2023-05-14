#include <unistd.h>
#include "shell.h"
#include "main.h"

/*
 *write_error - write error msg to stderr*
 * @params: parameters struct contains info about the command and prog
 * @msg: error message to print
 * func takes a parameter struct containing info about current
 * command and program and an error message to print to stderr.func
 * builts an error msg str from the info in the param struct
 *and the error msg and writes to stderr using the write
 */
void write_error(param_t *params, char *mg)
{
char errBuffer[1024] = {0};
char *writeHead = errBuffer, *bufPtr = errBuffer;
_strcpy(writeHead, params->argv[0]);
writeHead = bufPtr + _strlen(bufPtr);
_strcpy(writeHead, ": ");
writeHead = bufPtr + _strlen(bufPtr);
_strcpy(writeHead, get_number(params->lineCount));
writeHead = bufPtr + _strlen(bufPtr);
_strcpy(writeHead, ": ");
writeHead = bufPtr + _strlen(bufPtr);
_strcpy(writeHead, params->args[0]);
writeHead = bufPtr + _strlen(bufPtr);
_strcpy(writeHead, ": ");
writeHead = bufPtr + _strlen(bufPtr);
_strcpy(writeHead, msg);
writeHead = bufPtr + _strlen(bufPtr);
write(STDERR_FILENO, errBuffer, _strlen(bufPtr));

}

















