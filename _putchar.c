#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 *
 * @c: character to be printed
 *
 * Return: 1
 */
int _putchar(char character)
{
	static char buffer[1024];
	static int buff_size;

	if (character == -1 || buff_size >= 1024)
	{
		write(1, &buffer, buff_size);
		buff_size = 0;
	}
	if (character != -1)
		buffer[buff_size++] = character;
	return (1);
}
