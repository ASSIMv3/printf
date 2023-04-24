#include "main.h"

/**
 * imprime_i_d - a function that prints an integer and a double.
 *
 * @given_args: a list of a given arguments.
 * @flags: list of flags
 * Return: the size of the number.
 */
int imprime_i_d(va_list given_args, int *flags)
{
	int val, i, length, remain;
	int digit[100];

	i = 99;
	val = va_arg(given_args, int);
	length = 0;
	if (val < 0)
	{
		_putchar('-');
		length++;
	}
	else if (flags[0])
	{
		_putchar('+');
		length++;
	}
	else if (flags[1])
	{
		_putchar(' ');
		length++;
	}
	while (val > 9 || val < -9)
	{
		remain = val % 10;
		digit[i--] = (remain > 0) ? (remain) : (remain * (-1));
		val /= 10;
	}
	digit[i] = (val > 0) ? (val) : (val * (-1));
	while (i < 100)
	{
		_putchar(digit[i++] + '0');
		length++;
	}
	return (length);
}
