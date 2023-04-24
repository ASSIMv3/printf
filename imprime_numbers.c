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

/**
 * imprime_binary - a function that prints an unsigned integer
 *
 * @given_args: a list of a given arguments.
 * @flags: list of flags
 * Return: the size of the number.
 */
int imprime_binary(va_list given_args, __attribute__((unused)) int *flags)
{
	unsigned int num = va_arg(given_args, unsigned int);
	int binary[32];
	int printed_chars, i, j;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	i = 0;
	printed_chars = 0;
	while (num > 0)
	{
		binary[i] = num % 2;
		num /= 2;
		i++;
		printed_chars++;
	}

	for (j = i - 1; j >= 0; j--)
		_putchar(binary[j] + '0');

	return (printed_chars);
}
