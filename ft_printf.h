#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef int	(*t_print_func)(va_list *args, int *count);

typedef struct s_dispatcher
{
	char			specifier;
	t_print_func	func;
}	t_dispatcher;

int		ft_printf(const char *format, ...);
int		write_char(char c, int *count);
int		write_str(const char *s, int *count);
int		write_unsigned(unsigned long num, int base, int isupper, int *c);
int		write_signed(int num, int *count);
int		write_pointer(void *ptr, int *count);

int		print_unsigned(va_list *args, int *count);
int		print_hex_lower(va_list *args, int *count);
int		print_hex_upper(va_list *args, int *count);
int		print_percent(va_list *args, int *count);
int		print_char(va_list *args, int *count);
int		print_string(va_list *args, int *count);
int		print_pointer(va_list *args, int *count);
int		print_decimal(va_list *args, int *count);
t_dispatcher	*get_dispatcher(void);

#endif
