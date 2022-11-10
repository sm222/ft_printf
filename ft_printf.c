/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:12:13 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/10 13:01:34 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_select(va_list list, char c)
{
	char	*s;

	if (c == 's')
	{
		s = va_arg(list, char *);
		if (!s)
			return (ft_putstr_fd("(null)", STDOUT_FILENO));
		return (ft_putstr_fd(s, STDOUT_FILENO));
	}
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_fd(va_arg(list, int), STDOUT_FILENO));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg(list, int), STDOUT_FILENO));
	else if (c == 'p')
		return (ft_put_p(va_arg(list, uintptr_t)));
	else if (c == '%')
		return (ft_putchar_fd('%', STDOUT_FILENO));
	else if (c == 'x' || c == 'X')
		return (ft_put_hex(va_arg(list, unsigned int), c));
	else if (c == 'u')
		return (ft_put_u(va_arg(list, unsigned int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		total;

	total = 0;
	i = 0;
	if (!str)
		return (0);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] != '%')
			total += ft_putchar_fd(str[i], STDOUT_FILENO);
		else
		{
			i++;
			if (str[i] == 0)
				break ;
			total += ft_print_select(arg, str[i]);
		}
		i++;
	}
	va_end(arg);
	return (total);
}

/*
int	main(int c, char **v)
{
	(void)c;
	(void)v;
	printf("\033[1;0m%d\n", ft_printf("\033[1;32m"));
	ft_printf("\033[1;0m%d\n", printf("\033[1;32m"));
}
*/
