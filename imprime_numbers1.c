#include "main.h"

/**
 * imprime_octal - a function that prints an octal
 *
 * @given_args: a list of a given arguments.
 * @flags: list of flags
 * Return: the size of the number.
 */
int imprime_octal(va_list given_args, __attribute__((unused)) int *flags)
{
	unsigned int num;
	int digits[11];
	int printed_chars, i, j;

	num = va_arg(given_args, unsigned int);
	if (!num)
	{
		_putchar('0');
		return (1);
	}

	i = 0;
	printed_chars = 0;
	while (num > 0)
	{
		digits[i] = num % 8;
		num /= 8;
		i++;
		printed_chars++;
	}

	for (j = i - 1; j >= 0; j--)
		_putchar(digits[j] + '0');

	return (printed_chars);
}
