
#ifndef PRINTF_H
# define PRINTF_H 

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef void	(*t_print_func)(va_list *args, int *count);

typedef struct s_dispatcher
{
	char			specifier;
	print_func_t	func;
}	t_dispatcher_entry;

int		ft_printf(const char *format, ...);
void	write_char(char c, int *count);
void	write_str(const char *s, int *count);
void	write_unsigned(unsigned int num, int base, int uppercase, int *count);
void	write_signed(int num, int *count);
void	write_pointer(void *ptr, int *count);

#endif
