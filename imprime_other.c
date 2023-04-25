#include "main.h"

/**
 * imprime_pointer - a function that prints an address
 *
 * @given_args: a list of a given arguments.
 * @flags: list of flags
 * Return: the size of the number.
 */
int imprime_pointer(va_list given_args, __attribute__((unused)) int *flags)
{
	void *ptr;
	unsigned long int addr;
	unsigned long int mask = 0xf;
	unsigned long int hex_digit;
	int i, size = sizeof(void *) * 2;
	char ch;
	int leading_zeros = 1;

	ptr = va_arg(given_args, void *);
	if (!ptr)
		return (_printf("(nil)"));

	addr = (unsigned long int)ptr;

	_putchar('0');
	_putchar('x');

	if (!addr)
	{
		_putchar('0');
		return (3);
	}
	for (i = size - 1; i >= 0; i--)
	{
		hex_digit = (addr >> (i * 4)) & mask;
		if (hex_digit == 0 && leading_zeros)
			continue;
		leading_zeros = 0;
		if (hex_digit < 10)
			ch = '0' + hex_digit;
		else
			ch = 'W' + hex_digit;

		_putchar(ch);
	}
	return (size + 2);
}
