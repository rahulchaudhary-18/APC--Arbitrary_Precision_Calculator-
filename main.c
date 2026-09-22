/* ~~~~ Rahul Chaudhary ~~~~*/

#include "apc.h"

int main()
{
    char num1[1000];
    char num2[1000];
    char result[3000];
    char op;

    printf("Enter first number: ");
    scanf("%999s", num1);

    if (validate_number(num1) == FAILURE)
    {
        printf("Invalid first number\n");
        return FAILURE;
    }

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    if (validate_operator(op) == FAILURE)
    {
        printf("Invalid operator\n");
        return FAILURE;
    }

    printf("Enter second number: ");
    scanf("%999s", num2);

    if (validate_number(num2) == FAILURE)
    {
        printf("Invalid second number\n");
        return FAILURE;
    }

    if (op == '/' && strcmp(num2, "0") == 0)
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }

    result[0] = '\0';

    switch (op)
    {
        case '+':
            add_numbers(num1, num2, result);
            break;

        case '-':
            subtract_numbers(num1, num2, result);
            break;

        case '*':
            multiply_numbers(num1, num2, result);
            break;

        case '/':
            divide_numbers(num1, num2, result);
            break;
    }

    print_result(result);

    return SUCCESS;
}