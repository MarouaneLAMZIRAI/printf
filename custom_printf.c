#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * custom_printf - Our custom printf function.
 * @format: A string containing the format to print.
 * @...: Additional arguments to print.
 *
 * Return: The number of characters printed.
 */
int custom_printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;
    char *str_arg;

    va_start(args, format);

    while (format && format[printed_chars])
    {
        if (format[printed_chars] == '%' && format[printed_chars + 1])
        {
            printed_chars++;
            switch (format[printed_chars])
            {
            case 'c':
                putchar(va_arg(args, int));
                break;
            case 's':
                str_arg = va_arg(args, char *);
                if (!str_arg)
                    str_arg = "(null)";
                while (*str_arg)
                {
                    putchar(*str_arg);
                    str_arg++;
                }
                break;
            case '%':
                putchar('%');
                break;
            case 'd':
            case 'i':
                printf("%d", va_arg(args, int));
                break;
            case 'u':
                printf("%u", va_arg(args, unsigned int));
                break;
            case 'o':
                printf("%o", va_arg(args, unsigned int));
                break;
            case 'x':
                printf("%x", va_arg(args, unsigned int));
                break;
            case 'X':
                printf("%X", va_arg(args, unsigned int));
                break;
            default:
                putchar('%');
                putchar(format[printed_chars]);
                break;
            }
        }
        else
        {
            putchar(format[printed_chars]);
        }
        printed_chars++;
    }

    va_end(args);

    return (printed_chars - 1);
}
