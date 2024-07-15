#ifndef PRINTF_H
# define PRINTF_H 

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

typedef void	(*t_print_func)(va_list *args, int *count);

typedef struct s_dispatcher
{
	char			specifier;
	t_print_func	func;
}	t_dispatcher;

int		ft_printf(const char *format, ...);
void	write_char(char c, int *count);
void	write_str(const char *s, int *count);
void	write_unsigned(unsigned int num, int base, int uppercase, int *count);
void	write_signed(int num, int *count);
void	write_pointer(void *ptr, int *count);

void	print_unsigned(va_list *args, int *count);
void	print_hex_lower(va_list *args, int *count);
void	print_hex_upper(va_list *args, int *count);
void	print_percent(va_list *args, int *count);
void	print_char(va_list *args, int *count);
void	print_string(va_list *args, int *count);
void	print_pointer(va_list *args, int *count);
void	print_decimal(va_list *args, int *count);
t_dispatcher	*get_dispatcher(size_t *size);

#endif
