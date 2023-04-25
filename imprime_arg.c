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
		{'%', imprime_percent},
		{'i', imprime_i_d},
		{'d', imprime_i_d},
		{'b', imprime_binary},
		{'u', imprime_unsigned},
		{'o', imprime_octal},
		{'x', imprime_hex_lower},
		{'X', imprime_hex_upper},
		{'S', imprime_String},
		{'p', imprime_pointer},
		{'r', imprime_reverse}
	};
	int i = 0;

	while (i < 13)
	{
		if (c == data_types[i].c)
			return (data_types[i].func);
		i++;
	}
	_putchar('%');
	_putchar(c);
	return (0);
}
