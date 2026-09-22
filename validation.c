#include "apc.h"

/* Validate the number */
int validate_number(const char *str)
{
    int i = 0;

    if (str == NULL)
    {
        return FAILURE;
    }
    else if (str[0] == '\0')
    {
        return FAILURE;
    }
    else
    {
        /* Skip sign */
        if (str[0] == '+' || str[0] == '-')
        {
            i++;
        }
        else
        {
            i = 0;
        }

        /* Only sign is not a valid number */
        if (str[i] == '\0')
        {
            return FAILURE;
        }
        else
        {
            while (str[i] != '\0')
            {
                if (isdigit((unsigned char)str[i]))
                {
                    i++;
                }
                else
                {
                    return FAILURE;
                }
            }
        }
    }

    return SUCCESS;
}


/* Validate the operator */
int validate_operator(char op)
{
    if (op == '+')
    {
        return SUCCESS;
    }
    else if (op == '-')
    {
        return SUCCESS;
    }
    else if (op == '*')
    {
        return SUCCESS;
    }
    else if (op == '/')
    {
        return SUCCESS;
    }
    else
    {
        return FAILURE;
    }
}


/* Remove leading zeros */
void remove_leading_zeros(char *str)
{
    int i = 0;
    int j = 0;
    int negative = 0;

    if (str == NULL)
    {
        return;
    }
    else
    {
        /* Check negative sign */
        if (str[0] == '-')
        {
            negative = 1;
            i = 1;
        }
        else
        {
            i = 0;
        }

        /* Skip leading zeros */
        while (str[i] == '0')
        {
            i++;
        }

        /* If number contains only zeros */
        if (str[i] == '\0')
        {
            strcpy(str, "0");
        }
        else
        {
            /* Keep negative sign */
            if (negative == 1)
            {
                str[j] = '-';
                j++;
            }
            else
            {
                j = 0;
            }

            /* Copy remaining digits */
            while (str[i] != '\0')
            {
                str[j] = str[i];
                j++;
                i++;
            }

            str[j] = '\0';
        }
    }
}


/* Compare absolute values of two numbers */
int compare_abs(const char *a, const char *b)
{
    int i;
    int j;
    int len_a;
    int len_b;

    len_a = strlen(a);
    len_b = strlen(b);

    /* Ignore negative sign */
    if (a[0] == '-')
    {
        len_a--;
    }
    else
    {
        len_a = len_a;
    }

    if (b[0] == '-')
    {
        len_b--;
    }
    else
    {
        len_b = len_b;
    }

    /* Compare lengths */
    if (len_a > len_b)
    {
        return 1;
    }
    else if (len_a < len_b)
    {
        return -1;
    }
    else
    {
        /* Lengths are equal */
        if (a[0] == '-')
        {
            i = 1;
        }
        else
        {
            i = 0;
        }

        if (b[0] == '-')
        {
            j = 1;
        }
        else
        {
            j = 0;
        }

        /* Compare digit by digit */
        while (a[i] != '\0' && b[j] != '\0')
        {
            if (a[i] > b[j])
            {
                return 1;
            }
            else if (a[i] < b[j])
            {
                return -1;
            }
            else
            {
                i++;
                j++;
            }
        }
    }

    return 0;
}