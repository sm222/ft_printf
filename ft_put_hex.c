/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:51:22 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/10 09:31:11 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned int nb, char maj)
{
	int		size;
	char	*tmp;

	tmp = ft_ulltoa(nb, 16);
	size = ft_strlen(tmp);
	if (maj == 'X')
	{
		while (size + 1)
		{
			tmp[size] = ft_toupper(tmp[size]);
			size--;
		}
	}
	size = ft_putstr_fd(tmp, STDOUT_FILENO);
	free (tmp);
	return (size);
}
