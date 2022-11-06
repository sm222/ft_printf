/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:12:13 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/06 17:36:44 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	size_t	total;

	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				ft_putstr_fd(va_arg(arg, char *), STDOUT_FILENO);
			else if (str[i] == 'd' || str[i] == 'i')
				ft_putnbr_fd(va_arg(arg, int), STDOUT_FILENO);
			i++;
		}
		else
		{
			ft_putchar_fd(str[i], STDOUT_FILENO);
			i++;
		}
	}
	return (0);
}

int	main(void)
{
	char	*t;

	t = "\n";
	ft_printf("this is a %itest%sya", 42, t);
	return (0);
}
