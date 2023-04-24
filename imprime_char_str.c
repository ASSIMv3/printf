#include "main.h"

/**
 * imprime_char - a function tha prints a character
 *
 * @given_args: a list of arguments to print
 * @flags: a list of flags
 *
 * Return: 1
 */
int imprime_char(va_list given_args, __attribute__((unused)) int *flags)
{
	int c = va_arg(given_args, int);

	_putchar(c);
	return (1);
}

/**
 * imprime_str - a function that prints a string
 *
 * @given_args: a list of given arguments
 * @flags: a list of flags
 *
 * Return: the length of the string
 */
int imprime_str(va_list given_args, __attribute__((unused)) int *flags)
{
	char *str;
	int i;

	str = va_arg(given_args, char *);
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * imprime_percent - a funtion that prints the percent symbol
 *
 * @given_args: a list of given arguments
 * @flags: a list of flags
 *
 * Return: 1
 */
int imprime_percent(__attribute__((unused)) va_list given_args, int *flags)
{
	int f;

	f = flags[0];
	if (f == 20)
		_printf("dummy");
	_putchar('%');
	return (1);
}
