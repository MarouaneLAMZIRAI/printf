#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int count = 0;

    va_list args;
    va_start(args, format);

    while (*format)
    {
   
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break; 
            else if (*format == 'c')
            {
                int c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                if (str)
                {
                    while (*str)
                    {
                        putchar(*str);
                        str++;
                        count++;
                    }
                }
                else
                {
                   
                    printf("(null)");
                    count += 6;
                }
	}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{

				putchar('%');
				putchar(*format);
				count += 2;
			}
		}
		else
		{

			putchar(*format);
			count++;
		}

		format++; 
	}

	va_end(args); 
	return count;
}
