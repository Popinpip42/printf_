/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirpa-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:22:00 by lsirpa-g          #+#    #+#             */
/*   Updated: 2024/07/18 18:22:01 by lsirpa-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	return (write_char(c));
}

int	print_string(va_list *args)
{
	char	*s;

	s = va_arg(*args, char *);
	return (write_str(s));
}

int	print_pointer(va_list *args)
{
	void	*p;

	p = va_arg(*args, void *);
	return (write_pointer(p));
}

int	print_decimal(va_list *args)
{
	int	d;

	d = va_arg(*args, int);
	return (write_signed(d));
}

t_dispatcher	*get_dispatcher(void)
{
	t_dispatcher	*dispatcher;

	dispatcher = (t_dispatcher *)malloc(9 * sizeof(t_dispatcher));
	if (!dispatcher)
		return (NULL);
	dispatcher[0] = (t_dispatcher){'c', print_char};
	dispatcher[1] = (t_dispatcher){'s', print_string};
	dispatcher[2] = (t_dispatcher){'p', print_pointer};
	dispatcher[3] = (t_dispatcher){'d', print_decimal};
	dispatcher[4] = (t_dispatcher){'i', print_decimal};
	dispatcher[5] = (t_dispatcher){'u', print_unsigned};
	dispatcher[6] = (t_dispatcher){'x', print_hex_lower};
	dispatcher[7] = (t_dispatcher){'X', print_hex_upper};
	dispatcher[8] = (t_dispatcher){'%', print_percent};
	return (dispatcher);
}
