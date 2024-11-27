/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsirpa-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:21:28 by lsirpa-g          #+#    #+#             */
/*   Updated: 2024/07/18 18:21:30 by lsirpa-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef int	(*t_print_func)(va_list *args);

typedef struct s_dispatcher
{
	char			specifier;
	t_print_func	func;
}	t_dispatcher;

int				ft_printf(const char *format, ...);
t_dispatcher	*get_dispatcher(void);

// UTILS_1
int				write_char(char c);
int				write_str(const char *s);
int				write_unsigned(unsigned long num, int base, int isup);
int				write_signed(int num);
int				write_pointer(void *ptr);
//UTILS_2
int				print_unsigned(va_list *args);
int				print_hex_lower(va_list *args);
int				print_hex_upper(va_list *args);
int				print_percent(va_list *args);
int				print_char(va_list *args);
//UTILS_3
int				print_string(va_list *args);
int				print_pointer(va_list *args);
int				print_decimal(va_list *args);

#endif
