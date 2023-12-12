#include "main.h"

/**
 * njoro_print - does so the argument based on its type.
 * @fmt: Formatted string in which to print the arguments.
 * @list: arguments
 * @ind: indeces
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */

int njoro_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', printisha_char}, {'s', printisha_string}, {'%', printisha_percent},
		{'i', printisha_int}, {'d', printisha_int}, {'b', printisha_binary},
		{'u', printisha_unsigned}, {'o', printisha_octal}, {'x', printisha_hexadecimal},
		{'X', printisha_hexa_upper}, {'p', printisha_pointer}, {'S', printisha_non_printable},
		{'r', printisha_reverse}, {'R', printisha_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
