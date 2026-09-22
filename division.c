#include "apc.h"

static void get_abs_div_number(const char *src, char *dest)
{
    if (src[0] == '+' || src[0] == '-')
        strcpy(dest, src + 1);
    else
        strcpy(dest, src);

    remove_leading_zeros(dest);
}

static int compare_positive(const char *a, const char *b)
{
    return compare_abs(a, b);
}

static void subtract_positive(const char *a, const char *b, char *result)
{
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;
    int borrow = 0;

    char temp[3000];

    while (i >= 0)
    {
        int x = a[i] - '0' - borrow;
        int y = (j >= 0) ? b[j] - '0' : 0;

        if (x < y)
        {
            x += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        temp[k++] = (x - y) + '0';

        i--;
        j--;
    }

    while (k > 1 && temp[k - 1] == '0')
        k--;

    for (i = 0; i < k; i++)
        result[i] = temp[k - i - 1];

    result[k] = '\0';
}

void divide_numbers(const char *a, const char *b, char *result)
{
    char dividend[1000];
    char divisor[1000];
    char remainder[3000] = "0";
    char quotient[1000];

    int negative = 0;
    int qpos = 0;
    int i;

    get_abs_div_number(a, dividend);
    get_abs_div_number(b, divisor);

    if (a[0] == '-')
        negative = !negative;

    if (b[0] == '-')
        negative = !negative;

    if (strcmp(divisor, "0") == 0)
    {
        strcpy(result, "ERROR");
        return;
    }

    if (compare_positive(dividend, divisor) < 0)
    {
        strcpy(result, "0");
        return;
    }

    for (i = 0; dividend[i] != '\0'; i++)
    {
        int digit;

        if (strcmp(remainder, "0") == 0)
        {
            remainder[0] = dividend[i];
            remainder[1] = '\0';
        }
        else
        {
            int len = strlen(remainder);

            remainder[len] = dividend[i];
            remainder[len + 1] = '\0';
        }

        remove_leading_zeros(remainder);

        digit = 0;

        while (compare_positive(remainder, divisor) >= 0)
        {
            char temp[3000];

            subtract_positive(remainder, divisor, temp);
            strcpy(remainder, temp);
            digit++;
        }

        quotient[qpos++] = digit + '0';
    }

    quotient[qpos] = '\0';

    remove_leading_zeros(quotient);

    if (negative && strcmp(quotient, "0") != 0)
    {
        result[0] = '-';
        strcpy(result + 1, quotient);
    }
    else
    {
        strcpy(result, quotient);
    }
}