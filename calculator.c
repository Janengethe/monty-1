#include "monty.h"

/**
 * _add - adds the top two elements in stack
 * @head: top node
 * @line_number: node number
 */
void _add(stack_t **head, unsigned int line_number)
{
  /*if less than 2 elements*/
  if (*head == NULL || (*head)->next == NULL)
    {
      printf("L%u: can't add, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  (*head)->next->n += (*head)->n;/*add the nodes data*/
  (*head) = (*head)->next;
  (*head)->prev = NULL;
}
