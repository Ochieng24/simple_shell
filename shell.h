#ifndef MY_SHELL_H
#define MY_SHELL_H
#define _GNU_SOURCE
#include "listing.h"
#include <stdio.h>
/**
 * struct param_s: The necessary shell variables are stored in the structure.
 * @argv: Command-line argument from the main function
 * @args: An array of arguments
 * @buffer: input buffer
 * @nextCommand: The subsequent command to be processed.
 * @lineCount: overall number of input lines
 * @argsCap: maximum number of arguments the args array can contain
 * @status: Run commands should return status
 * @tokCount: Number of tokens in a single line of input
 * @alias_head: singly linked list of aliases
 * @env_head: singly linked array of environment variable
 * Description: stores vares supplied into other funcs
 */
typedef struct param_s
{
char **args;
unsigned int tokCount;
char *buffer;
char *nextCommand;
unsigned int argsCap;
unsigned int lineCount;
int status;
list_t *env_head;
char **argv;
list_t *alias_head;
} param_t;

/**
 * struct op - a built in funct
 * @name: built in name
 * @func: pointer to built in funct
 */
typedef struct op
{
char *name;
void (*func)(param_t *);
} op_t;
void _alias(param_t *params);

int process_string(param_t *);

int _strcmp(char *, char *);

char *_strdup(char *);

void _cd(param_t *params);

char *_strcpy(char *dest, const char *src);

int _getline(param_t *);

int _strcmp_n(char *, char *, int n);

char *_strtok(char *str, char *delim, char **savePtr);

void _setenv(param_t *params);

void run_command(param_t *);

void _printenv(param_t *);

void sigint_handler(int);

char *_getenv(char *name, param_t *params);

void _unsetenv(param_t *params);

void print_alias(char *name, param_t *params);

char *get_file(param_t *params);

void (*get_builtin(param_t *params))(param_t *);

void _alias(param_t *params);

void set_alias(char *name, param_t *params);

void make_alias(char *name, char *val, param_t *params);

void print_all_aliases(param_t *params);

void free_params(param_t *params);

void print_list_env(list_t *);

void print_list_alias(list_t *);

void *_realloc(char **ptr, unsigned int old_size, unsigned int new_size);

void write_error(param_t *params, char *msg);

void _clear(param_t *params);
#endif
