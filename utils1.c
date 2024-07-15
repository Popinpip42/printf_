#include "printf.h"

void	write_char(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	write_str(const char *s, int *count)
{
	while (*s)
		write_char(*s++, count);
}

void	write_unsigned(unsigned int num, int base, int uppercase, int *count)
{
	char		buffer[32];
	int			i;
	const char	*digits;

	if (uppercase)
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
	write_str(&buffer[i + 1], count);
}

void	write_signed(int num, int *count)
{
	if (num < 0)
	{
		write_char('-', count);
		num = -num;
	}
	write_unsigned((unsigned int)num, 10, 0, count);
}

void	write_pointer(void *ptr, int *count)
{
	uintptr_t	num;

	num = (uintptr_t)ptr;
	write_str("0x", count);
	write_unsigned(num, 16, 0, count);
}
