#ifndef MY_SHELL_H
#define MY_SHELL_H
#define _GNU_SOURCE
#include "listing.h"
#include <stdio.h>
/**
 * struct param_s - structure used to hold all shell variables needed
 * @argv: command line argument from main function
 * @buffer: input buffer
 * @args: array of arguments
 * @nextCommand: the next command to process
 * @argsCap: num of arguments the args array can hold
 * @lineCount: total line of input
 * @tokCount: num of tokens in a line input
 * @status: run command return status
 * @env_head: singly linked list of environment vars
 * @alias_head: singly linked list of aliases
 * Description: This structures hold all variables that passed into
 * other functions.
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

void _myExit(param_t *params);

void _clear(param_t *params);
#endif
