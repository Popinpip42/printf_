#include "printf.h"

void	print_char(va_list *args, int *count)
{
	char	c;

	c = (char)va_arg(*args, int);
	write_char(c, count);
}

void	print_string(va_list *args, int *count)
{
	char	*s;

	s = va_arg(*args, char *);
	write_str(s, count);
}

void	print_pointer(va_list *args, int *count)
{
	void	*p;

	p = va_arg(*args, void *);
	write_pointer(p, count);
}

void	print_decimal(va_list *args, int *count)
{
	int	d;

	d = va_arg(*args, int);
	write_signed(d, count);
}

t_dispatcher	*get_dispatcher(size_t *size)
{
	t_dispatcher	*dispatcher;

	*size = 9;
	dispatcher = (t_dispatcher *)malloc(*size * sizeof(t_dispatcher));
	if (dispatcher == NULL)
	{
		*size = 0;
		return (NULL);
	}
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
