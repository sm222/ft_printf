/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:06:35 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/08 15:14:24 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str_free(char *s)
{
	int	size;

	size = 0;
	if (!s)
		return (0);
	size = ft_putstr_fd(s, STDERR_FILENO);
	if (s)
		free(s);
	return (size);
}
