#include "apc.h"

void read_number(const char *message, char *number, int size)
{
    while (1)
    {
        printf("%s", message);

        if (fgets(number, size, stdin) == NULL)
            return;

        number[strcspn(number, "\n")] = '\0';

        if (validate_number(number) == SUCCESS)
            break;

        printf("Invalid number. Please try again.\n");
    }
}

void read_operator(char *op)
{
    while (1)
    {
        printf("Enter operator (+, -, *, /): ");

        scanf(" %c", op);

        if (validate_operator(*op) == SUCCESS)
            break;

        printf("Invalid operator. Please try again.\n");
    }
}