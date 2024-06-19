/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:01:12 by mbaypara          #+#    #+#             */
/*   Updated: 2024/04/25 16:17:41 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_check(char str)
{
	if (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p')
		return (1);
	return (0);
}

int	ft_format(va_list args, char c)
{
	char	a;

	if (c == 'c')
	{
		a = (char)va_arg(args, int);
		return (write(1, &a, 1));
	}
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'd' || c == 'i')
		return (ft_int(va_arg(args, int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (c == 's')
		return (ft_string(va_arg(args, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg(args, unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg(args, unsigned long), 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		counter;
	int		tmp;

	counter = -1;
	len = 0;
	va_start(args, str);
	while (str[++counter] != '\0')
	{
		if (str[counter] == '%' && ft_check(str[counter + 1]))
		{
			tmp = ft_format(args, str[++counter]);
			if (tmp == -1)
				return (-1);
			len += tmp - 1;
		}
		else if (str[counter] == '%')
			continue ;
		else if (write(1, &str[counter], 1) == -1)
			return (-1);
		len++;
	}
	va_end(args);
	return (len);
}
