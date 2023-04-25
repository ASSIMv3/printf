#include "main.h"

/**
 * imprime_pointer - a function that prints an address
 *
 * @given_args: a list of a given arguments.
 * @flags: list of flags
 * Return: the size of the number.
 */
int imprime_pointer(va_list given_args, int *flags)
{
	void *ptr;
	unsigned long int addr;
	unsigned int hex_digit[100];
	int i, size, flag;
	char ch;

	ptr = va_arg(given_args, void *);
	if (!ptr)
		return (_printf("(nil)"));

	addr = (unsigned long int)ptr;
	size = 0;
	flag = 0;
	if (flags[0])
	{
		_putchar('+');
		flag++;
	}
	else if (flags[1])
	{
		_putchar(' ');
		flag++;
	}
	_putchar('0');
	_putchar('x');

	if (!addr)
	{
		_putchar('0');
		return (3);
	}

	while (addr > 0)
	{
		hex_digit[size] = addr % 16;
		addr /= 16;
		size++;
	}
	for (i = size - 1; i >= 0; i--)
	{
		if (hex_digit[i] < 10)
			ch = '0' + hex_digit[i];
		else
			ch = 'W' + hex_digit[i];

		_putchar(ch);
	}
	return (size + 2 + flag);
}

/**
 * imprime_reverse - a function that reverses a string
 *
 * @given_args: a list of a given arguments.
 * @flags: list of flags
 * Return: the size of the number.
 */
int imprime_reverse(va_list given_args, __attribute__((unused)) int *flags)
{
	char *str;
	int i, j;

	str = va_arg(given_args, char *);
	if (!str)
		str = "(null)";

	i = 0;
	while (str[i])
		i++;

	for (j = i - 1; j >= 0; j--)
		_putchar(str[j]);

	return (i);
}
