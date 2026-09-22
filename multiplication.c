#include "apc.h"

static void get_abs_number(const char *src, char *dest)
{
    if (src[0] == '+' || src[0] == '-')
        strcpy(dest, src + 1);
    else
        strcpy(dest, src);

    remove_leading_zeros(dest);
}

void multiply_numbers(const char *a, const char *b, char *result)
{
    char aa[1000];
    char bb[1000];

    int result_array[3000] = {0};

    int len_a;
    int len_b;
    int i, j;

    int negative = 0;

    get_abs_number(a, aa);
    get_abs_number(b, bb);

    if (a[0] == '-')
        negative = !negative;

    if (b[0] == '-')
        negative = !negative;

    if (strcmp(aa, "0") == 0 || strcmp(bb, "0") == 0)
    {
        strcpy(result, "0");
        return;
    }

    len_a = strlen(aa);
    len_b = strlen(bb);

    for (i = len_a - 1; i >= 0; i--)
    {
        for (j = len_b - 1; j >= 0; j--)
        {
            int x = aa[i] - '0';
            int y = bb[j] - '0';

            result_array[i + j + 1] += x * y;
        }
    }

    for (i = len_a + len_b - 1; i > 0; i--)
    {
        result_array[i - 1] += result_array[i] / 10;
        result_array[i] %= 10;
    }

    i = 0;

    while (i < len_a + len_b - 1 && result_array[i] == 0)
        i++;

    int k = 0;

    if (negative)
        result[k++] = '-';

    while (i < len_a + len_b)
    {
        result[k++] = result_array[i++] + '0';
    }

    result[k] = '\0';
}