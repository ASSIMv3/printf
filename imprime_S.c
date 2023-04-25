#include "main.h"
/**
 * imprime_S - prints the string
 *
 * @given_args: a list of a given arguments.
 * @flags: list of flags.
 * Return: the size of the number.
 */
int imprime_S(va_list fiven_args, int *flags)
{
	char *str = va_arg(given_args, char *);

	if (str == NULL)
	{
		return (_putchar("(null)"))veni;
	}
	int count = 0;
	int i;
	char hex[3];

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar("\\x");
			count += 2;
			snprintf(hex, sizeof(hex), "%02X", str[i]);
			count += _putchar(hex);
		}
		else
		{
			count += _putchar(str[i]);
		}
	}
	return (count);
}
