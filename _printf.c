#include "main.h"

/**
 * _printf - an alternative function of the standard ( printf ).
 *
 * @format: the character string.
 *
 * Return: the number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list given_args;
	int printed_charac, flags[3];
	int (*func)(va_list given_args, int *flags);

	if (!format || (format[0] == '%' && format[1] == ' '
		&& format[2] == '\0'))
		return (-1);

	va_start(given_args, format);
	printed_charac = 0;
	set_zeros(flags);
	while (*format)
	{
		if (*format != '%')
			_putchar(*format), printed_charac++;
		else if (*format == '%')
		{
			format++;
			while (*format && get_fl(*format, flags))
				format++;
			if (!(*format))
				return (-1);
			func = imprime_arg(*format);
			if (func)
				printed_charac += func(given_args, flags);
			else
				printed_charac += 2;
		}
		format++, set_zeros(flags);
	}
	_putchar(-1);
	va_end(given_args);
	return (printed_charac);
}

/**
  * get_fl - a function that looks for flags (+, space, #)
  * @c: character
  * @flags: array of flags
  * Return: 0 (None)
  */
int get_fl(char c, int *flags)
{
	if (c == '+')
	{
		flags[0] = 1;
		return (1);
	}
	else if (c == ' ')
	{
		flags[1] = 1;
		return (1);
	}
	else if (c == '#')
	{
		flags[2] = 1;
		return (1);
	}
	return (0);
}

/**
  * set_zeros - set the flags to zeros
  * @fl: list of flags
  * Return: void
  */
void set_zeros(int *flags)
{
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
}
