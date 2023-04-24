#include "main.h"
#include <stdarg.h>

/**
 * imprime_arg - print arg
 * @c: data type
 * Return: 0
 */
int (*imprime_arg(char c))(va_list, int *)
{
	print_f data_types[] = {
		{'c', imprime_char},
		{'s', imprime_str},
		{'%', imprime_percent}
	};
	int i = 0;

	while (i < 3)
	{
		if (c == data_types[i].c)
			return (data_types[i].func);
		i++;
	}
	_putchar('%');
	_putchar(c);
	return (0);
}
