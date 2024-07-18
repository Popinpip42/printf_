#include "ft_printf.h"

int	print_unsigned(va_list *args, int *count)
{
	unsigned int	u;

	u = va_arg(*args, unsigned int);
	return (write_unsigned(u, 10, 0, count));
}

int	print_hex_lower(va_list *args, int *count)
{
	unsigned int	x;

	x = va_arg(*args, unsigned int);
	return (write_unsigned(x, 16, 0, count));
}

int	print_hex_upper(va_list *args, int *count)
{
	unsigned int	x;

	x = va_arg(*args, unsigned int);
	return (write_unsigned(x, 16, 1, count));
}

int	print_percent(va_list *args, int *count)
{
	(void)args;
	return (write_char('%', count));
}
