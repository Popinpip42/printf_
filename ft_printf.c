#include <stdio.h>
#include "ft_printf.h"

int	procss(const char **f, va_list *args, int *c, t_dispatcher *dispatcher)
{
	int	i;

	++(*f);
	i = 0;
	while (i < 9)
	{
		if (dispatcher[i].specifier == **f)
			return (dispatcher[i].func(args, c));
		i++;
	}
	if (write_char('%', c) < 0)
		return (-1);
	if (write_char(**f, c) < 0)
		return (-1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	t_dispatcher	*dispatcher;
	va_list			args;
	int				count;

	count = 0;
	dispatcher = get_dispatcher();
	if (!dispatcher)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (procss(&format, &args, &count, dispatcher) < 0)
				return (free(dispatcher), -1);
		}
		else
		{
			if (write(1, format, 1) < 0)
				return (free(dispatcher), -1);
			count++;
		}
		++format;
	}
	return (va_end(args), free(dispatcher), count);
}
/*
int	main(void)
{
	int entero = 985632;
	char caracter = 'B';
	char *cadena = NULL;
	char *cadena_larga = "Este es un string largo";
	char *cadena_vacia = "";
	void *puntero = &entero;
	void *puntero_null = NULL;
	int num_negativo = -42;
	int int_max = 2147483647;
	int int_min = -2147483648;
	unsigned int uint_max = 4294967295;

	int original_ret, mi_ret;
	//PRUEBA DE CARACTERES
	printf("%s\n", "Prueba de impresión de caracteres");
	printf("Original printf:\n");
	original_ret = printf("Caracter: %c\n", caracter);
	printf("Return: %d\n", original_ret);
	original_ret = printf("%c\n", caracter);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Caracter: %c\n", caracter);
	printf("Return: %d\n", mi_ret);
	mi_ret = ft_printf("%c\n", caracter);
	printf("Return: %d\n\n", mi_ret);

	//PRUEBA CON CADENAS
	printf("%s\n", "Prueba de impresión de cadenas");
	printf("Original printf:\n");
	original_ret = printf("Cadena: %s\n", cadena);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Cadena: %s\n", cadena);
	printf("Return: %d\n\n", mi_ret);

	//PRUEBA CON CADENAS LARGAS
	printf("%s\n", "Prueba de impresión de cadenas largas");
	printf("Original printf:\n");
	original_ret = printf("Cadena larga: %s\n", cadena_larga);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Cadena larga: %s\n", cadena_larga);
	printf("Return: %d\n\n", mi_ret);

	//PRUEBA DE CADENAS VACIAS
	printf("%s\n", "Prueba de impresión de cadenas vacías");
	printf("Original printf:\n");
	original_ret = printf("Cadena vacía: %s\n", cadena_vacia);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Cadena vacía: %s\n", cadena_vacia);
	printf("Return: %d\n\n", mi_ret);

	//PRUEBA DE PUNTEROS
	printf("%s\n", "Prueba de impresión de punteros");
	printf("Original printf:\n");
	original_ret = printf("Puntero: %p\n", puntero);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Puntero: %p\n", puntero);
	printf("Return: %d\n\n", mi_ret);
	//PRUEBA DE PUNTERO NULL
	printf("%s\n", "Prueba de impresión de puntero NULL");
	printf("Original printf:\n");
	original_ret = printf("Puntero NULL: %p\n", puntero_null);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Puntero NULL: %p\n", puntero_null);
	printf("Return: %d\n\n", mi_ret);

	//PRUEBA NUMEROS DECIMALES
	printf("%s\n", "Prueba de impresión de números decimales (base 10)");
	printf("Original printf:\n");
	original_ret = printf("Entero: %d\n", entero);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Entero: %d\n", entero);
	printf("Return: %d\n\n", mi_ret);

	//PRUEBA ENTEROS
	printf("%s\n", "Prueba de impresión de enteros (base 10)");
	printf("Original printf:\n");
	original_ret = printf("Entero: %i\n", entero);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Entero: %i\n", entero);
	printf("Return: %d\n\n", mi_ret);
	//PRUEBA DECIMALES LARGOS
	printf("%s\n", "Prueba de impresión de números decimales negativos");
	printf("Original printf:\n");
	original_ret = printf("Número negativo: %d\n", num_negativo);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Número negativo: %d\n", num_negativo);
	printf("Return: %d\n\n", mi_ret);

	//PRUEBA NUMEROS SIN SIGNO
	printf("%s\n", "Prueba de impresión de números sin signo (base 10)");
	printf("Original printf:\n");
	original_ret = printf("Unsigned Entero: %u\n", uint_max);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Unsigned Entero: %u\n", uint_max);
	printf("Return: %d\n\n", mi_ret);
	//PRUEBA INT MAX, INT MIN UINT MAX
	printf("%s\n", "Prueba de impresión de enteros máximos y mínimos");
	printf("Original printf:\n");
	original_ret = printf("Entero máximo: %d\n", int_max);
	printf("Return: %d\n", original_ret);
	original_ret = printf("Entero mínimo: %d\n", int_min);
	printf("Return: %d\n", original_ret);
	original_ret = printf("Unsigned Entero máximo: %u\n", uint_max);
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Entero máximo: %d\n", int_max);
	printf("Return: %d\n", mi_ret);
	mi_ret = ft_printf("Entero mínimo: %d\n", int_min);
	printf("Return: %d\n", mi_ret);
	mi_ret = ft_printf("Unsigned Entero máximo: %u\n", uint_max);
	printf("Return: %d\n\n", mi_ret);

	//PRUEBA PORCENTAJE
	printf("%s\n", "Prueba de impresión de porcentaje");
	printf("Original printf:\n");
	original_ret = printf("Porcentaje:%%%%%%\n");
	printf("Return: %d\n", original_ret);

	printf("Mi ft_printf:\n");
	mi_ret = ft_printf("Porcentaje:%%%%%\n");
	printf("Return: %d\n\n", mi_ret);
}
*/
