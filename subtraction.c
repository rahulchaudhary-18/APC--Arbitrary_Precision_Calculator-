#include "apc.h"

static void subtract_abs(const char *a, const char *b, char *result)
{
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;
    int borrow = 0;

    char temp[3000];

    while (i >= 0)
    {
        int x = (a[i] - '0') - borrow;
        int y = (j >= 0) ? (b[j] - '0') : 0;

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

static void get_abs_value(const char *src, char *dest)
{
    if (src[0] == '+' || src[0] == '-')
        strcpy(dest, src + 1);
    else
        strcpy(dest, src);

    remove_leading_zeros(dest);
}

void subtract_numbers(const char *a, const char *b, char *result)
{
    char aa[1000];
    char bb[1000];
    char temp[3000];

    int neg_a = (a[0] == '-');
    int neg_b = (b[0] == '-');

    get_abs_value(a, aa);
    get_abs_value(b, bb);

    if (neg_a != neg_b)
    {
        add_numbers(aa, bb, temp);

        if (neg_a && strcmp(temp, "0") != 0)
        {
            result[0] = '-';
            strcpy(result + 1, temp);
        }
        else
        {
            strcpy(result, temp);
        }

        return;
    }

    int cmp = compare_abs(aa, bb);

    if (cmp == 0)
    {
        strcpy(result, "0");
        return;
    }

    if (cmp > 0)
    {
        subtract_abs(aa, bb, result);

        if (neg_a)
        {
            strcpy(temp, result);
            result[0] = '-';
            strcpy(result + 1, temp);
        }
    }
    else
    {
        subtract_abs(bb, aa, result);

        if (!neg_a)
        {
            strcpy(temp, result);
            result[0] = '-';
            strcpy(result + 1, temp);
        }
    }
}