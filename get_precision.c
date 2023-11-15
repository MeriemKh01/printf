#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return (precision);

    precision = 0;

    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = curr_i - 1;

    return (precision);
}

/**
 * print_with_precision - Print a string or character with precision.
 * @specifier: Conversion specifier ('c' or 's').
 * @arg: The argument to be printed.
 * @precision: Precision value.
 */
void print_with_precision(char specifier, va_list arg, int precision)
{
    if (precision == -1)
    {
        // No precision specified, print as usual
        if (specifier == 'c')
            putchar(va_arg(arg, int));
        else if (specifier == 's')
            printf("%s", va_arg(arg, char *));
    }
    else
    {
        // Apply precision
        if (specifier == 'c')
            putchar(va_arg(arg, int));
        else if (specifier == 's')
            printf("%.*s", precision, va_arg(arg, char *));
    }
}

// Example of usage:
int main()
{
    const char *format = "%.*s\n";
    int precision;

    precision = get_precision(format, &(int){0}, va_list{});  // Replace with your actual list of arguments
    print_with_precision('s', va_list{}, precision);  // Replace with your actual list of arguments

    return 0;
}
