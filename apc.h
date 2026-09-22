#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

int validate_number(const char *str);
int validate_operator(char op);

void remove_leading_zeros(char *str);
int compare_abs(const char *a, const char *b);

void add_numbers(const char *a, const char *b, char *result);
void subtract_numbers(const char *a, const char *b, char *result);
void multiply_numbers(const char *a, const char *b, char *result);
void divide_numbers(const char *a, const char *b, char *result);

void read_number(const char *message, char *number, int size);
void read_operator(char *op);

void print_result(const char *result);

#endif