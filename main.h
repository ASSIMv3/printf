#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char character);
void set_zeros(int *fl);
int get_fl(char c, int *flags);
int (*imprime_arg(char c))(va_list, int *);
int imprime_char(va_list given_args, int *flags);
int imprime_str(va_list given_args, int *flags);
int imprime_percent(va_list given_args, int *flags);
int imprime_i_d(va_list given_args, int *flags);
int imprime_binary(va_list given_args, int *flags);
int imprime_unsigned(va_list given_args, int *flags);
int imprime_octal(va_list given_args, int *flags);
int imprime_hex_lower(va_list given_args, int *flags);
int imprime_hex_upper(va_list given_args, int *flags);

/**
  * struct printer - function to be printed
  * @c: data type.
  * @func: a function to print the arguments.
  */
typedef struct printer
{
	char c;
	int (*func)(va_list given_args, int *flags);
} print_f;

#endif /* MAIN_H */
