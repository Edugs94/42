int	ft_format_handler(char specifier, va_list args)
{
	int count;

	count = 0;
	if (specifier == 'c')
		// Le pedimos a va_arg que saque un 'int' (los char se promocionan a int)
		count = ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		// Le pedimos a va_arg que saque un 'char *'
		count = ft_print_str(va_arg(args, char *));
	else if (specifier == 'p')
		// Le pedimos a va_arg que saque un 'void *'
		count = ft_print_pointer(va_arg(args, void *));
	else if (specifier == 'd' || specifier == 'i')
		// Le pedimos a va_arg que saque un 'int'
		count = ft_print_number(va_arg(args, int));
	// ... aquí irían los demás casos: 'u', 'x', 'X' ...
	else if (specifier == '%')
	{
		write(1, "%", 1);
		count = 1;
	}
	return (count);
}
int	ft_printf(const char *format, ...)
{
	va_list	args;   // La "cinta transportadora"
	int		count;  // El contador total de caracteres impresos
	int		i;

	va_start(args, format); // 1. Inicializamos la lista de argumentos
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			// 2. Llamamos a nuestro ayudante (handler)
			// Le pasamos el especificador (ej: 'd') y la lista completa 'args'
			count += ft_format_handler(format[i], args);
		}
		else
		{
			// Si no es '%', simplemente imprimimos el carácter
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args); // 3. Limpiamos la lista de argumentos
	return (count);
}