/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirpa-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:22:08 by lsirpa-g          #+#    #+#             */
/*   Updated: 2024/07/18 18:22:09 by lsirpa-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(va_list *args)
{
	unsigned int	u;

	u = va_arg(*args, unsigned int);
	return (write_unsigned(u, 10, 0));
}

int	print_hex_lower(va_list *args)
{
	unsigned int	x;

	x = va_arg(*args, unsigned int);
	return (write_unsigned(x, 16, 0));
}

int	print_hex_upper(va_list *args)
{
	unsigned int	x;

	x = va_arg(*args, unsigned int);
	return (write_unsigned(x, 16, 1));
}

int	print_percent(va_list *args)
{
	(void)args;
	return (write_char('%'));
}
