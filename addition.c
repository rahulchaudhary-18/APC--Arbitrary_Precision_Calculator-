#include "apc.h"

static void add_abs(const char *a, const char *b, char *result)
{
    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int k = 0;
    int carry = 0;

    char temp[3000];

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';

        if (j >= 0)
            sum += b[j--] - '0';

        temp[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }

    for (i = 0; i < k; i++)
        result[i] = temp[k - i - 1];

    result[k] = '\0';
}

static void get_abs(const char *src, char *dest)
{
    if (src[0] == '+' || src[0] == '-')
        strcpy(dest, src + 1);
    else
        strcpy(dest, src);

    remove_leading_zeros(dest);
}

void add_numbers(const char *a, const char *b, char *result)
{
    char aa[1000];
    char bb[1000];

    int neg_a = (a[0] == '-');
    int neg_b = (b[0] == '-');

    get_abs(a, aa);
    get_abs(b, bb);

    if (neg_a == neg_b)
    {
        add_abs(aa, bb, result);

        if (neg_a && strcmp(result, "0") != 0)
        {
            char temp[3000];

            strcpy(temp, result);
            result[0] = '-';
            strcpy(result + 1, temp);
        }
    }
    else
    {
        int cmp = compare_abs(aa, bb);

        if (cmp == 0)
        {
            strcpy(result, "0");
        }
        else if (cmp > 0)
        {
            subtract_numbers(aa, bb, result);

            if (neg_a)
            {
                char temp[3000];

                strcpy(temp, result);
                result[0] = '-';
                strcpy(result + 1, temp);
            }
        }
        else
        {
            subtract_numbers(bb, aa, result);

            if (neg_b)
            {
                char temp[3000];

                strcpy(temp, result);
                result[0] = '-';
                strcpy(result + 1, temp);
            }
        }
    }
}