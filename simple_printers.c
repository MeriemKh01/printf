#include "main.h"

/**
 * print_from_to - this function prints range of char address
 * @start: this starting address
 * @stop: this stopped address
 * @except: this except address
 *
 * Description: this function print range of char address
 *
 * Return: the returned value are printed value of number bytes
 */

int print_from_to(char *start, char *stop, char *except)
{
	int addation = 0;

	while (start <= stop)
	{
		if (start != except)
			addation += _putchar(*start);
		start++;
	}
	return (addation);
}

/**
 * print_rev - this function prints string in reverse
 * @ap: parameters string
 * @params: the parameters of struct
 *
 * Description: prints string in reverse
 *
 * Return: the returned value printed of numbers bytes
 */

int print_rev(va_list ap, params_t *params)
{
	int len, add = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			add += _putchar(*str);
	}
	return (add);
}

/**
 * print_rot13 - this function prints string in rot13
 * @ap: parameters string
 * @params: the parameters of struct
 *
 * Description: prints string in rot13
 *
 * Return: the returned value printed of numbers bytes
 */

int print_rot13(va_list ap, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
