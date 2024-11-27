/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirpa-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:21:42 by lsirpa-g          #+#    #+#             */
/*   Updated: 2024/07/18 20:01:56 by lsirpa-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_char(char c)
{
	return (write(1, &c, 1));
}

int	write_str(const char *s)
{
	int	count;
	int	old_count;

	count = 0;
	if (!s)
	{
		count += write_str("(null)");
		return (count);
	}
	while (*s)
	{
		old_count = count;
		count += write_char(*s++);
		if (old_count > count)
			return (-1);
	}
	return (count);
}

int	write_unsigned(unsigned long num, int base, int isup)
{
	char		buffer[32];
	int			i;
	const char	*digits;

	if (isup)
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
	return (write_str(&buffer[i + 1]));
}

int	write_signed(int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count += write_char('-');
		if (count == -1)
			return (-1);
		num = -num;
	}
	count += write_unsigned((unsigned int)num, 10, 0);
	if (count == -1)
		return (-1);
	return (count);
}

int	write_pointer(void *ptr)
{
	unsigned long	num;
	int				count;

	count = 0;
	if (!ptr)
		return (write_str("(nil)"));
	num = (unsigned long)ptr;
	count += write_str("0x");
	if (count == -1)
		return (-1);
	count += write_unsigned(num, 16, 0);
	if (count == -1)
		return (-1);
	return (count);
}
//FOR UBUNTU FRANCINETTE
		//return (write_str("(nil)"));
//FOR MACOS FRANCINETTE
		//return (write_str("0x0"));
