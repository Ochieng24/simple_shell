#include <unistd.h>
#include "shell.h"
#include "main.h"
/**
 * write_error - write error message to stderr
 * @params: parameters struct containing info about the command and program
 * @msg: error message to print
 */
void write_error(param_t *params, char *msg)
{
char errors_Buffer[1024] = {0};/*array declaration to store error msg*/
char *modify_Head = errors_Buffer, *bufferPtr = errors_Buffer;
_strcpy(modify_Head, params->argv[0]);/*copy program name to error message*/
modify_Head = bufferPtr + _strlen(bufferPtr);/*move ptr end program*/
_strcpy(modify_Head, ": ");/*copy line count*/
modify_Head = bufferPtr + _strlen(bufferPtr);
_strcpy(modify_Head, get_number(params->lineCount));/*copy line count value*/
modify_Head = bufferPtr + _strlen(bufferPtr);
_strcpy(modify_Head, ": ");
modify_Head = bufferPtr + _strlen(bufferPtr);
_strcpy(modify_Head, params->args[0]);/*copy 1st arg of the command*/
modify_Head = bufferPtr + _strlen(bufferPtr);
_strcpy(modify_Head, ": ");
modify_Head = bufferPtr + _strlen(bufferPtr);
_strcpy(modify_Head, msg);/*copy error msg*/
modify_Head = bufferPtr + _strlen(bufferPtr);
write(STDERR_FILENO, errors_Buffer, _strlen(bufferPtr));/*write err to stderr*/
}

















