#include "ft_printf.h"

int	write_char(char c, int *count)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	(*count)++;
	return (0);
}

int	write_str(const char *s, int *count)
{
	if (!s)
	{
		if (write_str("(null)", count) < 0)
			return (-1);
		return (0);
	}
	while (*s)
	{
		if (write_char(*s++, count) < 0)
			return (-1);
	}
	return (0);
}

int	write_unsigned(unsigned long num, int base, int isupper, int *c)
{
	char		buffer[32];
	int			i;
	const char	*digits;

	if (isupper)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	buffer[31] = '\0';
	i = 30;
	if (num == 0)
		buffer[i--] = '0';
	else
	{
		while (num > 0)
		{
			buffer[i--] = digits[num % base];
			num /= base;
		}
	}
	if (write_str(&buffer[i + 1], c) < 0)
		return (-1);
	return (0);
}

int	write_signed(int num, int *count)
{
	if (num < 0)
	{
		if (write_char('-', count) < 0)
			return (-1);
		num = -num;
	}
	if (write_unsigned((unsigned int)num, 10, 0, count) < 0)
		return (-1);
	return (0);
}

int	write_pointer(void *ptr, int *count)
{
	unsigned long	num;

	if (!ptr)
	{	
		if (write_str("(nil)", count) < 0)
			return (-1);
		return (0);
	}
	/*if (!ptr && (write_str("(nil)", count) < 0))
		return (-1);*/
	num = (unsigned long)ptr;
	if (write_str("0x", count) < 0)
		return (-1);
	if (write_unsigned(num, 16, 0, count) < 0)
		return (-1);
	return (0);
}
