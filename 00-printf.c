#include "main.h"
/**
 * _printf - prints string or character
 * @format: string of varible non-keyword argument to print
 *
 * Return: return -1 if NULL else 1
 */

int _printf(const char *format, ...)
{
	int i, j, k, n;

	char *str = "%s", *ctr = "%c", *s, c;

	va_list args;

	va_start(args, format);
	i = 0;
	j = strlen(format);
	while (i < j && format != NULL)
	{
		if (*(format + i) != *str)
		{
			write(1, (format + i), 1); }
		else if (*(format + i) == *str && *(format + i + 1) == *(str + 1))
		{
			s = va_arg(args, char *);
			k = strlen(s);
			for (n = 0; n < k; n++)
			{
				if (s != NULL)
				{
					c = (char) *(s + n);
					write(1, &c, 1); }
			} ++i; }
		else if (*(format + i) == *ctr && *(format + i + 1) == *(ctr + 1))
		{
			c = (char) va_arg(args, int);
			write(1, &c, 1);
			++i; }
		else if ((*(format + i) == *ctr && *(format + i + 1) == *ctr))
		{
			write(1, ctr, 1);
			++i; }
		else if (*(format + i) == '%' && (*(format + i + 1) != *(str + 1) || *(format + i + 1) != *(ctr + 1)))
			write(1, ctr, 1);
		++i; }
	va_end(args);
	return (1);
}
