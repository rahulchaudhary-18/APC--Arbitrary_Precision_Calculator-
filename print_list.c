#include "apc.h"

void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}