#include <unistd.h>
#include <stdarg.h>
#include "printf.h"

int	ft_printf(const char *format, ...)
{
	t_dispatcher	*dispatcher;
	va_list			args;
	int				count;
	int				found;
	int				i;
	size_t			dispatcher_size;

	count = 0;
	dispatcher = get_dispatcher(&dispatcher_size);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			found = 0;
			i = 0;
			while (i < DISPATCHER_SIZE)
			{
				if (dispatcher[i].specifier == *format)
				{
					dispatcher[i].func(&args, &count);
					found = 1;
					break ;
				}
				i++;
			}
			if (!found)
			{
				write_char('%', &count);
				write_char(*format, &count);
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		++format;
	}
	va_end(args);
	free(dispatcher);
	return (count);
}

int	main(void)
{
	ft_printf("Character: %c\n", 'A');
	ft_printf("String: %s\n", "Hello, World!");
	ft_printf("Pointer: %p\n", main);
	ft_printf("Decimal: %d\n", 12345);
	ft_printf("Integer: %i\n", -12345);
	ft_printf("Unsigned: %u\n", 12345);
	ft_printf("Hex Lowercase: %x\n", 15);
	ft_printf("Hex Uppercase: %X\n", 15);
	ft_printf("Percent: %%\n");
}
