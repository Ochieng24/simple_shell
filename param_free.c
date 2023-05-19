#include "lists.h"
#include "shell.h"
#include <stdlib.h>
/**
 * free_params - Frees the memory allocated for the param_t structure.
 * @params: pointer to the param_t structure to free
 *
 * This function frees the dynamically allocated memory used by the param_t
 * structure, including its members: the array of arguments, the environment
 * list, and the input buffer.
 */
void free_params(param_t *params)
{
unsigned int x;  /* Loop variable */

if (params->buffer)  /* Check if buffer is not NULL */
free(params->buffer);  /* Free buffer memory */

if (params->nextCommand)  /* Check if nextCommand is not NULL */
free(params->nextCommand);  /* Free nextCommand memory */

free_list(params->env_head);  /* Free env_head list memory */
free_list(params->alias_head);  /* Free alias_head list memory */

for (x = 0; params->args[x]; x++)  /* Loop through args array */
free(params->args[x]);  /* Free each argument memory */

free(params->args);  /* Free args array memory */
free(params);  /* Free params structure memory */	}
}
