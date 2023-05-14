#ifndef LISTSH
#define LISTSH

#include <unistd.h>

/**
 * struct list_s - singly linked list node
 * @str: string data
 * @val: value str data
 * @len: len str data
 * @valLen: len str data
 * @next: points next node
 * Description: rep a node in a single linked list.
 */

typedef struct list_s
{
unsigned int valLen;
char *val;
unsigned int len;
struct list_s *next;
char *str;
} list_t;


int _putchar(char c);

list_t *add_node(list_t **head, char *str, char *val);

size_t print_list(list_t *h);

size_t list_len(list_t *h);

list_t *get_node(list_t *head, char *str);

void free_list(list_t *head);



#endif
